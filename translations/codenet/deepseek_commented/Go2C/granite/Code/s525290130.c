
#include <stdio.h>
#include <stdlib.h>

// nextInt reads the next word from the scanner, converts it to an integer, and returns it.
int nextInt(FILE *sc) {
    int t;
    fscanf(sc, "%d", &t);
    return t;
}

// reva takes a slice of integers and reverses it in place.
void reva(int *b, int len) {
    for (int i = 0; i < len / 2; i++) {
        int temp = b[i];
        b[i] = b[len - 1 - i];
        b[len - 1 - i] = temp;
    }
}

int main() {
    FILE *sc = stdin;
    int n = nextInt(sc); // Reads the number of elements
    int *a = (int *)malloc(n * sizeof(int)); // Initializes a slice of integers with size n
    for (int i = 0; i < n; i++) {
        a[i] = nextInt(sc); // Reads each element and assigns it to the slice
    }
    int q = nextInt(sc); // Reads the number of queries
    for (int i = 0; i < q; i++) {
        int b = nextInt(sc); // Reads the start index of the segment to reverse
        int e = nextInt(sc); // Reads the end index of the segment to reverse
        reva(a + b, e - b); // Reverses the segment of the array
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // Adds a space between elements, except before the first element
        }
        printf("%d", a[i]); // Writes the element to the output
    }
    printf("\n"); // Adds a newline after all elements
    return 0;
}
