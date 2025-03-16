#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the index and value
typedef struct {
    int index;
    int value;
} Element;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Element *elem1 = (Element *)a;
    Element *elem2 = (Element *)b;
    return elem1->value - elem2->value;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for N elements
    Element *A = (Element *)malloc(N * sizeof(Element));

    // Read the elements from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i].value);
        A[i].index = i + 1;
    }

    // Sort the array using qsort and the custom comparison function
    qsort(A, N, sizeof(Element), compare);

    // Print the indices of the sorted values, separated by spaces
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A[i].index);
    }
    printf("%d\n", A[N - 1].index);

    // Free the allocated memory
    free(A);

    return 0;
}
