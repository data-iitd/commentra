#include <stdio.h>

long long rs() {
    long long num;
    scanf("%lld", &num);
    return num;
}

int main() {
    long long N = rs();
    long long ans = 0;

    for (long long i = 1; i <= N; i++) {
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
