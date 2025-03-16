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

// Function to read the next long integer from input
long nextLong(FILE *input) {
    long value;
    fscanf(input, "%ld", &value);
    return value;
}

int main() {
    // Read three integers from the input
    int r = nextInt(stdin);
    int d = nextInt(stdin);
    long x = nextLong(stdin);

    // Perform the calculation in a loop and print the result 10 times
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        printf("%ld\n", x);
    }

    return 0;
}

// <END-OF-CODE>
