
#include <stdio.h> // Include the standard input/output library

int main() { // Main function is the entry point of the program
    int H, W, A, B; // Declare variables to store the matrix dimensions and values of A and B

    // Read the matrix dimensions and values of A and B from the console
    scanf("%d %d %d %d", &H, &W, &A, &B);

    // Check if the matrix dimensions are suitable for the given values of A and B
    if (W < 2 * A || H < 2 * B) {
        printf("-1\n"); // Print -1 if the matrix dimensions are not suitable
        return 0; // Exit the program
    }

    // Nested loops to generate the matrix
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Assign 0 or 1 based on the conditions specified
            if ((i < B && j < A) || (i >= B) && (j >= A)) {
                printf("0"); // Print 0
            } else {
                printf("1"); // Print 1
            }
        }
        printf("\n"); // Move to the next line after each row is printed
    }

    return 0; // Return 0 to indicate successful execution
}
