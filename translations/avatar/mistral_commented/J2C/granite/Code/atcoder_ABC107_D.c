

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;
    int idx;
} Node;

int cmpfunc (const void * a, const void * b) {
   return ((Node*)a)->val - ((Node*)b)->val;
}

int main() {
    int N;
    scanf("%d", &N);

    Node *arr = (Node*)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    qsort(arr, N, sizeof(Node), cmpfunc);

    int l = 0, r = N - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = arr[mid].val;

        long total = (long) N * (N + 1) / 2;
        long cnt = 0;

        int *bit = (int*)malloc(sizeof(int) * (2 * N + 2));
        memset(bit, 0, sizeof(int) * (2 * N + 2));

        for (int i = 0; i < N; i++) {
            int cur = arr[i].idx <= target? 1 : -1;
            for (int x = cur + N + 1; x < 2 * N + 2; x += x & -x) {
                bit[x]++;
            }
            for (int x = cur + N; x > 0; x -= x & -x) {
                cnt += bit[x];
            }
        }

        if (cnt >= total / 2 + 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%d\n", arr[l].val);

    free(arr);
    free(bit);

    return 0;
}

