#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to solve the problem
void solve(int n, int (*ls_xyh)[3]) {
    // Initialize x0 as None
    int x0 = 0;
    int y0 = 0;
    int h0 = 0;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i][0];  // Assign x0, y0, and h0
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    int cands[101][101][3];
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            cands[cx][cy][0] = cx;
            cands[cx][cy][1] = cy;
            cands[cx][cy][2] = h0 + abs(cx - x0) + abs(cy - y0);
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                int ch = cands[cx][cy][2];
                cands[cx][cy][2] = max(ch - abs(cx - x) - abs(cy - y), 0);
            }
        }
    }

    // Find the point with the minimum height among the valid candidates
    int xx = 0;
    int yy = 0;
    int hh = 1000000000;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            if (cands[cx][cy][2] < hh) {
                xx = cands[cx][cy][0];
                yy = cands[cx][cy][1];
                hh = cands[cx][cy][2];
            }
        }
    }

    // Print the solution
    printf("%d %d %d\n", xx, yy, hh);
}

// Function to read the question and return the problem data
void readQuestion(int *n, int (*ls_xyh)[3]) {
    // Read the first line to get the number of points
    scanf("%d", n);

    // Read the second line to get the list of points
    for (int j = 0; j < *n; j++) {
        scanf("%d %d %d", &ls_xyh[j][0], &ls_xyh[j][1], &ls_xyh[j][2]);
    }
}

// Main function to call the solve function and print the result
int main() {
    // Read the problem data
    int n;
    int ls_xyh[100][3];
    readQuestion(&n, ls_xyh);

    // Call the solve function to get the solution
    solve(n, ls_xyh);

    // Return from the main function
    return 0;
}

