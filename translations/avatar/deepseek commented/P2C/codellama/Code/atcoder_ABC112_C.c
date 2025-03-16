
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_H 1000

int solve(int n, int ls_xyh[][3]) {
    // Initialize x0 to None
    int x0 = -1;
    
    // Find the point with a positive height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    
    // Generate candidate points within a 101x101 grid
    int cands[MAX_N][3];
    int ncands = 0;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int h0 = ls_xyh[x0][2];
            int h = h0 + abs(cx - x0) + abs(cy - ls_xyh[x0][1]);
            cands[ncands][0] = cx;
            cands[ncands][1] = cy;
            cands[ncands][2] = h;
            ncands++;
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        int ncands2 = 0;
        for (int j = 0; j < ncands; j++) {
            int cx = cands[j][0];
            int cy = cands[j][1];
            int ch = cands[j][2];
            if (max(ch - abs(cx - x) - abs(cy - y), 0) == h) {
                cands[ncands2][0] = cx;
                cands[ncands2][1] = cy;
                cands[ncands2][2] = ch;
                ncands2++;
            }
        }
        ncands = ncands2;
    }
    
    // Return the coordinates of the center of the tower
    int xx = cands[0][0];
    int yy = cands[0][1];
    int hh = cands[0][2];
    return ' '.join([str(xx), str(yy), str(hh)])

int readQuestion() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    char *ws = malloc(1000000);
    scanf("%s", ws);
    int n = atoi(strtok(ws, " "));
    int ls_xyh[MAX_N][3];
    for (int i = 0; i < n; i++) {
        char *ws = malloc(1000000);
        scanf("%s", ws);
        int x = atoi(strtok(ws, " "));
        int y = atoi(strtok(NULL, " "));
        int h = atoi(strtok(NULL, " "));
        ls_xyh[i][0] = x;
        ls_xyh[i][1] = y;
        ls_xyh[i][2] = h;
    }
    return (n, ls_xyh);
}

int main() {
    // Read input, solve the problem, and print the result
    printf("%s\n", solve(*readQuestion()));
    return 0;
}

