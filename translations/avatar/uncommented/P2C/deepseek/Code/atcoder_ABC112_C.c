#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int** readIntMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void solve(int n, int** ls_xyh) {
    int x0 = -1, y0 = -1, h0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }

    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int h = h0 + abs(x0 - cx) + abs(y0 - cy);
            int valid = 1;
            for (int i = 0; i < n; i++) {
                int x = ls_xyh[i][0];
                int y = ls_xyh[i][1];
                int h_i = ls_xyh[i][2];
                if (max(h - abs(x - cx) - abs(y - cy), 0) != h_i) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                printf("%d %d %d\n", cx, cy, h);
                return;
            }
        }
    }
}

int main() {
    int n = readInt();
    int** ls_xyh = readIntMatrix(n);
    solve(n, ls_xyh);
    for (int i = 0; i < n; i++) {
        free(ls_xyh[i]);
    }
    free(ls_xyh);
    return 0;
}

