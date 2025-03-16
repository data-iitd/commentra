#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long ans = 0, mx = 0, sum = 0, mn = 100000000, cnt = 1;
    long long h;
    scanf("%lld", &h);

    while (h != 1) {
        if (h % 2 != 0) h--;
        h /= 2;
        cnt *= 2;
        ans += cnt;
    }

    printf("%lld\n", ans + 1);
}
