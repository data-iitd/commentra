
#include <stdio.h>

// Set up input reading methods for efficient reading from standard input
#define read(x) fread(x, 1, sizeof(x), stdin)
#define readline(x) fgets(x, sizeof(x), stdin)
#define readlines(x) fread(x, 1, sizeof(x), stdin)

// Read the input values for N, d, and x, and convert them to integers
int N, d, x;
read(&N);
read(&d);
read(&x);

int main(int argc, char *argv[]) {
    // Initialize the result variable to accumulate the final value
    int ret = 0;
    
    // Loop until N becomes zero
    while (N) {
        // Update the result by adding the current d and a calculated value based on N and x
        ret += d + (N - 0.5) * x;
        
        // Update d based on its current value, N, and x
        d += (d / N) + (5 * x) / (2 * N);
        
        // Update x based on its current value and N
        x += 2 * x / N;
        
        // Decrement N to move to the next iteration
        N--;
    }
    
    // Return the accumulated result
    return ret;
}

