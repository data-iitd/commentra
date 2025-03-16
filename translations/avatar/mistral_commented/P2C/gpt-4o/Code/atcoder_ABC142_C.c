#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int value;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->value - ((Element *)b)->value;
}

int main() {
    // Define the number of elements in the list 'A'
    int N;
    scanf("%d", &N);

    // Initialize an array of 'Element' structs
    Element *A = malloc(N * sizeof(Element));

    // Read the values and populate the array 'A'
    for (int i = 0; i < N; i++) {
        A[i].index = i + 1; // Store the index (1-based)
        scanf("%d", &A[i].value); // Read the value
    }

    // Sort the array 'A' based on the value
    qsort(A, N, sizeof(Element), compare);

    // Print the indices in sorted order
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i].index);
    }
    printf("\n");

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
