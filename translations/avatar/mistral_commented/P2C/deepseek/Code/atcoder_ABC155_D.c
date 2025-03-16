#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int), (int (*)(const void *, const void *))compare);

    long long ll = -1000000000000000000LL - 1;
    long long rr = 1000000000000000000LL + 1;

    while (ll + 1 < rr) {
        long long x = (ll + rr) / 2;

        long long tot = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                int l = 0;
                int r = N;

                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if ((long long)A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }

                tot += N - r;

            } else {
                int l = 0;
                int r = N;
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if ((long long)A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r;
            }

            if ((long long)A[i] * A[i] < x) {
                tot -= 1;
            }
        }

        if (tot >= K) {
            ll = x;
        } else {
            rr = x;
        }
    }

    printf("%lld\n", ll);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
