#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *L = (int*)malloc(100000 * sizeof(int));
    int l;

    for (int i = 0; i < N; i++) {
        scanf("%d", &l);
        L[i] = l;
    }

    qsort(L, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        int max_L = L[N - 1];
        if (max_L == 0) {
            break;
        }

        max_L /= 2;

        int *itr = (int*)bsearch(&max_L, L, N, sizeof(int), compare);
        int index = itr - L;

        memmove(L + index + 1, L + index, (N - index) * sizeof(int));
        L[index] = max_L;

        L[N - 1] = 0;
        qsort(L, N, sizeof(int), compare);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans);

    free(L);
    return 0;
}
