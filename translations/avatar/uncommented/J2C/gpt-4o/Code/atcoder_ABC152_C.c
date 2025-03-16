#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve() {
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    // Sort the array to simulate the behavior of a priority queue
    qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        if (arr[i] <= arr[0]) { // arr[0] is the smallest element after sorting
            sum++;
        }
    }

    free(arr);
    return sum;
}

int main() {
    printf("%d\n", solve());
    return 0;
}

// <END-OF-CODE>
