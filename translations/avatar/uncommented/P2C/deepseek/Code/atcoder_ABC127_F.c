#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q);
    int ans[2] = {0, 0};
    int *p1 = (int *)malloc(q * sizeof(int));
    int *p2 = (int *)malloc(q * sizeof(int));
    int p1_size = 0, p2_size = 0;
    int sum_b = 0, sum_p1 = 0, sum_p2 = 0;

    for (int i = 0; i < q; i++) {
        int ql[3];
        scanf("%d %d %d", &ql[0], &ql[1], &ql[2]);

        if (ql[0] == 2) {
            if (p1_size == p2_size) {
                printf("%d %d\n", -p2[0], sum_p1 - p1_size * (-p2[0]) + p2_size * (-p2[0]) - sum_p2 + sum_b);
            } else {
                printf("%d %d\n", p1[0], sum_p1 - p1_size * p1[0] + p2_size * p1[0] - sum_p2 + sum_b);
            }
        } else {
            sum_b += ql[2];
            if (p1_size == 0) {
                p1[p1_size++] = ql[1];
                sum_p1 += ql[1];
            } else if (p1[0] <= ql[1]) {
                p1[p1_size++] = ql[1];
                sum_p1 += ql[1];
            } else {
                p2[p2_size++] = -ql[1];
                sum_p2 += ql[1];
            }

            if (p1_size < p2_size) {
                int k = p2[0];
                p2[0] = p1[p1_size - 1];
                p1[p1_size - 1] = -k;
                p1_size++;
                p2_size--;
                sum_p2 -= k;
                sum_p1 += k;
            }

            if (p1_size - 1 > p2_size) {
                int k = p1[0];
                p1[0] = -p2[p2_size - 1];
                p2[p2_size - 1] = k;
                p2_size++;
                p1_size--;
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }

    free(p1);
    free(p2);
    return 0;
}
