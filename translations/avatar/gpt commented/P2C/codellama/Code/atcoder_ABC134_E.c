#include <stdio.h>

int binary_search(int key, int *arr, int low, int high) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    int N, A, i, j, idx;
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int *ans = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        ans[i] = 0;
    }
    for (i = 0; i < N; i++) {
        A = arr[i];
        idx = binary_search(A, arr, 0, i - 1);
        if (idx == i) {
            ans[i] = 1;
        } else {
            ans[i] = ans[idx] + 1;
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
