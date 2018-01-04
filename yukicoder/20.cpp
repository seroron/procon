#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;

int DIR_X[] = {-1,  1,  0,  0};
int DIR_Y[] = { 0,  0,  1, -1};    

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void dijkstra(vvi& field, vvi& cost, int sx, int sy) {
    cost.assign(field.size(), vi(field[0].size(), INT_MAX));
    
    auto queue = priority_queue<tuple<int,int,int>,
                                vector<tuple<int, int, int>>,
                                greater<tuple<int,int,int>>>();
    queue.emplace(sx, sy, 0);
    cost[sx][sy] = 0;
    
    while(!queue.empty()) {
        int ix, iy, ic;
        tie(ix, iy, ic) = queue.top();
        queue.pop();

        if(ic <= cost[ix][iy]) {        
            for(int i=0; i<4; i++) {
                int nx = ix + DIR_X[i];
                if(nx<0 || field.size()<=nx) continue;
                int ny = iy + DIR_Y[i];
                if(ny<0 || field[0].size()<=ny) continue;

                int c = ic + field[nx][ny];
                if(c<cost[nx][ny]) {
                    cost[nx][ny] = c;
                    queue.emplace(nx,ny,c);
                }
            }
        }
        
    }
}

int main() {

    int len, life, ox, oy;
    scanf("%d%d%d%d", &len, &life, &ox, &oy);    
    ox--;
    oy--;

    vvi field = vvi(len, vi(len));   
    for(int y=0; y<len; y++) {
        for(int x=0; x<len; x++) {
            scanf("%d", &field[x][y]);
        }
    }

    vvi cost;    
    dijkstra(field, cost, 0, 0);
    if(cost[len-1][len-1] < life) {
        printf("YES");
        return 0;
    }

    if(ox>0 || oy>0) {
        int oasis_life = life - cost[ox][oy];
        if(oasis_life <= 0) {
            printf("NO");
            return 0;
        }
        
        dijkstra(field, cost, ox, oy);
        if(oasis_life*2 - cost[len-1][len-1] > 0) {
            printf("YES");
            return 0;
        }
    }
    
    printf("NO");
    
    return 0;
}
