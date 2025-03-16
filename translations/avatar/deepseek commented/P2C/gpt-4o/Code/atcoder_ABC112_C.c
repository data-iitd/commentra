#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int h;
} Point;

void solve(int n, Point *ls_xyh, int *result) {
    int x0 = -1, y0 = -1, h0 = -1;

    // Find the point with a positive height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i].h > 0) {
            x0 = ls_xyh[i].x;
            y0 = ls_xyh[i].y;
            h0 = ls_xyh[i].h;
            break;
        }
    }

    // Generate candidate points within a 101x101 grid
    Point cands[10201]; // 101 * 101 = 10201
    int cands_count = 0;

    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands[cands_count++] = (Point){cx, cy, h0 + abs(cx - x0) + abs(cy - y0)};
        }
    }

    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i].x;
        int y = ls_xyh[i].y;
        int h = ls_xyh[i].h;

        int new_cands_count = 0;
        for (int j = 0; j < cands_count; j++) {
            int ch = cands[j].h;
            if (max(ch - abs(cands[j].x - x) - abs(cands[j].y - y), 0) == h) {
                cands[new_cands_count++] = cands[j];
            }
        }
        cands_count = new_cands_count;
    }

    // Return the coordinates of the center of the tower
    result[0] = cands[0].x;
    result[1] = cands[0].y;
    result[2] = cands[0].h;
}

int readQuestion(int *n, Point **ls_xyh) {
    scanf("%d", n);
    *ls_xyh = (Point *)malloc(*n * sizeof(Point));
    for (int i = 0; i < *n; i++) {
        scanf("%d %d %d", &(*ls_xyh)[i].x, &(*ls_xyh)[i].y, &(*ls_xyh)[i].h);
    }
    return 0;
}

int main() {
    int n;
    Point *ls_xyh;
    readQuestion(&n, &ls_xyh);

    int result[3];
    solve(n, ls_xyh, result);

    printf("%d %d %d\n", result[0], result[1], result[2]);

    free(ls_xyh);
    return 0;
}

// <END-OF-CODE>
