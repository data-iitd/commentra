#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int _lcm = 1;

    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }

    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        sum += pow(A[i], MOD - 2, MOD);
    }

    ans = _lcm * sum % MOD;

    printf("%lld\n", ans % MOD);

    return 0;
}
