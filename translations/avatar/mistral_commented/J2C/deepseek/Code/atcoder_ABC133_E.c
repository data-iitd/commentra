#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct Node {
    long pattern;
    int index;
    struct Node** children;
    int children_size;
    int parent;
} Node;

Node* create_node(int index) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->pattern = 0;
    node->index = index;
    node->children = NULL;
    node->children_size = 0;
    node->parent = -1;
    return node;
}

void set_parent(int K, int parent, int use, Node* node, Node** nodes) {
    node->pattern = K - use;
    node->parent = parent;
    int count = 1;
    if (parent != -1) {
        count++;
    }
    for (int i = 0; i < node->children_size; i++) {
        int n = node->children[i]->index;
        if (n == node->parent) {
            continue;
        }
        set_parent(K, node->index, count, nodes[n], nodes);
        count++;
    }
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    Node** nodes = (Node**)malloc(N * sizeof(Node*));
    for (int i = 0; i < N; i++) {
        nodes[i] = create_node(i);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        nodes[a]->children_size++;
        nodes[b]->children_size++;
        nodes[a]->children = (Node**)realloc(nodes[a]->children, nodes[a]->children_size * sizeof(Node*));
        nodes[b]->children = (Node**)realloc(nodes[b]->children, nodes[b]->children_size * sizeof(Node*));
        nodes[a]->children[nodes[a]->children_size - 1] = nodes[b];
        nodes[b]->children[nodes[b]->children_size - 1] = nodes[a];
    }

    set_parent(K, -1, 0, nodes[0], nodes);
    long patterns = 1;

    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i]->pattern) % MOD;
    }

    printf("%ld\n", patterns);

    for (int i = 0; i < N; i++) {
        free(nodes[i]->children);
        free(nodes[i]);
    }
    free(nodes);
}

int main() {
    solve();
    return 0;
}

