
#include <stdio.h>

void solve(int H, int W, int A, int B) {
    // Initialize the answer matrix with "0"
    char answer[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            answer[i][j] = '0';
        }
    }
    
    // Fill the matrix based on the given conditions
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {  // Check if the row index is less than B
                if (j < A) {  // Check if the column index is less than A
                    answer[i][j] = '0';  // Assign "0" if both conditions are met
                } else {
                    answer[i][j] = '1';  // Assign "1" otherwise
                }
            } else {  // If the row index is not less than B
                if (j < A) {
                    answer[i][j] = '1';  // Assign "1" if the column index is less than A
                } else {
                    answer[i][j] = '0';  // Assign "0" otherwise
                }
            }
        }
    }
    
    // Print each row of the matrix as a string
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%c", answer[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B);  // Read the height, width, number of columns to be filled with "0", and number of rows to be filled with "0"
    solve(H, W, A, B);  // Call the solve function with the read values
    return 0;
}

