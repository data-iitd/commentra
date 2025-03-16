
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, h;
} point;

char* solve(int n, point* ls_xyh) {
    int x0 = -1, y0 = -1, h0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i].h > 0) {
            x0 = ls_xyh[i].x;
            y0 = ls_xyh[i].y;
            h0 = ls_xyh[i].h;
            break;
        }
    }
    point* cands = (point*)malloc(sizeof(point) * 101 * 101);
    int cand_count = 0;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int h = h0 + abs(cx - x0) + abs(cy - y0);
            cands[cand_count].x = cx;
            cands[cand_count].y = cy;
            cands[cand_count].h = h;
            cand_count++;
        }
    }
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i].x;
        int y = ls_xyh[i].y;
        int h = ls_xyh[i].h;
        int new_cand_count = 0;
        for (int j = 0; j < cand_count; j++) {
            int new_h = cands[j].h - abs(cands[j].x - x) - abs(cands[j].y - y);
            if (new_h >= 0 && new_h == h) {
                cands[new_cand_count].x = cands[j].x;
                cands[new_cand_count].y = cands[j].y;
                cands[new_cand_count].h = new_h;
                new_cand_count++;
            }
        }
        cand_count = new_cand_count;
    }
    char* result = (char*)malloc(sizeof(char) * 100);
    sprintf(result, "%d %d %d", cands[0].x, cands[0].y, cands[0].h);
    return result;
}

int main() {
    int n;
    point* ls_xyh;
    char* result = solve(n, ls_xyh);
    printf("%s\n", result);
    free(result);
    return 0;
}
// END-OF-CODE