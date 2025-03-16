#include <stdio.h>

void solve(int H, int W, int A, int B) {
    // Declare a 2D array named 'answer' of size H x W.
    char answer[H][W + 1]; // +1 for the null terminator

    // Initialize the 2D array with '0' characters.
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            answer[i][j] = '0';
        }
        answer[i][W] = '\0'; // Null-terminate each row for printing
    }

    // Fill the 'answer' array based on the conditions.
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {
                if (j < A) {
                    answer[i][j] = '0';
                } else {
                    answer[i][j] = '1';
                }
            } else {
                if (j < A) {
                    answer[i][j] = '1';
                } else {
                    answer[i][j] = '0';
                }
            }
        }
    }

    // Print the 'answer' array.
    for (int i = 0; i < H; i++) {
        printf("%s\n", answer[i]);
    }
}

int main() {
    int H, W, A, B;

    // Read the input values for H, W, A, and B.
    scanf("%d %d %d %d", &H, &W, &A, &B);

    // Call the 'solve' function with the given input.
    solve(H, W, A, B);

    return 0;
}

// <END-OF-CODE>
