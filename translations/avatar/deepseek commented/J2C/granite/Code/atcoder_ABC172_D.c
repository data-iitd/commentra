

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long ans = 0;

    for (int i = 1; i <= n; i++) {
        long term = (long) n / (long) i;
        long sum = term * (term + 1) / 2;
        ans += (long) i * sum;
    }

    printf("%ld\n", ans);
    return 0;
}
