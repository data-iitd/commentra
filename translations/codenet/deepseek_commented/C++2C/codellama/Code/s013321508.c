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
        return 0;
    }

    max_L /= 2;
    int *itr = lower_bound(L, L + N, max_L);
    memmove(itr + 1, itr, (N - (itr - L)) * sizeof(int));
    *itr = max_L;
    L[N - 1] = 0;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans);

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

