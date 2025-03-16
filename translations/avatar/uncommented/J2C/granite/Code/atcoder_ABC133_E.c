
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node {
    long pattern;
    int index;
    struct Node **children;
    int parent;
} Node;

void setParent(int K, int parent, int use, Node *nodes, int index) {
    nodes[index].pattern = K - use;
    nodes[index].parent = parent;
    int count = 1;
    if (parent!= -1) {
        count++;
    }
    for (int i = 0; i < nodes[index].children->size; i++) {
        if (nodes[index].children->data[i] == nodes[index].parent) {
            continue;
        }
        setParent(K, nodes[index].index, count, nodes, nodes[index].children->data[i]);
        count++;
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    Node *nodes = (Node *)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children = (struct Node **)malloc(sizeof(struct Node *) * (N - 1));
        nodes[i].children->size = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        nodes[a].children->data[nodes[a].children->size] = b;
        nodes[a].children->size++;
        nodes[b].children->data[nodes[b].children->size] = a;
        nodes[b].children->size++;
    }
    setParent(K, -1, 0, nodes, 0);
    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 100000000;
    }
    printf("%ld\n", patterns);
    return 0;
}

