#include <stdio.h>
#include <math.h>

int main() {
    long long N, A, B;
    scanf("%lld %lld %lld", &N, &A, &B);
    long long k = 0;
    if (1 <= N && N <= pow(10, 18) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow(10, 18)) {
        if (A + B <= N) {
            k = N / (A + B);
            if (N - k * (A + B) > A) {
                printf("%lld\n", A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)));
            } else {
                printf("%lld\n", A * k + (N - k * (A + B)));
            }
        } else if (A + B > N && A <= N) {
            printf("%lld\n", A);
        } else {
            printf("%lld\n", N);
        }
    }
