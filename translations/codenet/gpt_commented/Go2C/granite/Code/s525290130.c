
#include <stdio.h>
#include <stdlib.h>

// nextInt reads the next integer from the scanner and returns it.
int nextInt(FILE *sc) {
    int t;
    fscanf(sc, "%d", &t);
    return t;
}

// reva reverses a slice of integers in place.
void reva(int *b, int len) {
    for (int i = 0; i < len / 2; i++) {
        // Swap the elements at positions i and len-1-i
        int temp = b[i];
        b[i] = b[len-1-i];
        b[len-1-i] = temp;
    }
}

int main() {
    // Create a new scanner to read from standard input
    FILE *sc = stdin;

    // Read the number of elements in the array
    int n = nextInt(sc);
    int *a = (int*)malloc(n * sizeof(int)); // Allocate memory for the array

    // Populate the array with integers from input
    for (int i = 0; i < n; i++) {
        a[i] = nextInt(sc); // Read each integer and store it in the array
    }

    // Read the number of queries
    int q = nextInt(sc);
    // Process each query
    for (int i = 0; i < q; i++) {
        int b = nextInt(sc); // Read the starting index for the reversal
        int e = nextInt(sc); // Read the ending index for the reversal
        reva(&a[b], e-b); // Reverse the slice from index b to e
    }

    // Write the modified array to output
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // Print a space before each element except the first
        }
        printf("%d", a[i]); // Print the current element
    }
    printf("\n"); // Print a newline after the output

    free(a); // Free the memory allocated for the array
    return 0;
}
