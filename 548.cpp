#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int h[13] = {};
    for(int i=0; i<13; i++) {
        char s;
        scanf("%c", &s);        
        if('a'<=s && s<='m') h[s-'a']++;
    }

    bool impossible=true;
    for(int i=0; i<13; i++) {
        bool ok = true;
        for(int j=0; j<13; j++) {
            if(j!=i && h[j]==0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            printf("%c\n", i+'a');
            impossible=false;
        }
    }

    if(impossible) {
        printf("Impossible");
    }
}
