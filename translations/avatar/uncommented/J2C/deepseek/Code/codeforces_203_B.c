#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int black[N + 2][N + 2];
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            black[i][j] = 0;
        }
    }
    for (int m = 1; m <= M; m++) {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (++black[xx][yy] == 9) {
                    printf("%d\n", m);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
