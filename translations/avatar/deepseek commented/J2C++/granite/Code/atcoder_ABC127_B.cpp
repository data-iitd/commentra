
#include <iostream> // Include necessary libraries for input/output operations
#include <cstdio> // Include cstdio for efficient file input/output operations
#include <cstdlib> // Include cstdlib for dynamic memory allocation
#include <cstring> // Include cstring for string manipulation functions
#include <cmath> // Include cmath for mathematical functions
#include <vector> // Include vector for dynamic arrays
#include <map> // Include map for associative arrays
#include <set> // Include set for unordered sets
#include <queue> // Include queue for priority queues
#include <stack> // Include stack for LIFO data structures
#include <algorithm> // Include algorithm for generic algorithms

using namespace std;

int main() {
    // Create a FILE pointer to read from standard input
    FILE *in = stdin;
    // Create a FILE pointer to write to standard output
    FILE *out = stdout;

    // Read three integers from the input
    int r, d;
    fscanf(in, "%d%d", &r, &d);
    long long x;
    fscanf(in, "%lld", &x);

    // Perform the calculation in a loop and print the result 10 times
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        fprintf(out, "%lld\n", x);
    }

    // Flush the output buffer to ensure all data is written to the output
    fflush(out);

    return 0;
}

