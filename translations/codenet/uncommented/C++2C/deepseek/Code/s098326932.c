#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

long long f(long long N) {
    long long a[20] = {0};
    int d = 0;
    while (N > 0) {
        a[d] = N % 10;
        N /= 10;
        d++;
    }
    double m = DBL_MAX;
    long long res = N;
    for (int i = 0; i <= d; i++) {
        long long bunsi = 0;
        long long bunbo = 9 * i;
        for (int j = d-1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9;
            else bunsi += a[j];
            
            if (j >= i) bunbo += a[j];
            
        }
        double frac = (double) bunsi / (double) bunbo;
        if (frac < m) {
            m = frac;
            res = bunsi;
        }
    }
    return res;
}

int main() {
    long long K;
    scanf("%lld", &K);
    long long N = f(1);
    for (long long i = 0; i < K; i++) {
        printf("%lld\n", N);
        N = f(N+1);
    }
}
