
#include <stdio.h>

int main() {
    int n;
    long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++) {
        long term = n / i;
        long sum = term * (term + 1) / 2;
        ans += i * sum;
    }
    printf("%ld\n", ans);
    return 0;
}

