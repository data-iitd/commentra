#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int N, M;
int balls[MAX_N][2];

void read_ints(int *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    // Initialize the list of balls with pairs [white pieces, red pieces]
    for (int i = 0; i < N; i++) {
        balls[i][0] = 1;
        balls[i][1] = 0;
    }

    // Special initialization for the first ball
    balls[0][0] = 0;
    balls[0][1] = 1;

    // Loop to process each operation
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--; // Convert to 0-based index

        // Swapping the balls if possible
        if (balls[x][0] >= 1 && balls[x][1] >= 1) {
            balls[x][0]--;
            balls[y][1]++;
        } else if (balls[x][0] == 0) {
            balls[x][1]--;
            balls[y][1]++;
        } else {
            balls[x][0]--;
            balls[y][0]++;
        }
    }

    // Counting the number of balls with at least one red or white piece
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans++;
        }
    }

    // Printing the final count
    printf("%d\n", ans);

    return 0;
}
