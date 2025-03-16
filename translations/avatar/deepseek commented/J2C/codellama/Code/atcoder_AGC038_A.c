#include <stdio.h> // Including header file for input and output
#include <stdlib.h> // Including header file for memory management

int main() { // Main function is the entry point of the program
    int H, W, A, B; // Declaring variables for the matrix dimensions and the values of A and B

    // Reading the matrix dimensions and the values of A and B
    scanf("%d %d %d %d", &H, &W, &A, &B);

    // Checking if the matrix dimensions are suitable for the given values of A and B
    if (W < 2 * A || H < 2 * B) {
        printf("-1\n"); // Printing -1 if the matrix dimensions are not suitable
        return 0; // Exiting the program
    }

    // Nested loops to generate the matrix
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Assigning 0 or 1 based on the conditions specified
            if ((i < B && j < A) || (i >= B) && (j >= A)) {
                printf("0"); // Writing 0 to the console
            } else {
                printf("1"); // Writing 1 to the console
            }
        }
        printf("\n"); // Moving to the next line after each row is written
    }

    return 0; // Exiting the program
}

