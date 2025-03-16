#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

bool is_prime(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
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
<<<<<<< HEAD
            ans *= (cnt + 1);
            ans %= MOD;
=======
            ans = (ans * (cnt + 1)) % MOD;
>>>>>>> 98c87cb78a (data updated)
        }
    }

    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
