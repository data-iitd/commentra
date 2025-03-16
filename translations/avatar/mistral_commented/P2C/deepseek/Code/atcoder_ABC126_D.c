#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct Node {
    int val;
    int color;
    struct Node** adjacencies;
    int adjacency_count;
} Node;

Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->color = -1; // -1 indicates uncolored
    node->adjacencies = (Node**)malloc(MAX_NODES * sizeof(Node*));
    node->adjacency_count = 0;
    return node;
}

void add_edge(Node* u, Node* v) {
    u->adjacencies[u->adjacency_count] = v;
    u->adjacency_count++;
    v->adjacencies[v->adjacency_count] = u;
    v->adjacency_count++;
}

void traverse(Node* node, int distance, int root_color) {
    if (node->color != -1) {
        return; // Node has already been visited
    }
    node->color = (distance % 2 == 0) ? root_color : !root_color;
    for (int i = 0; i < node->adjacency_count; i++) {
        Node* adj_node = node->adjacencies[i];
        traverse(adj_node, distance + 1, root_color);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node* nodes[MAX_NODES];
    for (int i = 0; i < n; i++) {
        nodes[i] = create_node(i + 1);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(nodes[u - 1], nodes[v - 1]);
    }

    int root_color = 1;
    traverse(nodes[0], 0, root_color);

    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i]->color);
    }

    for (int i = 0; i < n; i++) {
        free(nodes[i]->adjacencies);
        free(nodes[i]);
    }

    return 0;
}
