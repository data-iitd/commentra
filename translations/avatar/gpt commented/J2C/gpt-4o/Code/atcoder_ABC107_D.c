#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *bit;
    int size;
} BIT;

void BIT_init(BIT *bit, int size) {
    bit->size = size;
    bit->bit = (long *)calloc(size + 1, sizeof(long));
}

void BIT_update(BIT *bit, int index, long value) {
    for (; index <= bit->size; index += index & -index) {
        bit->bit[index] += value;
    }
}

long BIT_query(BIT *bit, int index) {
    long sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += bit->bit[index];
    }
    return sum;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve(int *arr, int n) {
    int *sorted = (int *)malloc(n * sizeof(int));
    long total = (long)n * (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    qsort(sorted, n, sizeof(int), compare);

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        int cur = 0;
        long cnt = 0;

        BIT bit;
        BIT_init(&bit, 2 * n + 1);
        
        for (int x = n + 1; x <= 2 * n; x++) {
            BIT_update(&bit, x, 1);
        }

        for (int i = 0; i < n; i++) {
            cur += (arr[i] <= target) ? 1 : -1;
            BIT_update(&bit, cur + n + 1, 1);
            cnt += BIT_query(&bit, cur + n);
        }

        if (cnt >= total / 2 + 1) {
            r = mid; // Move left if count is sufficient
        } else {
            l = mid + 1; // Move right if count is insufficient
        }
    }

    free(sorted);
    free(bit.bit);
    return sorted[l];
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
