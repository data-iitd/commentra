
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, m, sa, a, b;
    scanf("%d %d", &n, &m);
    sa = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        b -= a;
        if(b % 2 && b <= (n - sa) << 1) {
            sa++;
        }
    }
    printf("%d\n", sa);
    return 0;
}

