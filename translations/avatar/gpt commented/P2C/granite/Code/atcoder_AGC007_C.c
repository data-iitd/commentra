
#include <stdio.h>

int main() {
    // Read the input values for N, d, and x, and convert them to integers
    int N, d, x;
    scanf("%d %d %d", &N, &d, &x);

    int ret = 0;

    // Loop until N becomes zero
    while (N) {
        // Update the result by adding the current d and a calculated value based on N and x
        ret += d + (N - 0.5) * x;

        // Update d based on its current value, N, and x
        d = d + (d / N) + (5 * x) / (2 * N);

        // Update x based on its current value and N
        x += 2 * x / N;

        // Decrement N to move to the next iteration
        N--;
    }

    // Print the accumulated result
    printf("%d\n", ret);

    return 0;
}

