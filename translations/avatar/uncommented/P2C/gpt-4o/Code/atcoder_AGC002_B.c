#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int balls[MAX_N][2]; // balls[i][0] = weight, balls[i][1] = red
    for (int i = 0; i < N; i++) {
        balls[i][0] = 1; // weight
        balls[i][1] = 0; // red
    }
    balls[0][0] = 0; // first ball weight
    balls[0][1] = 1; // first ball red

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; // Convert to 0-based index
        y--; // Convert to 0-based index

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

// <END-OF-CODE>
