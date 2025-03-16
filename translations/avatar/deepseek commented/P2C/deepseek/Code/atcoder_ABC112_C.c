#include <stdio.h>
#include <stdlib.h>

void solve(int n, int** ls_xyh) {
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
    int cands[101 * 101][3];
    int cand_index = 0;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            cands[cand_index][0] = cx;
            cands[cand_index][1] = cy;
            cands[cand_index][2] = ls_xyh[x0][2] + abs(cx - ls_xyh[x0][0]) + abs(cy - ls_xyh[x0][1]);
            cand_index++;
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        int temp_cands[101 * 101][3];
        int temp_index = 0;
        for (int j = 0; j < cand_index; j++) {
            int cx = cands[j][0];
            int cy = cands[j][1];
            int ch = cands[j][2];
            if (max(ch - abs(cx - x) - abs(cy - y), 0) == h) {
                temp_cands[temp_index][0] = cx;
                temp_cands[temp_index][1] = cy;
                temp_cands[temp_index][2] = ch;
                temp_index++;
            }
        }
        cand_index = temp_index;
        for (int j = 0; j < cand_index; j++) {
            cands[j][0] = temp_cands[j][0];
            cands[j][1] = temp_cands[j][1];
            cands[j][2] = temp_cands[j][2];
        }
    }
    
    // Print the coordinates of the center of the tower
    printf("%d %d %d\n", cands[0][0], cands[0][1], cands[0][2]);
}

void readQuestion() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    int n;
    scanf("%d", &n);
    int** ls_xyh = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        ls_xyh[i] = (int*)malloc(3 * sizeof(int));
        scanf("%d %d %d", &ls_xyh[i][0], &ls_xyh[i][1], &ls_xyh[i][2]);
    }
    solve(n, ls_xyh);
    for (int i = 0; i < n; i++) {
        free(ls_xyh[i]);
    }
    free(ls_xyh);
}

int main() {
    // Read input, solve the problem, and print the result
    readQuestion();
    return 0;
}

