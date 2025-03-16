#include <stdio.h>

int main() {
    int n;
    long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++) {
        ans += (long)i * ((long)n / (long)i) * (((long)n / (long)i) + 1) / 2;
    }
    printf("%ld\n", ans);
    return 0;
}

