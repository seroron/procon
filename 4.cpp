#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    char dp[10200] = {1};
    for(int i=0; i<n; i++) {
        int w;
        scanf("%d", &w);
        sum += w;
        for(int j=10000; j>=0; j--) {
            if(dp[j]) {
                dp[j+w] = 1;
            }
        }
    }
    
    if(sum%2==1 || dp[sum/2]==0) {
        printf("impossible\n");
    } else {
        printf("possible\n");
    }
}
