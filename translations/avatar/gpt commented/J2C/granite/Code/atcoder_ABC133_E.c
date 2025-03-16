
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int index;
    long pattern;
    int parent;
    struct Node **children;
    int children_count;
} Node;

void set_parent(int K, int parent, int use, Node *nodes, int index) {
    nodes[index].pattern = K - use;
    nodes[index].parent = parent;
    int count = 1;
    if (parent!= -1) {
        count++;
    }
    for (int i = 0; i < nodes[index].children_count; i++) {
        if (nodes[index].children[i] == nodes[index].parent) {
            continue;
        }
        set_parent(K, index, count, nodes, nodes[index].children[i]);
        count++;
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    Node *nodes = (Node *)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children = (Node **)malloc(sizeof(Node *) * (N - 1));
        nodes[i].children_count = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        nodes[a].children[nodes[a].children_count] = &nodes[b];
        nodes[a].children_count++;
        nodes[b].children[nodes[b].children_count] = &nodes[a];
        nodes[b].children_count++;
    }
    set_parent(K, -1, 0, nodes, 0);
    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 100000007;
    }
    printf("%ld\n", patterns);
    return 0;
}
