
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int balls[N][2] = {{1, 0}};  // Initialize the state of each ball (weight and radius)
    balls[0][0] = 0;  // Set the first ball's state

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;

        int w_x = balls[x][0];
        int r_x = balls[x][1];
        int w_y = balls[y][0];
        int r_y = balls[y][1];

        if (w_x >= 1 && r_x >= 1) {
            balls[x][0]--;
            balls[y][1]++;
        } else if (w_x == 0) {
            balls[x][1]--;
            balls[y][1]++;
        } else {
            balls[x][0]--;
            balls[y][0]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
