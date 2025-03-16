#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    int weight;
    int radius;
} Ball;

int main() {
    int N, M;
    Ball balls[MAX_N];

    // Read the number of balls (N) and the number of operations (M)
    scanf("%d %d", &N, &M);

    // Initialize the state of each ball
    for (int i = 0; i < N; i++) {
        balls[i].weight = 1;
        balls[i].radius = 0;
    }
    balls[0].weight = 0;
    balls[0].radius = 1;

    // Process each operation
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--; // Convert to 0-based index

        // Update the states of the balls based on their weights and radii
        if (balls[x].weight > 0 && balls[x].radius > 0) {
            balls[x].weight--;
            balls[y].radius++;
        } else if (balls[x].weight == 0) {
            balls[x].radius--;
            balls[y].radius++;
        } else {
            balls[x].weight--;
            balls[y].weight++;
        }
    }

    // Calculate the number of balls with a non-zero radius
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i].radius > 0) {
            ans++;
        }
    }

    // Print the final count of balls with non-zero radius
    printf("%d\n", ans);

    return 0;
}
