#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define INF 1000000000
int N, M;
int **edge;
bool *used;
int ans;
void input() {
    char *str = malloc(100 * sizeof(char));
    scanf("%s", str);
    N = atoi(strtok(str, " "));
    M = atoi(strtok(NULL, " "));
    edge = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        edge[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            edge[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        scanf("%s", str);
        int X = atoi(strtok(str, " ")) - 1;
        int Y = atoi(strtok(NULL, " ")) - 1;
        int Z = atoi(strtok(NULL, " ")) - 1;
        edge[X][Y] = 1;
        edge[Y][X] = 1;
    }
    used = malloc(N * sizeof(bool));
    for (int i = 0; i < N; i++) {
        used[i] = false;
    }
    ans = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            int queue[N];
            int front = 0, rear = 0;
            queue[rear++] = i;
            while (front != rear) {
                int node = queue[front++];
                used[node] = true;
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    if (!used[nextnode] && edge[node][nextnode]) {
                        queue[rear++] = nextnode;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}
int main() {
    input();
    return 0;
}



