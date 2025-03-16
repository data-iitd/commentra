
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    int bonus;
} problem;

int min(int a, int b) {
    if (a >= b) {
        return b;
    }
    return a;
}

int main() {
    int D, G;
    scanf("%d %d", &D, &G);
    problem *problems = (problem *)malloc(sizeof(problem) * D);
    for (int i = 0; i < D; i++) {
        scanf("%d %d", &problems[i].number, &problems[i].bonus);
    }

    int ans = 10000;
    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0;
        int solved = 0;
        bool ok = false;
        for (int j = 0; j < D; j++) {
            if (bit & (1 << j)) {
                score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
                solved += problems[j].number;
            }
        }
        if (score < G) {
            int j;
            for (j = D - 1; j >= 0; j--) {
                if (!(bit & (1 << j))) {
                    break;
                }
            }
            for (int k = 0; k < problems[j].number; k++) {
                score += (j + 1) * 100;
                solved++;
                if (score >= G) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                score += problems[j].bonus;
                if (score >= G) {
                    ok = true;
                }
            }
        } else {
            ok = true;
        }
        if (ok) {
            ans = min(ans, solved);
        }
    }
    printf("%d\n", ans);

    free(problems);
    return 0;
}
