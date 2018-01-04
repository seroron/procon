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

int h, w;

bool check(const vector<char>& field, int mx, int my) {
    bool red = false;

    vector<char> f = field;
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            if(f[x+y*w] == '#') {
                f[x+y*w] = 'R';
                red = true;
                
                int bx = x+mx;
                int by = y+my;
                if(!(0<=bx && bx<w && 0<=by && by<h)) return false;
                if(f[bx+by*w] == '#') {
                    f[bx+by*w] = 'B';
                } else {
                    return false;
                }
            }
        }
    }

    return red;
}

int main() {
    scanf("%d%d", &h, &w);
    getchar();

    auto field = vector<char>(w*h);
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            scanf("%c", &field[x + y*w]);
        }
        getchar();
    }
    
    for(int mx=-w+1; mx<w; mx++) {
        for(int my=-h+1; my<h; my++) {
            if(mx==0 && my==0) continue;
            if(check(field, mx, my)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");        
    
    return 0;
}
