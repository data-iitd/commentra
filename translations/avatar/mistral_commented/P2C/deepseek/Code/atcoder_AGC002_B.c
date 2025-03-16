#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    int weight;
    int position;
} Ball;

Ball balls[MAX_N];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize list of balls with their weight and position
    for (int i = 0; i < N; i++) {
        balls[i].weight = 1;
        balls[i].position = 0;
    }
    balls[0].weight = 0;
    balls[0].position = 1;

    // Process each event
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        // Get weight and position of balls at x and y
        int w_x = balls[x - 1].weight;
        int r_x = balls[x - 1].position;
        int w_y = balls[y - 1].weight;
        int r_y = balls[y - 1].position;

        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].position += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].position -= 1;
            balls[y - 1].position += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].weight -= 1;
            balls[y - 1].weight += 1;
        }
    }

    // Calculate answer
    int ans = 0;
    // Iterate through the list of balls and count the number of moving balls
    for (int i = 0; i < N; i++) {
        if (balls[i].position) {
            ans += 1;
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}
