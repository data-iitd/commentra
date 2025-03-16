#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct Node {
    int val;
    int color;
    struct Node** adj;
    int adj_size;
} Node;

Node* nodes[MAX_NODES];
int n;

void traverse(Node* node, int distance, int* visited, int root_color) {
    if (visited[node->val] == 1) {
        return;
    }
    visited[node->val] = 1;
    if (distance % 2 == 0) {
        node->color = root_color;
    } else {
        node->color = !root_color;
    }
    for (int i = 0; i < node->adj_size; i++) {
        Node* adjNode = node->adj[i];
        traverse(adjNode, distance + 1, visited, root_color);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        nodes[i] = (Node*)malloc(sizeof(Node));
        nodes[i]->val = 0;
        nodes[i]->color = -1;
        nodes[i]->adj = (Node**)malloc(n * sizeof(Node*));
        nodes[i]->adj_size = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Node* node1 = nodes[u - 1];
        Node* node2 = nodes[v - 1];
        node1->adj[node1->adj_size++] = node2;
        node2->adj[node2->adj_size++] = node1;
    }
    int visited[MAX_NODES] = {0};
    int root_color = 1;
    traverse(nodes[0], 0, visited, root_color);
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i]->color);
        free(nodes[i]->adj);
        free(nodes[i]);
    }
    return 0;
}
