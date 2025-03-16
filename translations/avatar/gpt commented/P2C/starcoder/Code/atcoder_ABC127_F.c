#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <assert.h>

int main() {
    int q;
    scanf("%d", &q);
    int ans[2] = {0, 0};
    int p1[100000] = {0};
    int p2[100000] = {0};
    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;
    for (int i = 0; i < q; i++) {
        int ql[3];
        scanf("%d %d %d", &ql[0], &ql[1], &ql[2]);
        if (ql[0] == 2) {
            if (p1[0] == p2[0]) {
                printf("%d %d\n", -p2[0], sum_p1 - p1[0] * (int)log2(p1[0]) + p2[0] * (int)log2(p2[0]) - sum_p2 + sum_b);
            } else {
                printf("%d %d\n", p1[0], sum_p1 - p1[0] * (int)log2(p1[0]) + p2[0] * (int)log2(p1[0]) - sum_p2 + sum_b);
            }
        } else {
            sum_b += ql[2];
            if (p1[0] == 0) {
                p1[0] = ql[1];
                sum_p1 += ql[1];
            } else if (p1[0] >= ql[1]) {
                p1[0] = ql[1];
                sum_p1 += ql[1];
            } else {
                p2[0] = -ql[1];
                sum_p2 += ql[1];
            }
            if (p1[0] < p2[0]) {
                int k = p2[0];
                p2[0] = p1[0];
                p1[0] = -k;
                sum_p2 += k;
                sum_p1 -= k;
            }
            if (p1[0] - 1 > p2[0]) {
                int k = p1[0];
                p1[0] = p2[0];
                p2[0] = -k;
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
    return 0;
}

