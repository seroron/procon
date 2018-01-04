#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> sushi(n+1, 0);
    for(int i=1; i<n+1; i++) {
        scanf("%d", &sushi[i]);
    }

    for(int i=3; i<n+1; i++) {
        sushi[i] = max(sushi[i-2]+sushi[i], sushi[i-3]+sushi[i]);
    }

    printf("%d\n", max(sushi[n], sushi[n-1]));
}
