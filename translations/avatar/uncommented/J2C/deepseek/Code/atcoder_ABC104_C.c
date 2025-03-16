#include <stdio.h>
#include <stdlib.h>

#define INF 100000

int main() {
    int D, G, i;
    int p[30], c[30];
    int min = INF;

    scanf("%d %ld", &D, &G);
    for (i = 0; i < D; i++) {
        scanf("%d %d", &p[i], &c[i]);
    }

    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0;
        int solve_num = 0;
        for (i = 0; i < D; i++) {
            if (bit & (1 << i)) {
                score += 100 * (i + 1) * p[i] + c[i];
                solve_num += p[i];
            }
        }
        if (score < G) {
            for (i = D - 1; i >= 0; i--) {
                if (!(bit & (1 << i))) {
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
            min = score < min ? score : min;
        }
    }
    printf("%d\n", min);
    return 0;
}
