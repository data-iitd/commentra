#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, h;
} Building;

char* solve(int n, Building* ls_xyh) {
    // Allocate memory for the result string
    char* result = (char*)malloc(50 * sizeof(char));
    int x0 = -1, y0 = -1, h0 = -1;

    // Initialize the coordinates and height of the first building with a positive height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i].h > 0) {
            x0 = ls_xyh[i].x;
            y0 = ls_xyh[i].y;
            h0 = ls_xyh[i].h;
            break;
        }
    }

    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int ch = h0 + abs(cx - x0) + abs(cy - y0);
            int valid = 1;

            // Filter candidates based on the height constraints from the other buildings
            for (int j = 0; j < n; j++) {
                int h = ls_xyh[j].h;
                if (max(ch - abs(cx - ls_xyh[j].x) - abs(cy - ls_xyh[j].y), 0) != h) {
                    valid = 0;
                    break;
                }
            }

            // Select the first valid candidate position and height
            if (valid) {
                sprintf(result, "%d %d %d", cx, cy, ch);
                return result;
            }
        }
    }

    // Return the result as a space-separated string
    return result;
}

Building* readQuestion() {
    // Read input from standard input and parse the number of buildings and their properties
    int n;
    scanf("%d", &n);
    Building* ls_xyh = (Building*)malloc(n * sizeof(Building));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &ls_xyh[i].x, &ls_xyh[i].y, &ls_xyh[i].h);
    }
    return ls_xyh;
}

int main() {
    // Execute the solve function with the input read from readQuestion and print the result
    Building* ls_xyh = readQuestion();
    char* result = solve(n, ls_xyh);
    printf("%s\n", result);
    free(ls_xyh);
    free(result);
    return 0;
}
