
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    // Read input values N and X from the standard input

    int xs[N];
    // Define an array xs of size N to store the calculated values

    for (int i = 0; i < N; i++) {
        xs[i] = i + 1;
    }
    // Initialize the array xs with values from 1 to N

    if (X == 1 || X == N * 2 - 1) {
    // Check if X is equal to 1 or N*2-1

        printf("No\n");
    // If it is, print "No" and end the program

        return 0;
    }
    // Else, X is neither 1 nor N*2-1

    printf("Yes\n");
    // Print "Yes"

    if (X == N * 2 - 2) {
        for (int i = N - 1; i < N + 2; i++) {
            xs[i % N] = X + 2 - i;
        }
    } else {
        int ys[N - 3];
        // Define an array ys of size N-3 to store the calculated values

        for (int i = 0; i < N - 3; i++) {
            ys[i] = i + 1;
        }
        // Initialize the array ys with values from 1 to N-3

        for (int i = 0; i < N - 3; i++) {
            ys[i] = ys[i] + X - 1 - i;
        }
        // Calculate the array ys based on the value of X

        for (int i = 0; i < N - 3; i++) {
            xs[i] = ys[i];
        }
        // Copy the values from ys to xs

        xs[N - 3] = X + 2;
        xs[N - 2] = X - 1;
        xs[N - 1] = X;
        xs[N - 0] = X + 1;
    }
    // Calculate the array xs based on the value of X

    for (int i = 0; i < N; i++) {
        printf("%d\n", xs[i]);
    }
    // Print each element of the array xs

    return 0;
}
// End of C code