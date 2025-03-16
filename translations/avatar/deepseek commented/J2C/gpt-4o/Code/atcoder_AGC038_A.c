#include <stdio.h> // Including standard input-output library

int main() {
    int H, W, A, B; // Declaring variables for height, width, and values A and B

    // Reading the height, width, and values A and B from input
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
            if ((i < B && j < A) || (i >= B && j >= A)) {
                printf("0"); // Printing 0
            } else {
                printf("1"); // Printing 1
            }
        }
        printf("\n"); // Moving to the next line after each row is printed
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
