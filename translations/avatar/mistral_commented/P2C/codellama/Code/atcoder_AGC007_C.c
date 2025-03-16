#include <stdio.h>
#include <stdlib.h>

// Function to read input from standard input in buffer
void read(char *buffer, int size) {
    fgets(buffer, size, stdin);
}

// Function to read a single line from standard input in buffer
void readline(char *buffer, int size) {
    fgets(buffer, size, stdin);
}

// Function to read multiple lines from standard input in buffer
void readlines(char *buffer, int size) {
    fgets(buffer, size, stdin);
}

// Function definition: main function takes three arguments N, d, and x
int main(int argc, char *argv[]) {
    // Initializing the result variable to 0
    int ret = 0;

    // Reading input as three integers: N, d, and x
    int N, d, x;
    scanf("%d %d %d", &N, &d, &x);

    // Loop continues as long as N is greater than 0
    while (N > 0) {
        // Adding the current term to the result
        ret += d + (N - 0.5) * x;

        // Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N);

        // Updating the value of x for the next iteration
        x += 2 * x / N;

        // Decrementing the value of N for the next iteration
        N -= 1;
    }

    // Returning the final result
    printf("%d\n", ret);

    // End of code
    return 0;
}


Translate the above C code to Java and end with comment "