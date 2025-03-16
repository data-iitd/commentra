#include <stdio.h>
#include <math.h>

int main() {
    long long N, A, B;
    long long k = 0;

    scanf("%lld %lld %lld", &N, &A, &B);

    if (isValidInput(N, A, B)) {
        if (A + B <= N) {
            k = calculateK(N, A, B);

            if (remainingPartGreaterThanA(N, k, A)) {
                printResult(N, k, A);
            } else {
                printResult(N, k, A);
            }
        } else if (A + B > N && A <= N) {
            printA();
        } else {
            printN();
        }
    }

    return 0;
}

int isValidInput(long long n, long long a, long long b) {
    return (1 <= n && n <= pow(10, 18) && 0 <= a && 0 <= b && 0 < a + b && a + b <= pow(10, 18));
}

long long calculateK(long long n, long long a, long long b) {
    return n / (a + b);
}

int remainingPartGreaterThanA(long long n, long long k, long long a) {
    return (n - k * (a + b)) > a;
}

void printResult(long long n, long long k, long long a) {
    long long result = 0;
    if (remainingPartGreaterThanA(n, k, a)) {
        result = a * k + (n - k * (a + b)) - (n - (k * (a + b) + a));
    } else {
        result = a * k + (n - k * (a + b));
    }
    printf("%lld\n", result);
}

void printA() {
    printf("%lld\n", A);
}

void printN() {
    printf("%lld\n", N);
}
