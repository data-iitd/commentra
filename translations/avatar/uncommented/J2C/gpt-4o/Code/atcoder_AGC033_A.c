#include <stdio.h>
#include <stdlib.h>

#define MAX_H 1000
#define MAX_W 1000

typedef struct {
    int y;
    int x;
    int depth;
} Node;

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    
    char A[MAX_H][MAX_W];
    int flag[MAX_H][MAX_W] = {0};
    Node queue[MAX_H * MAX_W];
    int front = 0, rear = 0;
    
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                queue[rear++] = (Node){i, j, 0};
            }
        }
    }
    
    int ans = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while (front < rear) {
        Node temp = queue[front++];
        int y = temp.y;
        int x = temp.x;
        int depth = temp.depth;
        
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    queue[rear++] = (Node){newY, newX, depth + 1};
                    ans = depth + 1;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}

/* <END-OF-CODE> */
