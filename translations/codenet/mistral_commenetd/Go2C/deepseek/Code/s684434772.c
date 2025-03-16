#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

long long combi(int n, int k) {
    long long min = (long long)(k - 1) * k / 2;
    long long max = (long long)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

long long pow64(int base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long long total = 0;

    for (int i = k; i <= n + 1; i++) {
        long long comb = combi(n, i);
        total += comb;
        total = total % (pow64(10, 9) + 7);
    }

    printf("%lld\n", total);

    return 0;
}

