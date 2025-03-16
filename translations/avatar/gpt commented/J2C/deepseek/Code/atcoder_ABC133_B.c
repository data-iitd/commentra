#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, D;
    scanf("%d %d", &N, &D);

    int vectors[N][D];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            scanf("%d", &vectors[i][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = 0;
            for (int d = 0; d < D; d++) {
                int x = vectors[i][d] - vectors[j][d];
                dist += x * x;
            }
            double sq = sqrt(dist);
            answer += (fabs(sq - floor(sq)) < 1e-3 ? 1 : 0);
        }
    }

    printf("%d\n", answer);
    return 0;
}
