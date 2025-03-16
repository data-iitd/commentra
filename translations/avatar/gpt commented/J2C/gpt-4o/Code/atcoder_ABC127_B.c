#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 10240

// Function to read the next integer from input
int nextInt(FILE *input) {
    int value;
    fscanf(input, "%d", &value);
    return value;
}

// Function to read the next long value from input
long nextLong(FILE *input) {
    long value;
    fscanf(input, "%ld", &value);
    return value;
}

int main() {
    // Create a file pointer for standard input
    FILE *input = stdin;

    // Read integer values for r and d, and a long value for x from the input
    int r = nextInt(input);
    int d = nextInt(input);
    long x = nextLong(input);

    // Perform the calculation and output the result 10 times
    for (int i = 0; i < 10; ++i) {
        // Update x according to the formula x = r * x - d
        x = r * x - d;
        // Print the updated value of x
        printf("%ld\n", x);
    }

    return 0;
}

// <END-OF-CODE>
