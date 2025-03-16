#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function named 'iterate_tokens' that reads input from standard input and yields each token as a string.
char* iterate_tokens() {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* token;
    char* saveptr;

    while ((read = getline(&line, &len, stdin)) != -1) {
        token = strtok_r(line, " ", &saveptr);
        while (token != NULL) {
            yield token;
            token = strtok_r(NULL, " ", &saveptr);
        }
    }

    free(line);
}

// Define a function named 'solve' that takes four integer arguments: H, W, A, and B.
void solve(int H, int W, int A, int B) {

    // Initialize a 2D array named 'answer' of size H x W with all elements set to the string "0".
    char answer[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            answer[i][j] = '0';
        }
    }

    // Iterate through each row 'i' in the range of H.
    for (int i = 0; i < H; i++) {
        // Iterate through each column 'j' in the range of W.
        for (int j = 0; j < W; j++) {
            // Set the value of the cell 'answer[i][j]' based on the conditions.
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

    // Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%c", answer[i][j]);
        }
        printf("\n");
    }
}

// Define a function named 'main' that does not take any arguments.
int main() {

    // Read the input tokens and assign them to the variables H, W, A, and B.
    char* token;
    int H, W, A, B;
    token = iterate_tokens();
    H = atoi(token);
    token = iterate_tokens();
    W = atoi(token);
    token = iterate_tokens();
    A = atoi(token);
    token = iterate_tokens();
    B = atoi(token);

    // Call the 'solve' function with the given input.
    solve(H, W, A, B);

    return 0;
}

