#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to solve the problem
char* solve(int n, int** ls_xyh) {
    // Initialize x0 as None
    int x0 = -1;
    int y0 = -1;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    int** cands = (int**)malloc(sizeof(int*) * 101 * 101);
    int cands_size = 0;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int h0 = ls_xyh[0][2];
            int h = h0 + abs(cx - x0) + abs(cy - y0);
            cands[cands_size] = (int*)malloc(sizeof(int) * 3);
            cands[cands_size][0] = cx;
            cands[cands_size][1] = cy;
            cands[cands_size][2] = h;
            cands_size++;
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        for (int j = 0; j < cands_size; j++) {
            int cx = cands[j][0];
            int cy = cands[j][1];
            int ch = cands[j][2];
            if (max(ch - abs(cx - x) - abs(cy - y), 0) == h) {
                cands[j][2] = -1;
            }
        }
    }

    // Find the point with the minimum height among the valid candidates
    int min_h = 1000000000;
    int min_i = -1;
    for (int i = 0; i < cands_size; i++) {
        if (cands[i][2] > 0 && cands[i][2] < min_h) {
            min_h = cands[i][2];
            min_i = i;
        }
    }

    // Return the solution as a string
    char* solution = (char*)malloc(sizeof(char) * 100);
    sprintf(solution, "%d %d %d", cands[min_i][0], cands[min_i][1], cands[min_i][2]);
    return solution;
}

// Function to read the question and return the problem data
int** readQuestion() {
    // Read the first line to get the number of points
    char* line = (char*)malloc(sizeof(char) * 100);
    fgets(line, 100, stdin);
    int n = atoi(strtok(line, " "));

    // Read the second line to get the list of points
    int** ls_xyh = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        fgets(line, 100, stdin);
        ls_xyh[i] = (int*)malloc(sizeof(int) * 3);
        ls_xyh[i][0] = atoi(strtok(line, " "));
        ls_xyh[i][1] = atoi(strtok(NULL, " "));
        ls_xyh[i][2] = atoi(strtok(NULL, " "));
    }

    // Return the problem data as a tuple (number of points, list of points)
    return ls_xyh;
}

// Main function to call the solve function and print the result
int main() {
    // Call the readQuestion function to get the problem data
    int** data = readQuestion();

    // Call the solve function to get the solution
    char* solution = solve(data[0][0], data);

    // Print the solution
    printf("%s", solution);

    // Free the memory
    for (int i = 0; i < data[0][0]; i++) {
        free(data[i]);
    }
    free(data);
    free(solution);

    return 0;
}

