
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N], F[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &F[i]);
    }

    std::sort(A, A + N);
    std::sort(F, F + N, std::greater<int>());
    int scores[N];
    for (int i = 0; i < N; i++) {
        scores[i] = A[i] * F[i];
    }
    std::sort(scores, scores + N, std::greater<int>());

    int ok = scores[0], ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (A[i] * F[i] > mid) {
                k -= A[i] - mid / F[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    printf("%d\n", ok);

    return 0;
}
