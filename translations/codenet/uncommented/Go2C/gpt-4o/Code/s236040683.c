#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *to;
    int size;
    int capacity;
} Node;

void initNode(Node *node) {
    node->size = 0;
    node->capacity = 2; // Initial capacity
    node->to = (int *)malloc(node->capacity * sizeof(int));
}

void addEdge(Node *node, int to) {
    if (node->size >= node->capacity) {
        node->capacity *= 2;
        node->to = (int *)realloc(node->to, node->capacity * sizeof(int));
    }
    node->to[node->size++] = to;
}

void freeNode(Node *node) {
    free(node->to);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    Node *nodes = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        initNode(&nodes[i]);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--; // Convert to 0-based index
        to--;   // Convert to 0-based index
        addEdge(&nodes[from], to);
        addEdge(&nodes[to], from);
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", nodes[i].size);
        freeNode(&nodes[i]);
    }

    free(nodes);
    return 0;
}

// <END-OF-CODE>
