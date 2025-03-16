
#include <stdio.h>
#include <stdlib.h>

int main() {
    int q;
    scanf("%d", &q);
    int ans[2] = {0, 0};
    int *p1 = (int *)malloc(sizeof(int) * q);
    int *p2 = (int *)malloc(sizeof(int) * q);
    int p1_len = 0, p2_len = 0;
    long long sum_b = 0, sum_p1 = 0, sum_p2 = 0;

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 2) {
            if (p1_len == p2_len) {
                printf("%d %lld\n", p2[0], sum_p1 - p1_len * p2[0] + p2_len * p2[0] - sum_p2 + sum_b);
            } else {
                printf("%d %lld\n", p1[0], sum_p1 - p1_len * p1[0] + p2_len * p1[0] - sum_p2 + sum_b);
            }
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            sum_b += b;
            if (p1_len == 0) {
                p1[p1_len++] = a;
                sum_p1 += a;
            } else if (p1[0] <= a) {
                p1[p1_len++] = a;
                sum_p1 += a;
            } else {
                p2[p2_len++] = -a;
                sum_p2 -= a;
            }
            if (p1_len < p2_len) {
                int k = -p2[--p2_len];
                p1[p1_len++] = k;
                sum_p2 += k;
                sum_p1 -= k;
            }
            if (p1_len - 1 > p2_len) {
                int k = p1[--p1_len];
                p2[p2_len++] = -k;
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }

    free(p1);
    free(p2);

    return 0;
}
