
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} IntArray;

IntArray *IntArrayCreate() {
    IntArray *arr = (IntArray *)malloc(sizeof(IntArray));
    arr->arr = (int *)malloc(sizeof(int) * 10);
    arr->size = 0;
    arr->capacity = 10;
    return arr;
}

void IntArrayPush(IntArray *arr, int val) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (int *)realloc(arr->arr, sizeof(int) * arr->capacity);
    }
    arr->arr[arr->size++] = val;
}

int *readInts() {
    int *arr = (int *)malloc(sizeof(int) * 10);
    int size = 0;
    char *token = NULL;
    char input[1024];
    fgets(input, 1024, stdin);
    char *saveptr = NULL;
    token = strtok(input, " ");
    while (token!= NULL) {
        if (size == 10) {
            arr = (int *)realloc(arr, sizeof(int) * 20);
        }
        arr[size++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

void dfs(int **g, bool *seen, int i, int *nodes, int *edges) {
    if (seen[i]) {
        return;
    }
    seen[i] = true;
    (*nodes)++;
    (*edges) += g[i][0];
    for (int j = 1; j <= g[i][0]; j++) {
        dfs(g, seen, g[i][j], nodes, edges);
    }
}

int solve() {
    int *line0 = readInts();
    int n = line0[0];
    int m = line0[1];
    int **g = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        g[i] = (int *)malloc(sizeof(int) * 10);
        g[i][0] = 0;
    }
    bool *seen = (bool *)malloc(sizeof(bool) * (n + 1));
    for (int i = 1; i <= n; i++) {
        seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int *a = readInts();
        int u = a[0];
        int v = a[1];
        g[u][0]++;
        g[u][g[u][0]] = v;
        g[v][0]++;
        g[v][g[v][0]] = u;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            int nodes = 0;
            int edges = 0;
            dfs(g, seen, i, &nodes, &edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

int main() {
    while (solve()!= EOF) {}
    return 0;
}

End with comment "