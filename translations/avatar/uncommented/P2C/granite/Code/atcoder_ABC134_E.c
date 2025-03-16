
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
} Array;

int binary_search(int key, Array arr) {
    int bad = -1, good = arr.size;
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (arr.arr[mid] < key) {
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
    Array *ans = (Array *)malloc(sizeof(Array) * N);
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans[0]);
        if (idx == ans[0].size) {
            ans[i].arr = (int *)malloc(sizeof(int));
            ans[i].size = 1;
            ans[i].arr[0] = A;
        } else {
            ans[idx].arr = (int *)realloc(ans[idx].arr, sizeof(int) * (ans[idx].size + 1));
            ans[idx].arr[ans[idx].size] = A;
            ans[idx].size++;
        }
    }
    printf("%d\n", N);
    return 0;
}
// END-OF-CODE