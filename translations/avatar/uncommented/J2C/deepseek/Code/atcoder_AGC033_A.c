#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 100
#define MAX_W 100

typedef struct {
    int y, x, depth;
} Node;

int main() {
    int H, W;
    char A[MAX_H][MAX_W];
    int flag[MAX_H][MAX_W] = {0};
    Node queue[MAX_H * MAX_W];
    int head = 0, tail = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;

    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                Node start = {i, j, 0};
                queue[tail++] = start;
            }
        }
    }

    while (head < tail) {
        Node temp = queue[head++];
        int y = temp.y;
        int x = temp.x;
        int depth = temp.depth;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                if (flag[ny][nx] == 0 && A[ny][nx] == '.') {
                    flag[ny][nx] = 1;
                    Node queue_add = {ny, nx, depth + 1};
                    queue[tail++] = queue_add;
                    ans = depth + 1;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
