
#include <stdio.h>
#include <math.h>

int main(void) {
    int N, D, i, j, dist, answer = 0;
    scanf("%d %d", &N, &D);
    int vectors[N][D];
    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            scanf("%d", &vectors[i][j]);
        }
    }
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            dist = 0;
            for (int d = 0; d < D; d++) {
                int x = vectors[i][d] - vectors[j][d];
                dist += (x * x);
            }
            double sq = sqrt(dist);
            answer += (fabs(sq - floor(sq)) < 0.001? 1 : 0);
        }
    }
    printf("%d\n", answer);
    return 0;
}

