#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 100
#define MAX_W 100

typedef struct {
    int y, x, depth;
} QueueNode;

typedef struct {
    QueueNode data[MAX_H * MAX_W];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, QueueNode node) {
    q->data[q->rear++] = node;
}

QueueNode dequeue(Queue *q) {
    return q->data[q->front++];
}

int main() {
    int H, W;
    char A[MAX_H][MAX_W];
    Queue q;
    initQueue(&q);
    
    scanf("%d %d", &H, &W);
    
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                QueueNode start = {i, j, 0};
                enqueue(&q, start);
            }
        }
    }
    
    int flag[MAX_H][MAX_W] = {0};
    int ans = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while (!isEmpty(&q)) {
        QueueNode temp = dequeue(&q);
        int y = temp.y;
        int x = temp.x;
        int depth = temp.depth;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                if (flag[ny][nx] == 0 && A[ny][nx] == '.') {
                    flag[ny][nx] = 1;
                    QueueNode queue_add = {ny, nx, depth + 1};
                    enqueue(&q, queue_add);
                    if (depth + 1 > ans) {
                        ans = depth + 1;
                    }
                }
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
