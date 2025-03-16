
#include <stdio.h>

void solve(int H, int W, int A, int B) {
    // Initialize a 2D array (matrix) with dimensions H x W filled with "0"
    char answer[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            answer[i][j] = '0';
        }
    }
    
    // Fill the matrix based on the conditions involving A and B
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // If we are in the first B rows
            if (i < B) {
                // If we are in the first A columns
                if (j < A) {
                    answer[i][j] = '0';  // Set to "0"
                } else {
                    answer[i][j] = '1';  // Set to "1" for columns >= A
                }
            } else {
                // If we are in rows >= B
                if (j < A) {
                    answer[i][j] = '1';  // Set to "1" for columns < A
                } else {
                    answer[i][j] = '0';  // Set to "0" for columns >= A
                }
            }
        }
    }
    
    // Print the resulting matrix row by row
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%c", answer[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Generator function to iterate over input tokens
    char* next_token() {
        static char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);
        char* token = strtok(buffer, " \n");
        return token;
    }
    
    // Read input values for H, W, A, and B
    int H = atoi(next_token());  // Height of the matrix
    int W = atoi(next_token());  // Width of the matrix
    int A = atoi(next_token());  // Column threshold for "0" and "1"
    int B = atoi(next_token());  // Row threshold for "0" and "1"
    
    // Call the solve function with the input parameters
    solve(H, W, A, B);
    
    return 0;
}

