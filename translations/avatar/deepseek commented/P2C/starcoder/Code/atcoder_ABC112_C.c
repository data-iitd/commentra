
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    int n = atoi(line);
    int *ls_xyh = (int *) malloc(n * 3 * sizeof(int));
    for (int j = 0; j < n; j++) {
        read = getline(&line, &len, stdin);
        int *p = ls_xyh + 3 * j;
        p[0] = atoi(strtok(line, " "));
        p[1] = atoi(strtok(NULL, " "));
        p[2] = atoi(strtok(NULL, " "));
    }
    
    // Initialize x0 to None
    int x0 = -1;
    
    // Find the point with a positive height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[3 * i + 2] > 0) {
            x0 = ls_xyh[3 * i];
            break;
        }
    }
    
    // Generate candidate points within a 101x101 grid
    int *cands = (int *) malloc(101 * 101 * 3 * sizeof(int));
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int ch = h0 + abs(cx - x0) + abs(cy - y0);
            cands[3 * (cx * 101 + cy) + 0] = cx;
            cands[3 * (cx * 101 + cy) + 1] = cy;
            cands[3 * (cx * 101 + cy) + 2] = ch;
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[3 * i + 0];
        int y = ls_xyh[3 * i + 1];
        int h = ls_xyh[3 * i + 2];
        for (int j = 0; j < 101 * 101; j++) {
            int cx = cands[3 * j + 0];
            int cy = cands[3 * j + 1];
            int ch = cands[3 * j + 2];
            cands[3 * j + 2] = max(ch - abs(cx - x) - abs(cy - y), 0);
        }
    }
    
    // Return the coordinates of the center of the tower
    int *p = cands;
    int xx = p[0];
    int yy = p[1];
    int hh = p[2];
    printf("%d %d %d\n", xx, yy, hh);
    
    // Free memory
    free(line);
    free(ls_xyh);
    free(cands);
    
    return 0;
}

