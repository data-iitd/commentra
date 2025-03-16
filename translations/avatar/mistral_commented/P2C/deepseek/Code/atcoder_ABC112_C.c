#include <stdio.h>
#include <stdlib.h>

// Function to solve the problem
char* solve(int n, int** ls_xyh) {
    // Initialize x0 as NULL
    int* x0 = NULL;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i];  // Assign x0, y0, and h0
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    int cands[10000][3];
    int cand_index = 0;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int ch = x0[2] + abs(cx - x0[0]) + abs(cy - x0[1]);
            cands[cand_index][0] = cx;
            cands[cand_index][1] = cy;
            cands[cand_index][2] = ch;
            cand_index++;
        }
    }

    // Filter out the invalid candidate points based on the given height
    int valid_cands[10000][3];
    int valid_count = 0;
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        for (int j = 0; j < cand_index; j++) {
            int cx = cands[j][0];
            int cy = cands[j][1];
            int ch = cands[j][2];
            if (max(ch - abs(cx - x) - abs(cy - y), 0) == h) {
                valid_cands[valid_count][0] = cx;
                valid_cands[valid_count][1] = cy;
                valid_cands[valid_count][2] = ch;
                valid_count++;
            }
        }
    }

    // Find the point with the minimum height among the valid candidates
    int xx = valid_cands[0][0];
    int yy = valid_cands[0][1];
    int hh = valid_cands[0][2];

    // Return the solution as a string
    char* solution = (char*)malloc(20 * sizeof(char));
    sprintf(solution, "%d %d %d", xx, yy, hh);
    return solution;
}

// Function to read the question and return the problem data
void readQuestion(int* n, int*** ls_xyh) {
    // Read the first line to get the number of points
    int ws[100];
    fscanf(stdin, "%d", &ws[0]);
    *n = ws[0];

    // Allocate memory for the list of points
    *ls_xyh = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *n; i++) {
        (*ls_xyh)[i] = (int*)malloc(3 * sizeof(int));
    }

    // Read the second line to get the list of points
    for (int j = 0; j < *n; j++) {
        fscanf(stdin, "%d %d %d", &(*ls_xyh)[j][0], &(*ls_xyh)[j][1], &(*ls_xyh)[j][2]);
    }
}

// Main function to call the solve function and print the result
int main() {
    // Declare variables
    int n;
    int** ls_xyh;

    // Call the readQuestion function to get the problem data
    readQuestion(&n, &ls_xyh);

    // Call the solve function to get the solution
    char* solution = solve(n, ls_xyh);

    // Print the solution
    printf("%s\n", solution);

    // Free allocated memory
    free(solution);
    for (int i = 0; i < n; i++) {
        free(ls_xyh[i]);
    }
    free(ls_xyh);

    return 0;
}
