#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define INF 1000000007
<<<<<<< HEAD
#define INF2 1000000009
#define INF3 998244353
=======
>>>>>>> 98c87cb78a (data updated)
#define BLACK 35

// Function prototypes
int countBlack(int h, int w, int **m);
int solve(int h, int w, int a, int **m);
<<<<<<< HEAD
void freeGrid(int **grid, int h);
=======
void flush();
>>>>>>> 98c87cb78a (data updated)

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k); // Read height, width, and target count

    // Allocate memory for the grid
    int **m = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        m[i] = (int *)malloc(w * sizeof(int));
    }

    // Read the grid
    for (int i = 0; i < h; i++) {
        char s[100]; // Assuming max width is 100
<<<<<<< HEAD
        scanf("%s", s);
=======
        scanf("%s", s); // Read the row as a string
>>>>>>> 98c87cb78a (data updated)
        for (int j = 0; j < w; j++) {
            m[i][j] = (int)s[j]; // Convert each character to int and store
        }
    }

    int answer = solve(h, w, k, m); // Solve the problem and get the answer
    printf("%d\n", answer); // Print the answer

    // Free allocated memory
<<<<<<< HEAD
    freeGrid(m, h);
    return 0;
}

// Function to free the allocated grid
void freeGrid(int **grid, int h) {
    for (int i = 0; i < h; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Function to count the number of black cells in the grid
=======
    for (int i = 0; i < h; i++) {
        free(m[i]);
    }
    free(m);

    flush(); // Ensure output is flushed at the end
    return 0;
}

// Count the number of black cells in the grid
>>>>>>> 98c87cb78a (data updated)
int countBlack(int h, int w, int **m) {
    int count = 0; // Initialize count
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == BLACK) {
                count++; // Increment count if the cell is black
            }
        }
    }
    return count; // Return the count of black cells
}

<<<<<<< HEAD
// Function to calculate the number of ways to paint the grid to achieve the target count of black cells
=======
// Calculate the number of ways to paint the grid to achieve the target count of black cells
>>>>>>> 98c87cb78a (data updated)
int solve(int h, int w, int a, int **m) {
    int result = 0; // Initialize result
    for (int i = 0; i < (1 << h); i++) { // Iterate over all possible row paint combinations
        for (int k = 0; k < (1 << w); k++) { // Iterate over all possible column paint combinations
            // Create a temporary grid to simulate painting
            int **tmp = (int **)malloc(h * sizeof(int *));
            for (int j = 0; j < h; j++) {
                tmp[j] = (int *)malloc(w * sizeof(int));
                memcpy(tmp[j], m[j], w * sizeof(int)); // Copy original grid to temporary grid
            }

            // Paint rows based on the current combination
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) { // Check if the current row is painted
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1; // Paint the entire row
                    }
                }
            }

            // Paint columns based on the current combination
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) { // Check if the current column is painted
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1; // Paint the entire column
                    }
                }
            }

            if (countBlack(h, w, tmp) == a) { // Check if the count of black cells matches the target
                result++; // Increment result if it matches
            }

            // Free temporary grid
            for (int j = 0; j < h; j++) {
                free(tmp[j]);
            }
            free(tmp);
        }
    }
    return result; // Return the total number of valid combinations
}
<<<<<<< HEAD
=======

// Flush function (not strictly necessary in C, but included for completeness)
void flush() {
    fflush(stdout);
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
