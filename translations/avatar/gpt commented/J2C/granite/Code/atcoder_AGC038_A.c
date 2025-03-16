
#include <stdio.h>

int main() {
    // Create a Scanner object for input and a BufferedWriter for output
    int H, W, A, B;
    scanf("%d %d %d %d", &H, &W, &A, &B); // Read the dimensions of the grid and the parameters A and B
    
    // Check if the grid can accommodate the required number of 0s and 1s
    if (W < 2 * A || H < 2 * B) {
        printf("-1"); // Print -1 if the grid is too small
        return 0; // Exit the program
    }
    
    // Generate the grid based on the parameters A and B
    for (int i = 0; i < H; i++) { // Iterate over each row
        for (int j = 0; j < W; j++) { // Iterate over each column
            // Determine whether to write '0' or '1' based on the current position
            if ((i < B && j < A) || (i >= B && j >= A)) 
                printf("0"); // Write '0' for specified conditions
            else 
                printf("1"); // Write '1' otherwise
        } 
        printf("\n"); // Move to the next line after finishing a row
    } 
    
    return 0;
}
