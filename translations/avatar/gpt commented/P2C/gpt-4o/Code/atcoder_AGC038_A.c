#include <stdio.h>
#include <stdlib.h>

void solve(int H, int W, int A, int B) {
    // Allocate memory for a 2D array (matrix) with dimensions H x W
    char **answer = (char **)malloc(H * sizeof(char *));
    for (int i = 0; i < H; i++) {
        answer[i] = (char *)malloc((W + 1) * sizeof(char)); // +1 for null terminator
    }

    // Fill the matrix based on the conditions involving A and B
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // If we are in the first B rows
            if (i < B) {
                // If we are in the first A columns
                if (j < A) {
                    answer[i][j] = '0';  // Set to '0'
                } else {
                    answer[i][j] = '1';  // Set to '1' for columns >= A
                }
            } else {
                // If we are in rows >= B
                if (j < A) {
                    answer[i][j] = '1';  // Set to '1' for columns < A
                } else {
                    answer[i][j] = '0';  // Set to '0' for columns >= A
                }
            }
        }
        answer[i][W] = '\0'; // Null-terminate the string for each row
    }

    // Print the resulting matrix row by row
    for (int i = 0; i < H; i++) {
        printf("%s\n", answer[i]);
        free(answer[i]); // Free each row after printing
    }
    free(answer); // Free the array of pointers

    return;
}

int main() {
    int H, W, A, B;

    // Read input values for H, W, A, and B
    scanf("%d %d %d %d", &H, &W, &A, &B);

    // Call the solve function with the input parameters
    solve(H, W, A, B);

    return 0;
}

// <END-OF-CODE>
