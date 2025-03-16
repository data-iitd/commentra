#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addEdge(ArrayList *list, int vertex) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = vertex;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}

ArrayList* graph[MAX_N];
int maxMatching;

int maxMatchingFunction(int v, int p, int n) {
    int a = 0;
    int o = 0;

    for (int i = 0; i < graph[v]->size; ++i) {
        int w = graph[v]->data[i];
        if (w == p) continue;

        int r = maxMatchingFunction(w, v, n);
        a += r / 2;
        o += r % 2;
    }

    return 2 * a + (o < 1 ? 0 : 1);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        graph[i] = createArrayList(10);
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        addEdge(graph[a], b);
        addEdge(graph[b], a);
    }

    maxMatching = maxMatchingFunction(0, -1, n) / 2;

    if (2 * maxMatching == n) {
        printf("Second\n");
    } else {
        printf("First\n");
    }

    for (int i = 0; i < n; ++i) {
        freeArrayList(graph[i]);
    }

    return 0;
}

