
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a FILE pointer to read input from the standard input stream
    FILE *in = stdin;

    // Create a FILE pointer to write output to the standard output stream
    FILE *out = stdout;

    // Read integer values for r and d, and a long value for x from the input
    int r;
    int d;
    long x;
    fscanf(in, "%d %d %ld", &r, &d, &x);

    // Perform the calculation and output the result 10 times
    for (int i = 0; i < 10; ++i) {
        // Update x according to the formula x = r * x - d
        x = r * x - d;
        // Print the updated value of x
        fprintf(out, "%ld\n", x);
    }

    // Close the output file to release resources
    fclose(out);

    return 0;
}
