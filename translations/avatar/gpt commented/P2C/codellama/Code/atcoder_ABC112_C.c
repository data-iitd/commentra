#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_H 10000

int solve(int n, int ls_xyh[][3]) {
    // Initialize the coordinates and height of the first building with a positive height
    int x0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    
    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    int cands[MAX_N][MAX_N][2];
    for (int cx = 0; cx < MAX_N; cx++) {
        for (int cy = 0; cy < MAX_N; cy++) {
            cands[cx][cy][0] = cx;
            cands[cx][cy][1] = cy;
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        for (int cx = 0; cx < MAX_N; cx++) {
            for (int cy = 0; cy < MAX_N; cy++) {
                if (cands[cx][cy][1] - abs(cx - x) - abs(cy - y) < h) {
                    cands[cx][cy][0] = -1;
                }
            }
        }
    }
    
    // Select the first valid candidate position and height
    int xx = -1;
    int yy = -1;
    int hh = -1;
    for (int cx = 0; cx < MAX_N; cx++) {
        for (int cy = 0; cy < MAX_N; cy++) {
            if (cands[cx][cy][0] != -1) {
                xx = cands[cx][cy][0];
                yy = cands[cx][cy][1];
                hh = cands[cx][cy][1] - abs(cx - x0) - abs(cy - y0);
                break;
            }
        }
    }
    
    // Return the result as a space-separated string
    return 0;
}

int readQuestion(int *n, int ls_xyh[][3]) {
    // Read input from standard input and parse the number of buildings and their properties
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    sscanf(line, "%d", n);
    for (int i = 0; i < *n; i++) {
        read = getline(&line, &len, stdin);
        sscanf(line, "%d %d %d", &ls_xyh[i][0], &ls_xyh[i][1], &ls_xyh[i][2]);
    }
    return 0;
}

int main() {
    // Execute the solve function with the input read from readQuestion and print the result
    int n;
    int ls_xyh[MAX_N][3];
    readQuestion(&n, ls_xyh);
    printf("%d %d %d\n", solve(n, ls_xyh));
    return 0;
}

