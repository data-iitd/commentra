#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD 1000000007
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int N, i, _lcm = 1;
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        _lcm = lcm(_lcm, A[i]);
    }
    long long ans = _lcm * (pow(A[0], MOD - 2) % MOD);
    for (i = 1; i < N; i++) {
        ans = (ans * pow(A[i], MOD - 2)) % MOD;
    }
    printf("%d", (int)(ans % MOD));
    return 0;
}
