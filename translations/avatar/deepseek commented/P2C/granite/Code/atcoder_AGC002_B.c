
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int balls[N][2] = {{0, 1}};  // Initializing the list of balls with pairs [white pieces, red pieces]
    for (int i = 1; i < N; i++) {
        balls[i][0] = 1;
        balls[i][1] = 0;
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int w_x = balls[x - 1][0];
        int r_x = balls[x - 1][1];
        int w_y = balls[y - 1][0];
        int r_y = balls[y - 1][1];

        if (w_x >= 1 && r_x >= 1) {
            balls[x - 1][0] -= 1;
            balls[y - 1][1] += 1;
        } else if (w_x == 0) {
            balls[x - 1][1] -= 1;
            balls[y - 1][1] += 1;
        } else {
            balls[x - 1][0] -= 1;
            balls[y - 1][0] += 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans += 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
