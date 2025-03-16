#include <stdio.h>
#include <math.h>

#define INF 100000

int main() {
    int D;
    long long G;
    int p[30];
    int c[30];

    scanf("%d %lld", &D, &G);
    for (int i = 0; i < D; i++) {
        scanf("%d %d", &p[i], &c[i]);
    }

    int min = INF;

    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0;
        int solve_num = 0;

        for (int i = 0; i < D; i++) {
            if (bit & (1 << i)) {
                score += 100 * (i + 1) * p[i] + c[i];
                solve_num += p[i];
            }
        }

        if (score < G) {
            for (int i = D - 1; i >= 0; i--) {
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
            min = fmin(min, solve_num);
        }
    }

    printf("%d\n", min);
    return 0;
}
