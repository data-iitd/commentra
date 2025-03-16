#include <stdio.h>
#include <stdlib.h>

#define NUM (int)(1e5 + 2)

typedef struct {
    int value;
    int index;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->value - ((Element *)b)->value;
}

int main() {
    int N;
    scanf("%d", &N); // Reading the number of elements in the array

    Element *elements = (Element *)malloc(N * sizeof(Element)); // Array to store elements and their indices

    // Reading the elements one by one and storing them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &elements[i].value); // Reading an element
        elements[i].index = i; // Storing the index of the element
    }

    // Sorting the elements based on their values
    qsort(elements, N, sizeof(Element), compare);

    int bin = 0; // Initializing a binary index variable
    int diff = 0; // Initializing a variable to store the difference in parity between elements

    // Processing the elements in sorted order
    for (int i = 0; i < N; i++) {
        int idx = elements[i].index; // Getting the index of the element

        // Checking if the binary index and the index of the current element have opposite parity
        if ((bin % 2) != (idx % 2)) {
            diff++; // Incrementing the difference if the condition is true
        }

        bin++; // Incrementing the binary index
        bin %= 2; // Setting the binary index to 0 or 1 based on the current parity
    }

    // Calculating and printing the answer
    int ans = diff / 2;
    printf("%d\n", ans);

    free(elements); // Freeing the allocated memory
    return 0;
}

// <END-OF-CODE>
