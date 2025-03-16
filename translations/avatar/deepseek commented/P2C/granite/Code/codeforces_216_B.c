
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} IntArray;

IntArray *newIntArray() {
    IntArray *arr = (IntArray *)malloc(sizeof(IntArray));
    arr->arr = (int *)malloc(sizeof(int) * 10);
    arr->size = 0;
    arr->capacity = 10;
    return arr;
}

void deleteIntArray(IntArray *arr) {
    free(arr->arr);
    free(arr);
}

void addInt(IntArray *arr, int x) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (int *)realloc(arr->arr, sizeof(int) * arr->capacity);
    }
    arr->arr[arr->size++] = x;
}

int *readInts(IntArray *arr) {
    int x;
    while (scanf("%d", &x) == 1) {
        addInt(arr, x);
    }
    return arr->arr;
}

void dfs(int **g, int *seen, int i, int *nodes, int *edges) {
    if (seen[i]) {
        return;
    }
    seen[i] = 1;
    (*nodes)++;
    (*edges) += g[i]->size;
    for (int j = 0; j < g[i]->size; j++) {
        dfs(g, seen, g[i]->arr[j], nodes, edges);
    }
}

int solve() {
    int n, m;
    IntArray *line0 = newIntArray();
    if (readInts(line0)!= 2) {
        deleteIntArray(line0);
        return 0;
    }
    n = line0->arr[0];
    m = line0->arr[1];
    int **g = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        g[i] = newIntArray();
    }
    int *seen = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        seen[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        if (readInts(line0)!= 2) {
            deleteIntArray(line0);
            for (int i = 0; i < n; i++) {
                deleteIntArray(g[i]);
            }
            free(g);
            free(seen);
            return 0;
        }
        a = line0->arr[0] - 1;
        b = line0->arr[1] - 1;
        addInt(g[a], b);
        addInt(g[b], a);
    }
    deleteIntArray(line0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            int nodes = 0, edges = 0;
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
    for (int i = 0; i < n; i++) {
        deleteIntArray(g[i]);
    }
    free(g);
    free(seen);
    return 1;
}

int main() {
    while (solve());
    return 0;
}

Translate the above C code to Java and end with comment "