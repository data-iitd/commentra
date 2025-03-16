#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long power(long long x, long long n, int mod) {
    if (n == 0) {
        return 1;
    }
    long long val = power(x, n / 2, mod);
    val = val * val % mod;
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    int c[n];
    char buffer[100];
    fgets(buffer, 100, stdin); // Consume the newline character after the integer
    fgets(buffer, 100, stdin);
    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL && i < n) {
        c[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int mod = 1000000007;
    if (n == 1) {
        printf("%d\n", c[0] * 2 % mod);
        return 0;
    }

    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))compare);

    long long b = power(2, n, mod);
    long long a = power(2, n - 2, mod);

    long long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        ans += val;
        ans %= mod;
    }

    ans *= b;
    ans %= mod;

    printf("%lld\n", ans);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
