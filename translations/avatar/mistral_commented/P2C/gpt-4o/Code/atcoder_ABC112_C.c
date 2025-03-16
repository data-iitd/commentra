#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Structure to hold the coordinates and height
typedef struct {
    int x;
    int y;
    int h;
} Point;

// Function to solve the problem
char* solve(int n, Point* ls_xyh) {
    int x0 = -1, y0 = -1, h0 = -1;

    // Find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i].h > 0) {
            x0 = ls_xyh[i].x;
            y0 = ls_xyh[i].y;
            h0 = ls_xyh[i].h;
            break;
        }
    }

    // Allocate memory for candidates
    Point* cands = malloc(101 * 101 * sizeof(Point));
    int cands_count = 0;

    // Generate candidate points
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands[cands_count++] = (Point){cx, cy, h0 + abs(cx - x0) + abs(cy - y0)};
        }
    }

    // Filter out invalid candidate points
    for (int i = 0; i < n; i++) {
        Point p = ls_xyh[i];
        for (int j = 0; j < cands_count; j++) {
            if (max(cands[j].h - abs(cands[j].x - p.x) - abs(cands[j].y - p.y), 0) != p.h) {
                // Shift candidates left if invalid
                for (int k = j; k < cands_count - 1; k++) {
                    cands[k] = cands[k + 1];
                }
                cands_count--;
                j--; // Stay on the same index
            }
        }
    }

    // Find the point with the minimum height among valid candidates
    Point result = cands[0];
    for (int i = 1; i < cands_count; i++) {
        if (cands[i].h < result.h) {
            result = cands[i];
        }
    }

    // Prepare the result as a string
    char* output = malloc(50 * sizeof(char));
    sprintf(output, "%d %d %d", result.x, result.y, result.h);

    // Free allocated memory
    free(cands);

    return output;
}

// Function to read the question and return the problem data
void readQuestion(int* n, Point** ls_xyh) {
    scanf("%d", n);
    *ls_xyh = malloc(*n * sizeof(Point));

    for (int i = 0; i < *n; i++) {
        scanf("%d %d %d", &(*ls_xyh)[i].x, &(*ls_xyh)[i].y, &(*ls_xyh)[i].h);
    }
}

// Main function to call the solve function and print the result
int main() {
    int n;
    Point* ls_xyh;

    // Read the problem data
    readQuestion(&n, &ls_xyh);

    // Call the solve function to get the solution
    char* solution = solve(n, ls_xyh);

    // Print the solution
    printf("%s\n", solution);

    // Free allocated memory
    free(ls_xyh);
    free(solution);

    return 0;
}

// Helper function to calculate max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// End of code
