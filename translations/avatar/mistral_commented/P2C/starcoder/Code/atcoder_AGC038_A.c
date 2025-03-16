#include <stdio.h>
#include <stdlib.h>

// Define a function named'solve' that takes four integer arguments: H, W, A, and B.
void solve(int H, int W, int A, int B) {

    // Initialize a 2D list named 'answer' of size H x W with all elements set to the string "0".
    char **answer = (char **)malloc(H * sizeof(char *));
    for (int i = 0; i < H; i++) {
        answer[i] = (char *)malloc(W * sizeof(char));
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
        printf("%s\n", answer[i]);
    }
}

// Define a function named'main' that does not take any arguments.
int main(void) {

    // Define an inner function named 'iterate_tokens' that reads input from standard input and yields each token as a string.
    char *iterate_tokens(void) {
        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, stdin);
        for (char *word = strtok(line, " "); word!= NULL; word = strtok(NULL, " ")) {
            yield word;
        }
    }

    // Read the input tokens and assign them to the variables H, W, A, and B.
    int H = atoi(next(tokens));
    int W = atoi(next(tokens));
    int A = atoi(next(tokens));
    int B = atoi(next(tokens));

    // Call the'solve' function with the given input.
    solve(H, W, A, B);

    // Free the memory allocated for the 2D list 'answer'.
    for (int i = 0; i < H; i++) {
        free(answer[i]);
    }
    free(answer);

    // Return from the function.
    return 0;
}

