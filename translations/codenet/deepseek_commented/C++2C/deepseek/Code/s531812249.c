#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979
#define rep(i, n) for (int i = 0; i < n; i++)

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    ans += n * (n - 1) / 2;
    ans += m * (m - 1) / 2;
    printf("%d\n", ans);
}
