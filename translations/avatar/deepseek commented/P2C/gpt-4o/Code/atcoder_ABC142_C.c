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
    return elem1->value - elem2->value;
}

int main() {
    int N;
    
    // Input the number of elements (N)
    scanf("%d", &N);
    
    Element *A = (Element *)malloc(N * sizeof(Element));
    
    // Input the elements and create an array of structs
    for (int i = 0; i < N; i++) {
        A[i].index = i + 1; // Store the index (1-based)
        scanf("%d", &A[i].value); // Store the value
    }
    
    // Sort the array of structs based on the integer values
    qsort(A, N, sizeof(Element), compare);
    
    // Print the indices in the required format
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i].index);
    }
    printf("\n");
    
    // Free allocated memory
    free(A);
    
    return 0;
}

// <END-OF-CODE>
