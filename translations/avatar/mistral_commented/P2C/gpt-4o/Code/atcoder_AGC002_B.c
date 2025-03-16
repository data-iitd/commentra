#include <stdio.h>
#include <stdlib.h>

#define INF 1e9
#define MOD 1000000007

// Function to read integers from input
void read_ints(int *a, int *b) {
    scanf("%d %d", a, b);
}

int main() {
    int N, M;
    read_ints(&N, &M);

    // Initialize array of balls with their weight and position
    int balls[N][2];
    for (int i = 0; i < N; i++) {
        balls[i][0] = 1; // weight
        balls[i][1] = 0; // position
    }
    balls[0][0] = 0; // weight of the first ball
    balls[0][1] = 1; // position of the first ball

    // Process each event
    for (int i = 0; i < M; i++) {
        int x, y;
        read_ints(&x, &y);
        x--; // Convert to 0-based index
        y--; // Convert to 0-based index

        int w_x = balls[x][0];
        int r_x = balls[x][1];
        int w_y = balls[y][0];
        int r_y = balls[y][1];

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x][0]--;
            balls[y][1]++;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x][1]--;
            balls[y][1]++;
        } else {
            // Ball x is moving and collides with ball y
            balls[x][0]--;
            balls[y][0]++;
        }
    }

    // Calculate answer
    int ans = 0;
    // Iterate through the list of balls and count the number of moving balls
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans++;
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
