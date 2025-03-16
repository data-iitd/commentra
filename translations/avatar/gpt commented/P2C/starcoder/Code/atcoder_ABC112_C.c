#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input from standard input and parse the number of buildings and their properties
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    int n = atoi(line);
    int *ls_xyh = (int *) malloc(n * 3 * sizeof(int));
    for (int j = 0; j < n; j++) {
        read = getline(&line, &len, stdin);
        int *p = ls_xyh + j * 3;
        p[0] = atoi(strtok(line, " "));
        p[1] = atoi(strtok(NULL, " "));
        p[2] = atoi(strtok(NULL, " "));
    }
    
    // Initialize the coordinates and height of the first building with a positive height
    int x0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i * 3 + 2] > 0) {
            x0 = ls_xyh[i * 3];
            break;
        }
    }
    
    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    int *cands = (int *) malloc(101 * 101 * 3 * sizeof(int));
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int ch = abs(cx - x0) + abs(cy - ls_xyh[0]) + ls_xyh[0 + 2];
            cands[cx * 101 + cy] = ch;
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (int i = 1; i < n; i++) {
        int x = ls_xyh[i * 3];
        int y = ls_xyh[i * 3 + 1];
        int h = ls_xyh[i * 3 + 2];
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                int ch = cands[cx * 101 + cy];
                cands[cx * 101 + cy] = max(ch - abs(cx - x) - abs(cy - y), 0);
            }
        }
    }
    
    // Select the first valid candidate position and height
    int *p = cands;
    int xx = 0;
    int yy = 0;
    int hh = 0;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            if (p[cx * 101 + cy] > hh) {
                xx = cx;
                yy = cy;
                hh = p[cx * 101 + cy];
            }
        }
    }
    
    // Return the result as a space-separated string
    printf("%d %d %d\n", xx, yy, hh);
    
    // Free memory
    free(line);
    free(ls_xyh);
    free(cands);
    
    return 0;
}

