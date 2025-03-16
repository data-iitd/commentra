#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search(int key, int *arr, int len) {
    int bad = -1, good = len;
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (arr[mid] < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    return good;
}

int main() {
    int N;
    scanf("%d", &N);
    int *ans = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, i);
        if (idx == i) {
            ans[i] = A;
        } else {
            ans[idx] = A;
        }
    }
    printf("%d\n", i);
    free(ans);
    return 0;
}

