
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main() {
    // Read the height (H) and width (W) of the grid
    int H, W;
    scanf("%d %d", &H, &W);

    // Initialize a 2D character array to store the grid
    char A[H][W];

    // Initialize a queue to perform BFS (Breadth-First Search)
    int queue[H * W][3];
    int front = 0, rear = 0;

    // Read the grid input and populate the character array
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            // If the current cell is a wall ('#'), add its position to the queue
            if (A[i][j] == '#') {
                queue[rear][0] = i;
                queue[rear][1] = j;
                queue[rear][2] = 0;
                rear++;
            }
        }
    }

    // Initialize a flag array to track visited cells
    int flag[H][W];
    memset(flag, 0, sizeof(flag));

    // Variable to store the maximum depth reached
    int ans = 0;

    // Direction vectors for moving up, down, left, and right
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Perform BFS until the queue is empty
    while (front < rear) {
        int y = queue[front][0];
        int x = queue[front][1];
        int depth = queue[front][2];
        front++;

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            // Calculate new coordinates
            int newY = y + dy[i];
            int newX = x + dx[i];

            // Check if the new coordinates are within bounds
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                // Check if the cell has not been visited and is an empty space ('.')
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    queue[rear][0] = newY;
                    queue[rear][1] = newX;
                    queue[rear][2] = depth + 1;
                    rear++;
                    ans = depth + 1;
                }
            }
        }
    }

    // Output the maximum depth reached
    printf("%d\n", ans);

    return 0;
}
