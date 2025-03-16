#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list to store the sequence
    int *L = NULL;
    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;
    // Read a line of input, split it into parts, and iterate over each part
    char input[1000];
    fgets(input, sizeof(input), stdin);
    int len = 0;
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        len++;
    }
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            k = k * 10 + (input[i] - '0');
        } else {
            // Extend the list 'L' by adding 'r' for 'k' times
            if (L == NULL) {
                L = (int *)malloc(k * sizeof(int));
            } else {
                L = (int *)realloc(L, (r - 1) * sizeof(int) + k * sizeof(int));
            }
            for (int j = 0; j < k; j++) {
                L[r - 1 + j] = r;
            }
            // Increment 'r' for the next number
            r++;
            k = 0;
        }
    }
    // Extend the list 'L' by adding 'r' for 'k' times
    if (k > 0) {
        if (L == NULL) {
            L = (int *)malloc(k * sizeof(int));
        } else {
            L = (int *)realloc(L, (r - 1) * sizeof(int) + k * sizeof(int));
        }
        for (int j = 0; j < k; j++) {
            L[r - 1 + j] = r;
        }
        r++;
    }

    // Read another line of input
    fgets(input, sizeof(input), stdin);
    len = 0;
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        len++;
    }
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            j = j * 10 + (input[i] - '0');
        } else {
            // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
            printf("%d\n", L[j - 1]);
            j = 0;
        }
    }
    // Free the allocated memory
    free(L);

    return 0;
}
