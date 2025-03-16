
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long pattern;
    int index;
    int parent;
    int childrenCount;
    int *children;
} Node;

void initNode(Node *node, int i) {
    node->pattern = 0;
    node->index = i;
    node->parent = -1;
    node->childrenCount = 0;
    node->children = NULL;
}

void setParent(Node *node, int K, int parent, int use, Node **nodes) {
    node->pattern = K - use;
    node->parent = parent;
    int count = 1;
    if (parent!= -1) {
        count++;
    }
    for (int i = 0; i < node->childrenCount; i++) {
        if (node->children[i] == node->parent) {
            continue;
        }
        setParent(nodes[node->children[i]], K, node->index, count, nodes);
        count++;
    }
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    Node *nodes = (Node *) malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        initNode(&nodes[i], i);
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[a - 1].children[nodes[a - 1].childrenCount++] = b - 1;
        nodes[b - 1].children[nodes[b - 1].childrenCount++] = a - 1;
    }
    setParent(&nodes[0], K, -1, 0, nodes);
    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 1000000007;
    }
    printf("%ld\n", patterns);
}

int main() {
    solve();
    return 0;
}

