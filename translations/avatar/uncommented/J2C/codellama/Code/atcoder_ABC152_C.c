
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int *q = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        q[i] = arr[i];
        if (arr[i] <= q[0]) {
            sum++;
        }
    }
    free(q);
    return sum;
}

