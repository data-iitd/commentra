#include <stdio.h>
#include <stdlib.h>

// Defining a static inner class FastReader for reading input
typedef struct {
    char buffer[1000000];
    int position;
    int length;
} FastReader;

// Function for reversing a number
int reverse(int n) {
    // Base case for numbers less than 10
    if (n < 10)
        return n * 10;

    // Initializing variables
    int t = n, r = 0;

    // Reversing the number
    while (t > 0) {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10;

        // Moving to the next digit
        t = t / 10;
    }

    // Returning the reversed number
    return r;
}

// Main function
int main() {
    // Creating an instance of FastReader
    FastReader sc = (FastReader) malloc(sizeof(FastReader));

    // Reading input for number of test cases
    int n = sc->nextInt();

    // Reading input for number of operations
    int m = sc->nextInt();

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    printf("%d\n", t + n);

    // Deallocating memory
    free(sc);

    // Returning from main
    return 0;
}

