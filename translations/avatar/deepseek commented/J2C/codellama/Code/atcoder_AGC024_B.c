#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
    }

    // Create a HashMap to map each value in P to its index
    int *map = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    // Create a list to store indices of elements that are out of order
    int *nglist = (int *)malloc(N * sizeof(int));
    int nglist_size = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[nglist_size++] = i; // Add the index to nglist if the current element is greater than the next element
        }
    }

    // If nglist is empty, the array P is already sorted
    if (nglist_size == 0) {
        printf("0\n"); // Print 0 and return as the array is sorted
        return 0;
    }

    // Calculate the minimum number of swaps required to sort the array P
    int ans = nglist[0] + 1 + N - nglist[nglist_size - 1] - 1;
    for (int i = 0; i < nglist_size - 1; ++i) {
        ans = nglist[i] + 1 + N - nglist[i + 1] - 1;
    }

    // Print the minimum number of swaps required
    printf("%d\n", ans);

    // Free the memory allocated for the arrays
    free(P);
    free(map);
    free(nglist);

    return 0;
}

