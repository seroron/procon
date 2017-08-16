#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <queue>

using namespace std;

int count_bit(uint32_t n) {
    int c = 0;
    while(n) {
        if(n&0x01) c++;
        n >>= 1;
    }
    return c;
}

int main() {
    int first_n;
    scanf("%d", &first_n);
    
    vector<int> costs(first_n+1, numeric_limits<int>::max());
    costs[1] = 1;
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        
        int bc = count_bit(n);

        if(n + bc == first_n) {
            costs[n+bc] = costs[n] + 1;
            break;
        }

        if(n + bc < first_n && costs[n] + 1 < costs[n+bc]) {
            costs[n+bc] = costs[n] + 1;
            q.push(n+bc);
        }
        
        if(n - bc >= 1 && costs[n] + 1 < costs[n-bc]) {
            costs[n-bc] = costs[n] + 1;
            q.push(n-bc);
        }
    }
    
    printf("%d\n", costs[first_n]==numeric_limits<int>::max() ? -1 : costs[first_n]);
}
