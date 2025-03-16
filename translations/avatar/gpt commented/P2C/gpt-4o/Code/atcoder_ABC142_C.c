#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int value;
} Element;

// Comparison function for sorting
int compare(const void *a, const void *b) {
    Element *elem1 = (Element *)a;
    Element *elem2 = (Element *)b;
    return elem1->value - elem2->value; // Sort by value
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements

    Element *A = malloc(N * sizeof(Element)); // Allocate memory for N elements

    // Read the elements and store them in the array of structs
    for (int i = 0; i < N; i++) {
        A[i].index = i + 1; // Store the original index (1-based)
        scanf("%d", &A[i].value); // Read the value
    }

    // Sort the array of structs based on the value
    qsort(A, N, sizeof(Element), compare);

    // Print the indices of the sorted values
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" "); // Print space before all but the first index
        }
        printf("%d", A[i].index); // Print the index
    }
    printf("\n"); // Print a newline at the end

    free(A); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
