

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    char A[H][W];
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
    }

    int queue[H * W][3];
    int front = 0, rear = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                queue[rear][0] = i;
                queue[rear][1] = j;
                queue[rear][2] = 0;
                rear++;
            }
        }
    }

    int flag[H][W];
    memset(flag, 0, sizeof(flag));

    int ans = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (front < rear) {
        int y = queue[front][0];
        int x = queue[front][1];
        int depth = queue[front][2];
        front++;

        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (0 <= newY && newY < H && 0 <= newX && newX < W && flag[newY][newX] == 0 && A[newY][newX] == '.') {
                flag[newY][newX] = 1;
                queue[rear][0] = newY;
                queue[rear][1] = newX;
                queue[rear][2] = depth + 1;
                rear++;
                ans = depth + 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

