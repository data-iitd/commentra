
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char A[H][W];
    int queue[H * W][3];
    int head = 0, tail = 0;
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                queue[tail][0] = i;
                queue[tail][1] = j;
                queue[tail][2] = 0;
                tail++;
            }
        }
    }
    int flag[H][W];
    memset(flag, 0, sizeof(flag));
    int ans = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (head < tail) {
        int y = queue[head][0];
        int x = queue[head][1];
        int depth = queue[head][2];
        head++;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < H && 0 <= nx && nx < W && flag[ny][nx] == 0 && A[ny][nx] == '.') {
                flag[ny][nx] = 1;
                queue[tail][0] = ny;
                queue[tail][1] = nx;
                queue[tail][2] = depth + 1;
                tail++;
                ans = depth + 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
//END-OF-CODE