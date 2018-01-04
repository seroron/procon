#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int prev_prime(int *np, int s) {
    while(s>1) {
        if(np[s]==0) return s;
        s--;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);


    int np[10000] = {1, 1};
    for(int i=4; i<=10000; i+=2) {
        np[i]=1;
    }
    for(int i=3; i<=10000; i+=2) {
        for(int j=i*2; j<=10000; j+=i) {
            np[j]=1;
        }
    }
    
    
    int dp[10001] = {0, 0, 0, 0};

    for(int i=4; i<=n; i++) {
        int p = i;
        while((p = prev_prime(np, p))>0){
            if(i-p>1 && dp[i-p]==0) {
                dp[i] = 1;
                break;
            }
            p--;
        }
    }

    printf(dp[n]==1 ? "Win" : "Lose");
}
