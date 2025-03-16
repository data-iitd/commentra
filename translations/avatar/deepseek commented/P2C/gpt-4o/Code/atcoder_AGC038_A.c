#include <stdio.h>

void solve(int H, int W, int A, int B) {
    // Initialize the answer matrix
    char answer[H][W + 1]; // +1 for null terminator

    // Fill the matrix based on the given conditions
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {  // Check if the row index is less than B
                if (j < A) {  // Check if the column index is less than A
                    answer[i][j] = '0';  // Assign '0' if both conditions are met
                } else {
                    answer[i][j] = '1';  // Assign '1' otherwise
                }
            } else {  // If the row index is not less than B
                if (j < A) {
                    answer[i][j] = '1';  // Assign '1' if the column index is less than A
                } else {
                    answer[i][j] = '0';  // Assign '0' otherwise
                }
            }
        }
        answer[i][W] = '\0'; // Null-terminate the string for printing
    }

    // Print each row of the matrix as a string
    for (int i = 0; i < H; i++) {
        printf("%s\n", answer[i]);
    }
}

int main() {
    int H, W, A, B;

    // Read the height, width, number of columns to be filled with "0", and number of rows to be filled with "0"
    scanf("%d %d %d %d", &H, &W, &A, &B);

    solve(H, W, A, B);  // Call the solve function with the read values

    return 0;
}

// <END-OF-CODE>
