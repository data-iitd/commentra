#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    int mod = 1000000007;
    long long val = power(x, n / 2);
    val = val * val % mod;
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    return val;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int c[n];
    char buffer[1000];
    fgets(buffer, 1000, stdin); // Consume the newline character after the first number
    fgets(buffer, 1000, stdin);
    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        c[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    if (n == 1) {
        printf("%lld\n", (long long)c[0] * 2 % 1000000007);
        return 0;
    }

    qsort(c, n, sizeof(int), compare);
    long long b = power(2, n);
    long long a = power(2, n - 2);
    long long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % 1000000007;
        val *= c[n + 1 - i];
        val %= 1000000007;
        ans += val;
        ans %= 1000000007;
    }
    ans *= b;
    ans %= 1000000007;
    printf("%lld\n", ans);

    return 0;
}
