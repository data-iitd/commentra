
#include <stdio.h>
#include <math.h>

int main() {
    int R, G, B, N, ans = 0, tmp;
    scanf("%d %d %d %d", &R, &G, &B, &N);
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            tmp = N - R * x - G * y;
            if (tmp >= 0 && tmp % B == 0) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
