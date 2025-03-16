

#include <stdio.h>
#include <stdlib.h>

// Define a Node struct
typedef struct Node {
    int val;
    int color;
    struct Node **adjacencies;
    int num_adjacencies;
} Node;

// Initialize the root node
Node *init_root() {
    Node *root = (Node *)malloc(sizeof(Node));
    root->val = 0;
    root->color = 1;
    root->adjacencies = NULL;
    root->num_adjacencies = 0;
    return root;
}

// Read input and initialize nodes
Node **init_nodes(int n) {
    Node **nodes = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->val = i;
        nodes[i]->color = 0;
        nodes[i]->adjacencies = NULL;
        nodes[i]->num_adjacencies = 0;
    }
    return nodes;
}

// Read edges and add adjacencies to nodes
void add_edge(Node **nodes, int u, int v, int w) {
    Node *node_u = nodes[u];
    Node *node_v = nodes[v];
    node_u->adjacencies = (Node **)realloc(node_u->adjacencies, (node_u->num_adjacencies + 1) * sizeof(Node *));
    node_u->adjacencies[node_u->num_adjacencies] = node_v;
    node_u->num_adjacencies++;
    node_v->adjacencies = (Node **)realloc(node_v->adjacencies, (node_v->num_adjacencies + 1) * sizeof(Node *));
    node_v->adjacencies[node_v->num_adjacencies] = node_u;
    node_v->num_adjacencies++;
}

// Traverse the graph and color nodes based on their distance from the root
void traverse(Node *node, int distance) {
    if (node->color!= 0) {
        return;
    }
    node->color = distance % 2 == 0? 1 : 2;
    for (int i = 0; i < node->num_adjacencies; i++) {
        traverse(node->adjacencies[i], distance + 1);
    }
}

// Print the color of each node
void print_colors(Node **nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i]->color);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node **nodes = init_nodes(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(nodes, u - 1, v - 1, w);
    }
    Node *root = init_root();
    traverse(root, 0);
    print_colors(nodes, n);
    return 0;
}
