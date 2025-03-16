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

void enqueue(Queue *q, int y, int x, int depth) {
    q->data[q->rear].y = y;
    q->data[q->rear].x = x;
    q->data[q->rear].depth = depth;
    q->rear++;
}

QueueNode dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int main() {
    int H, W;
    char A[MAX_H][MAX_W];
    Queue q = {.front = 0, .rear = 0};
    int flag[MAX_H][MAX_W] = {0};
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;

    scanf("%d %d", &H, &W);

    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                enqueue(&q, i, j, 0);
            }
        }
    }

    while (!isEmpty(&q)) {
        QueueNode temp = dequeue(&q);
        int y = temp.y;
        int x = temp.x;
        int depth = temp.depth;

        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    enqueue(&q, newY, newX, depth + 1);
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
