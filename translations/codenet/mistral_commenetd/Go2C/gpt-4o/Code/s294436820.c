#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for large prime numbers used in modular arithmetic.
#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

// Constants for black cell representation.
#define Black 35

// Function prototypes
int countBlack(int h, int w, int **m);
int solve(int h, int w, int a, int **m);
void freeMatrix(int **matrix, int h);

int main() {
    // Read input
    int h, w, a;
    scanf("%d %d %d", &h, &w, &a);
    
    // Allocate memory for the matrix
    int **m = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        m[i] = (int *)malloc(w * sizeof(int));
        char s[w + 1]; // +1 for null terminator
        scanf("%s", s);
        for (int j = 0; j < w; j++) {
            m[i][j] = (int)s[j];
        }
    }

    // Solve the problem
    int answer = solve(h, w, a, m);

    // Print the result
    printf("%d\n", answer);

    // Free allocated memory
    freeMatrix(m, h);
    return 0;
}

// Function to count the number of black cells in a grid.
int countBlack(int h, int w, int **m) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++;
            }
        }
    }
    return count;
}

// Function to solve the problem.
int solve(int h, int w, int a, int **m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            // Create a temporary matrix
            int **tmp = (int **)malloc(h * sizeof(int *));
            for (int j = 0; j < h; j++) {
                tmp[j] = (int *)malloc(w * sizeof(int));
                memcpy(tmp[j], m[j], w * sizeof(int));
            }
            // Paint rows
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            // Paint columns
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            // Check the count of black cells
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
            // Free temporary matrix
            freeMatrix(tmp, h);
        }
    }
    return result;
}

// Function to free allocated memory for a matrix
void freeMatrix(int **matrix, int h) {
    for (int i = 0; i < h; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// <END-OF-CODE>
