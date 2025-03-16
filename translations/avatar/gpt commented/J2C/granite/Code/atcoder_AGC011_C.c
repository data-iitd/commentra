
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->array = (int*)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(ArrayList* list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity);
    }
    list->array[list->size++] = value;
}

void dfs(ArrayList** graph, bool* visited, int* color, int node, int c) {
    if (visited[node]) {
        if (color[node] >= 0 && color[node]!= c) mujun = true;
        return;
    }
    visited[node] = true;
    color[node] = c;
    int total = 1;
    for (int i = 0; i < graph[node]->size; i++) {
        int adjacent = graph[node]->array[i];
        total += dfs(graph, visited, color, adjacent, 1 - c);
    }
    return total;
}

int main() {
    Scanner scan = new Scanner(System.in); 
    int n = scan.nextInt(); 
    int m = scan.nextInt(); 

    ArrayList** graph = (ArrayList**)malloc(sizeof(ArrayList*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = createArrayList(n);
    }

    for (int i = 0; i < m; i++) {
        int u = scan.nextInt() - 1; 
        int v = scan.nextInt() - 1; 
        add(graph[u], v); 
        add(graph[v], u); 
    }

    bool* visited = (bool*)malloc(sizeof(bool) * n);
    memset(visited, false, sizeof(bool) * n);

    int* color = (int*)malloc(sizeof(int) * n);
    memset(color, -1, sizeof(int) * n);

    long one = 0; 
    long bipartite = 0; 
    long count = 0; 

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue; 
        count++; 
        mujun = false; 
        int kind = dfs(graph, visited, color, i, 0); 
        if (kind == 1) one++; 
        else if (!mujun) bipartite++; 
    }

    long total = one * (2 * n - one); 
    total += (count - one) * (count - one); 
    total += bipartite * bipartite; 

    printf("%ld\n", total); 

    return 0;
}

