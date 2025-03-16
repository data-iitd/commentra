

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *arr;
    int size;
} Task;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int solve(Task tsk) {
    int n = tsk.size;
    int *arr = tsk.arr;
    int *sorted = (int*)malloc(n * sizeof(int));
    memcpy(sorted, arr, n * sizeof(int));
    qsort(sorted, n, sizeof(int), cmpfunc);

    long total = (long)n * (n + 1) / 2;
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        int cur = 0;
        long cnt = 0;
        int *bit = (int*)malloc((2 * n + 2) * sizeof(int));
        memset(bit, 0, (2 * n + 2) * sizeof(int));

        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target? 1 : -1;
            for (int x = cur + n + 1; x < 2 * n + 2; x += x & -x)
                bit[x]++;
            for (int x = cur + n; x > 0; x -= x & -x)
                cnt += bit[x];
        }

        if (cnt >= total / 2 + 1)
            r = mid;
        else
            l = mid + 1;
    }

    return sorted[l];
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Task tsk;
    tsk.arr = arr;
    tsk.size = n;

    int result = solve(tsk);
    printf("%d\n", result);

    free(arr);
    return 0;
}

Translate the above C code to Python and end with comment "