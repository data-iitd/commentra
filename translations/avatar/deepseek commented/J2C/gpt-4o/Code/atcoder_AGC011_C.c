#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

typedef struct {
    ArrayList *graph;
    bool *visited;
    int *color;
    long one;
    long bipartite;
    long count;
    bool mujun;
} Main;

void initArrayList(ArrayList *list, int capacity) {
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

void addToArrayList(ArrayList *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
}

int dfs(Main *main, int a, int c) {
    if (main->visited[a]) {
        if (main->color[a] >= 0 && main->color[a] != c) {
            main->mujun = true;
        }
        return 0;
    }
    main->visited[a] = true;
    main->color[a] = c;
    int total = 1;
    for (int i = 0; i < main->graph[a].size; i++) {
        total += dfs(main, main->graph[a].data[i], 1 - c);
    }
    return total;
}

void run() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Main main;
    main.graph = (ArrayList *)malloc(n * sizeof(ArrayList));
    for (int i = 0; i < n; ++i) {
        initArrayList(&main.graph[i], 2);
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; // Convert to 0-based index
        addToArrayList(&main.graph[u], v);
        addToArrayList(&main.graph[v], u);
    }
    
    main.visited = (bool *)calloc(n, sizeof(bool));
    main.color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        main.color[i] = -1;
    }
    
    main.one = 0;
    main.bipartite = 0;
    main.count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (main.visited[i]) continue;
        main.count++;
        main.mujun = false;
        int kind = dfs(&main, i, 0);
        if (kind == 1) {
            main.one++;
        } else if (!main.mujun) {
            main.bipartite++;
        }
    }
    
    long total = main.one * (2 * n - main.one);
    total += (main.count - main.one) * (main.count - main.one);
    total += main.bipartite * main.bipartite;
    
    printf("%ld\n", total);
    
    for (int i = 0; i < n; ++i) {
        freeArrayList(&main.graph[i]);
    }
    free(main.graph);
    free(main.visited);
    free(main.color);
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
