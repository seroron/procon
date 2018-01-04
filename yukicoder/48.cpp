#include <cstdio>
#include <math.h>
#include <complex>

using namespace std;
int main() {
    int tx, ty, l;
    scanf("%d%d%d", &tx, &ty, &l);
	
    int m = ceil(1.0*abs(tx)/l) + ceil(1.0*abs(ty)/l);
    int r = 0;
	
    if(ty >= 0) {
        if(tx != 0) r++;
    } else {
        r += 2;
    }
	
    printf("%d\n",  m+r);
}
