#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF 1000000000
int N, M;
int **edge;
int *used;
int ans;
void input() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    sscanf(line, "%d %d", &N, &M);
    free(line);
    edge = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edge[i] = (int *)malloc(N * sizeof(int));
        memset(edge[i], 0, N * sizeof(int));
    }
    for (int i = 0; i < M; i++) {
        read = getline(&line, &len, stdin);
        int X, Y, Z;
        sscanf(line, "%d %d %d", &X, &Y, &Z);
        edge[X - 1][Y - 1] = edge[Y - 1][X - 1] = 1;
        free(line);
    }
    used = (int *)malloc(N * sizeof(int));
    memset(used, 0, N * sizeof(int));
    ans = 0;
}
void BFS(int node) {
    int queue[N];
    int front = 0, rear = 0;
    queue[rear++] = node;
    while (front < rear) {
        node = queue[front++];
        used[node] = 1;
        for (int i = 0; i < N; i++) {
            if (edge[node][i] && !used[i]) {
                queue[rear++] = i;
            }
        }
    }
}
void main() {
    input();
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            BFS(i);
        }
    }
    printf("%d\n", ans);
}
