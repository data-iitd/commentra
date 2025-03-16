#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

int main() {
    int D;
    long G;
    int p[100000];
    int c[100000];
    scanf("%d", &D);
    scanf("%ld", &G);
    for (int i = 0; i < D; i++) {
        scanf("%d", &p[i]);
        scanf("%d", &c[i]);
    }
    int min = INT_MAX;
    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0;
        int solve_num = 0;
        for (int i = 0; i < D; i++) {
            if ((bit & (1 << i))!= 0) {
                score += 100 * (i + 1) * p[i] + c[i];
                solve_num += p[i];
            }
        }
        if (score < G) {
            for (int i = D - 1; i >= 0; i--) {
                if ((bit & (1 << i)) == 0) {
                    for (int j = 0; j < p[i] - 1; j++) {
                        score += 100 * (i + 1);
                        solve_num++;
                        if (score >= G) {
                            break;
                        }
                    }
                }
            }
        }
        if (score >= G) {
            min = min < solve_num? min : solve_num;
        }
    }
    printf("%d\n", min);
    return 0;
}

