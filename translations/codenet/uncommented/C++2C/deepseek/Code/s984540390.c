#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long h, ans = 0, cnt = 1, mx = 1e8, mn = 1e8;
    scanf("%lld", &h);
    while (h != 1) {
        if (h % 2 != 0) h--;
        h /= 2;
        cnt *= 2;
        ans += cnt;
    }
    printf("%lld\n", ans + 1);
    return 0;
}
