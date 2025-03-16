#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} List;

void initList(List *list) {
    list->size = 0;
    list->capacity = 10;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

void add(List *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

void dfs(int u, int *d, List *edges) {
    for (int i = 0; i < edges[u].size; i++) {
        int nu = edges[u].data[i];
        if (d[nu] == INT_MAX) {
            d[nu] = d[u] + 1;
            dfs(nu, d, edges);
        }
    }
}

int main() {
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--; v--; // Convert to 0-based index

    List edges[MAX_N];
    for (int i = 0; i < N; i++) {
        initList(&edges[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based index
        add(&edges[a], b);
        add(&edges[b], a);
    }

    int d[MAX_N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    dfs(u, d, edges);

    int e[MAX_N];
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v] = 0;
    dfs(v, e, edges);

    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(edges[i].data);
    }

    return 0;
}

// <END-OF-CODE>
