#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    long long N, K;
    scanf("%lld %lld", &N, &K);
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), compare);

    long long ll = -1000000000000000000LL - 1;
    long long rr = 1000000000000000000LL + 1;

    while (ll + 1 < rr) {
        long long x = (ll + rr) / 2;
        long long tot = 0;

        for (long long i = 0; i < N; i++) {
            if (A[i] < 0) {
                long long l = -1, r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        r = c;
                    } else {
                        l = c;
                    }
                }
                tot += N - r;
            } else {
                long long l = -1, r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r;
            }
            if (A[i] * A[i] < x) {
                tot -= 1;
            }
        }
        tot /= 2;

        if (tot < K) {
            ll = x;
        } else {
            rr = x;
        }
    }

    printf("%lld\n", ll);
    free(A);
    return 0;
}

// <END-OF-CODE>
