#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        A[i] = input * N + i;
    }

    // Sorting the array A
    qsort(A, N, sizeof(int), (int (*)(const void *, const void *))compare);

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        if (d % 2 != i % 2) {
            cnt += 1;
        }
    }

    printf("%d\n", cnt / 2);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
