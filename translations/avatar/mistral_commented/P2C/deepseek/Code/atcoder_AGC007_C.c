#include <stdio.h>

// Function to read input from standard input in buffer
void read(int *N, int *d, int *x) {
    scanf("%d %d %d", N, d, x);
}

// Function definition: main function takes three arguments N, d, and x
int main(void) {
    int N, d, x;

    // Reading input as three integers: N, d, and x
    read(&N, &d, &x);

    // Initializing the result variable to 0
    double ret = 0.0;

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
    printf("%.6f\n", ret);

    return 0;
}
