#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 100
#define MAX_W 100

int main() {
    int H, W;
    char A[MAX_H][MAX_W];
    int flag[MAX_H][MAX_W];
    int queue[MAX_H * MAX_W][3];
    int head = 0, tail = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;

    // Read the number of rows and columns from the input
    scanf("%d %d", &H, &W);

    // Initialize the flag array to mark the visited cells
    memset(flag, 0, sizeof(flag));

    // Read the grid and initialize the queue with the starting points of '#'
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &A[i][j]);
            if (A[i][j] == '#') {
                queue[tail][0] = i;
                queue[tail][1] = j;
                queue[tail][2] = 0;
                tail++;
            }
        }
    }

    // Process the queue and find the answer
    while (head < tail) {
        int y = queue[head][0];
        int x = queue[head][1];
        int depth = queue[head][2];
        head++;

        // Process the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            // If the cell is within the grid and hasn't been visited yet,
            // and contains a '.', mark it as visited and add it to the queue
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    queue[tail][0] = newY;
                    queue[tail][1] = newX;
                    queue[tail][2] = depth + 1;
                    tail++;
                    ans = ans > depth + 1 ? ans : depth + 1;
                }
            }
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}
