
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long pattern;
    int index;
    int *children;
    int parent;
    int children_size;
} Node;

void setParent(int K, int parent, int use, Node *nodes, int N) {
    nodes[parent].pattern = K - use;
    nodes[parent].parent = -1;
    int count = 1;
    if (parent != -1) {
        count++;
    }
    for (int i = 0; i < nodes[parent].children_size; i++) {
        if (nodes[parent].children[i] == parent) {
            continue;
        }
        setParent(K, nodes[parent].children[i], count, nodes, N);
        count++;
    }
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    Node *nodes = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children = (int *)malloc(N * sizeof(int));
        nodes[i].children_size = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[a - 1].children[nodes[a - 1].children_size++] = b - 1;
        nodes[b - 1].children[nodes[b - 1].children_size++] = a - 1;
    }

    setParent(K, 0, 0, nodes, N);

    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 1000000007;
    }

    printf("%ld\n", patterns);

    for (int i = 0; i < N; i++) {
        free(nodes[i].children);
    }
    free(nodes);
}

int main() {
    solve();
    return 0;
}

