
#include <stdio.h> // Include necessary header files for input/output operations
#include <stdlib.h> // Include necessary header files for memory allocation and deallocation
#include <stdbool.h> // Include necessary header files for boolean data type

int main() {
    // Create a FILE pointer to read from standard input
    FILE *in = stdin;
    // Create a FILE pointer to write to standard output
    FILE *out = stdout;

    // Read three integers from the input
    int r, d;
    long long x;
    fscanf(in, "%d %d %lld", &r, &d, &x);

    // Perform the calculation in a loop and print the result 10 times
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        fprintf(out, "%lld\n", x);
    }

    // Flush the output buffer to ensure all data is written to the output
    fflush(out);

    // Close the input and output files to release system resources
    fclose(in);
    fclose(out);

    return 0;
}

