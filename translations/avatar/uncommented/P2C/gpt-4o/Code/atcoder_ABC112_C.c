#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int h;
} Point;

void solve(int n, Point* ls_xyh) {
    int x0 = -1, y0 = -1, h0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i].h > 0) {
            x0 = ls_xyh[i].x;
            y0 = ls_xyh[i].y;
            h0 = ls_xyh[i].h;
            break;
        }
    }

    Point cands[10201]; // 101 * 101 = 10201 possible candidates
    int cands_count = 0;

    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands[cands_count++] = (Point){cx, cy, h0 + abs(cx - x0) + abs(cy - y0)};
        }
    }

    for (int i = 0; i < n; i++) {
        Point* new_cands = (Point*)malloc(cands_count * sizeof(Point));
        int new_cands_count = 0;

        for (int j = 0; j < cands_count; j++) {
            int ch = cands[j].h;
            int cx = cands[j].x;
            int cy = cands[j].y;
            if (fmax(ch - abs(cx - ls_xyh[i].x) - abs(cy - ls_xyh[i].y), 0) == ls_xyh[i].h) {
                new_cands[new_cands_count++] = cands[j];
            }
        }

        free(cands);
        cands = new_cands;
        cands_count = new_cands_count;
    }

    printf("%d %d %d\n", cands[0].x, cands[0].y, cands[0].h);
    free(cands);
}

void readQuestion(int* n, Point** ls_xyh) {
    scanf("%d", n);
    *ls_xyh = (Point*)malloc(*n * sizeof(Point));
    for (int i = 0; i < *n; i++) {
        scanf("%d %d %d", &(*ls_xyh)[i].x, &(*ls_xyh)[i].y, &(*ls_xyh)[i].h);
    }
}

int main() {
    int n;
    Point* ls_xyh;
    readQuestion(&n, &ls_xyh);
    solve(n, ls_xyh);
    free(ls_xyh);
    return 0;
}

// <END-OF-CODE>
