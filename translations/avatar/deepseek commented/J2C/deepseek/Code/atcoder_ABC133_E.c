#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct Node {
    long pattern;
    int index;
    int *children;
    int children_size;
    int parent;
} Node;

void setParent(int K, int parent, int use, Node *nodes, int N) {
    nodes[use].pattern = K - use;
    nodes[use].parent = parent;
    int count = 1;
    if (parent != -1) {
        count++;
    }
    for (int i = 0; i < nodes[use].children_size; i++) {
        int n = nodes[use].children[i];
        if (n == nodes[use].parent) {
            continue;
        }
        setParent(K, use, n, nodes, N);
        count++;
    }
}

void solve(int N, int K) {
    Node *nodes = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children = (int *)malloc(N * sizeof(int));
        nodes[i].children_size = 0;
        nodes[i].parent = -1;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        nodes[a].children[nodes[a].children_size++] = b;
        nodes[b].children[nodes[b].children_size++] = a;
    }
    setParent(K, -1, 0, nodes, N);
    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % MOD;
    }
    printf("%ld\n", patterns);
    for (int i = 0; i < N; i++) {
        free(nodes[i].children);
    }
    free(nodes);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    solve(N, K);
    return 0;
}

