#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

int n, d;
int t[101], k[101];
vector<vector<int>> dp;

int solve(int nd, int s) {
    if(nd == n) return 0;
    if (dp[nd][s] > 0) return dp[nd][s];
    
    if(s==0) {
        dp[nd][s] = max(solve(nd+1, 0) + t[nd],   solve(nd+1, 1) + k[nd]-d);
    } else {
        dp[nd][s] = max(solve(nd+1, 0) + t[nd]-d, solve(nd+1, 1) + k[nd]);        
    }

    return dp[nd][s];
}

int main() {
    scanf("%d%d", &n, &d);    
    getchar();

    for(int i=0; i<n; i++) {
        scanf("%d%d", &t[i], &k[i]);    
    }

    dp = vector<vector<int>>(n, vector<int>(2, -1));    
    int r1 = solve(0,0);
    
    dp = vector<vector<int>>(n, vector<int>(2, -1));
    int r2 = solve(0,1)-d;
        
    printf("%d\n", max(r1,r2));
    
    return 0;
}
