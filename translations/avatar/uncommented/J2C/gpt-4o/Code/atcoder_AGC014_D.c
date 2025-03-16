#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList g[MAX_N];

void initArrayList(ArrayList *list) {
    list->size = 0;
    list->capacity = 10;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

void add(ArrayList *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int maxMatching(int v, int p) {
    int a = 0, o = 0;
    for (int i = 0; i < g[v].size; i++) {
        int w = g[v].data[i];
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + (o < 1 ? o : 1) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        initArrayList(&g[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based index
        add(&g[a], b);
        add(&g[b], a);
    }

    int m = maxMatching(0, -1) / 2;
    printf("%s\n", (2 * m == n) ? "Second" : "First");

    for (int i = 0; i < n; i++) {
        free(g[i].data);
    }

    return 0;
}

// <END-OF-CODE>
