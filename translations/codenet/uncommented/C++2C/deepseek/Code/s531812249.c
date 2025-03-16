#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;
    // gu gu
    ans += n * (n - 1) / 2;

    // kiki
    ans += m * (m - 1) / 2;

    printf("%d\n", ans);

    return 0;
}
