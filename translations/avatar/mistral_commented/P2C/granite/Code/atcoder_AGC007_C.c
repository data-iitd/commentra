
#include <stdio.h>

// Function definition: main function takes three arguments N, d, and x
double main(int N, double d, double x) {
    // Initializing the result variable to 0
    double ret = 0;

    // Loop continues as long as N is greater than 0
    while (N > 0) {
        // Adding the current term to the result
        ret += d + (N - 0.5) * x;

        // Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N);

        // Updating the value of x for the next iteration
        x += 2 * x / N;

        // Decrementing the value of N for the next iteration
        N--;
    }

    // Returning the final result
    return ret;
}

// Main function to read input from standard input and call the main function
int main() {
    // Reading input as three integers: N, d, and x
    int N;
    double d, x;
    scanf("%d %lf %lf", &N, &d, &x);

    // Calling the main function and printing the result
    printf("%.10lf\n", main(N, d, x));

    return 0;
}

