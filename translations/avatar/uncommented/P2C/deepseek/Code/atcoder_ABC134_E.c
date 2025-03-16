#include <stdio.h>
#include <stdlib.h>

int binary_search(int key, int** ans, int len) {
    int bad = -1, good = len;
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid][len - 1] < key) {
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
    int* ans[N];
    int ans_size = 0;

    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, ans_size);
        if (idx == ans_size) {
            ans[ans_size] = (int*)malloc(1 * sizeof(int));
            ans[ans_size][0] = A;
            ans_size++;
        } else {
            ans[idx] = (int*)realloc(ans[idx], (ans[idx][0] + 1) * sizeof(int));
            ans[idx][ans[idx][0]] = A;
            ans[idx][0]++;
        }
    }

    printf("%d\n", ans_size);

    return 0;
}
