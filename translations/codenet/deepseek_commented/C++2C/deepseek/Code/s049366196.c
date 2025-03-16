#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(long long x) {
    for (long long i = 2; i*i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    long long ans = 1;
    for (int i = 2; i <= N; i++) {
        if (is_prime((long long)i)) {
            int NN = N;
            int cnt = 0;
            while (NN) {
                cnt += NN / i;
                NN /= i;
            }
            ans *= cnt + 1;
            ans %= 1000000007;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
