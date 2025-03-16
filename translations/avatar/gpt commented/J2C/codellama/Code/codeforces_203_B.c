#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, x, y, m;
    scanf("%d %d", &N, &M);
    int **black = (int **)malloc((N + 2) * sizeof(int *));
    for (int i = 0; i < N + 2; i++) {
        black[i] = (int *)malloc((N + 2) * sizeof(int));
    }
    for (m = 1; m <= M; m++) {
        scanf("%d %d", &x, &y);
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (++black[xx][yy] == 9) {
                    printf("%d", m);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
