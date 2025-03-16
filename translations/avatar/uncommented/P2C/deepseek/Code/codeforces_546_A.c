#include <stdio.h>

int main() {
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);
    if (1 <= k && k <= 1000 && 1 <= n && n <= 1000 && 1 <= w && w <= 1000) {
        int total = 0;
        for (int i = 1; i <= w; i++) {
            total += i * k;
        }
        if (total > n) {
            printf("%d\n", total - n);
        } else {
            printf("0\n");
        }
    }
    return 0;
}
