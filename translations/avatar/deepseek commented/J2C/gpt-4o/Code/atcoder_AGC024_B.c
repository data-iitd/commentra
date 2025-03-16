#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements in the array P
    int *P = (int *)malloc(N * sizeof(int)); // Initialize the array P with N elements
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]); // Read each element
        P[i]--; // Adjust to 0-based index
    }

    // Create an array to map each value in P to its index
    int *map = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    // Create an array to store indices of elements that are out of order
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
        free(P);
        free(map);
        free(nglist);
        return 0;
    }

    // Calculate the minimum number of swaps required to sort the array P
    int ans = (N - nglist[0] - 1 < nglist[nglist_size - 1] + 1) ? (N - nglist[0] - 1) : (nglist[nglist_size - 1] + 1);
    for (int i = 0; i < nglist_size - 1; ++i) {
        int current = nglist[i] + 1 + N - nglist[i + 1] - 1;
        if (current < ans) {
            ans = current;
        }
    }

    // Print the minimum number of swaps required
    printf("%d\n", ans);

    // Free allocated memory
    free(P);
    free(map);
    free(nglist);
    
    return 0;
}

// <END-OF-CODE>
