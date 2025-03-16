
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long pattern;
    int index;
    int parent;
    int use;
    int count;
    int* children;
} Node;

void setParent(int K, int parent, int use, Node* nodes, int N) {
    nodes[parent].pattern = K - use;
    nodes[parent].parent = -1;
    nodes[parent].count = 1;
    if (parent != -1) {
        nodes[parent].count++;
    }
    for (int i = 0; i < nodes[parent].count; i++) {
        if (nodes[parent].children[i] == parent) {
            continue;
        }
        setParent(K, nodes[parent].children[i], nodes[parent].count, nodes, N);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    Node* nodes = (Node*)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children = (int*)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[a].children[nodes[a].count++] = b;
        nodes[b].children[nodes[b].count++] = a;
    }
    setParent(K, 0, 0, nodes, N);
    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 1000000007;
    }
    printf("%ld\n", patterns);
    return 0;
}

