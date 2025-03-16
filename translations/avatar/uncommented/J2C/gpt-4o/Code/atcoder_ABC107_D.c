#include <stdio.h>
#include <stdlib.h>

long long countPairs(int *arr, int n, int target) {
    long long cnt = 0;
    int cur = 0;
    long long *bit = (long long *)calloc(2 * n + 2, sizeof(long long));

    for (int x = n + 1; x < 2 * n + 2; x += x & -x) {
        bit[x]++;
    }

    for (int i = 0; i < n; i++) {
        cur += arr[i] <= target ? 1 : -1;
        for (int x = cur + n + 1; x < 2 * n + 2; x += x & -x) {
            bit[x]++;
        }
        for (int x = cur + n; x > 0; x -= x & -x) {
            cnt += bit[x];
        }
    }

    free(bit);
    return cnt;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve(int *arr, int n) {
    int *sorted = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    qsort(sorted, n, sizeof(int), compare);

    long long total = (long long)n * (n + 1) / 2;
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        long long cnt = countPairs(arr, n, target);

        if (cnt >= total / 2 + 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int result = sorted[l];
    free(sorted);
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int result = solve(arr, N);
    printf("%d\n", result);

    free(arr);
    return 0;
}

// <END-OF-CODE>
