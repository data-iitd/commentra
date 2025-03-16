#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    int *L = (int *)malloc(sizeof(int) * 100000);
    int l;
    for (int i = 0; i < N; i++) {
        scanf("%d", &l);
        L[i] = l;
    }

    qsort(L, N, sizeof(int), compare);

    int max_L = L[N - 1];
    if (max_L == 0) {
        printf("0\n");
        return 0;
    }

    max_L /= 2;
    int *itr = lower_bound(L, L + N, max_L);
    int *new_L = (int *)malloc(sizeof(int) * (N + 1));
    memcpy(new_L, L, sizeof(int) * (itr - L));
    new_L[itr - L] = max_L;
    memcpy(new_L + (itr - L) + 1, itr, sizeof(int) * (N - (itr - L)));
    free(L);
    L = new_L;

    for (int i = 0; i < M; i++) {
        max_L = L[N - 1];
        if (max_L == 0) {
            break;
        }

        max_L /= 2;
        itr = lower_bound(L, L + N, max_L);
        int *new_L = (int *)malloc(sizeof(int) * (N + 1));
        memcpy(new_L, L, sizeof(int) * (itr - L));
        new_L[itr - L] = max_L;
        memcpy(new_L + (itr - L) + 1, itr, sizeof(int) * (N - (itr - L)));
        free(L);
        L = new_L;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans);

    free(L);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int lower_bound(int *arr, int *arr_end, int key) {
    int *left = arr;
    int *right = arr_end - 1;
    while (left <= right) {
        int *mid = left + (right - left) / 2;
        if (*mid < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - arr;
}

