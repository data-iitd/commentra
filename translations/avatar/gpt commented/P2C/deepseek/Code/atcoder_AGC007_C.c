#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a line from standard input
void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
}

// Main function to calculate the result
int main() {
    // Read the input values for N, d, and x
    int N = readInt();
    int d = readInt();
    int x = readInt();

    // Initialize the result variable to accumulate the final value
    double ret = 0.0;

    // Loop until N becomes zero
    while (N > 0) {
        // Update the result by adding the current d and a calculated value based on N and x
        ret += d + (N - 0.5) * x;

        // Update d based on its current value, N, and x
        d = d + (d / N) + (5 * x) / (2 * N);

        // Update x based on its current value and N
        x += 2 * x / N;

        // Decrement N to move to the next iteration
        N--;
    }

    // Print the result
    printf("%.6f\n", ret);

    return 0;
}
