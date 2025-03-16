#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *to;
    int size;
    int capacity;
} Node;

<<<<<<< HEAD
void initNode(Node *node) {
    node->size = 0;
    node->capacity = 2; // Initial capacity
    node->to = malloc(node->capacity * sizeof(int));
=======
void out(int x) {
    printf("%d\n", x);
>>>>>>> 98c87cb78a (data updated)
}

void addEdge(Node *node, int to) {
    if (node->size >= node->capacity) {
<<<<<<< HEAD
        node->capacity *= 2;
=======
        node->capacity = node->capacity ? node->capacity * 2 : 1;
>>>>>>> 98c87cb78a (data updated)
        node->to = realloc(node->to, node->capacity * sizeof(int));
    }
    node->to[node->size++] = to;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Node *nodes = malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
<<<<<<< HEAD
        initNode(&nodes[i]);
=======
        nodes[i].to = NULL;
        nodes[i].size = 0;
        nodes[i].capacity = 0;
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
        printf("%d\n", nodes[i].size);
        free(nodes[i].to); // Free the memory allocated for edges
    }

    free(nodes); // Free the memory allocated for nodes
=======
        out(nodes[i].size);
        free(nodes[i].to); // Free the allocated memory for edges
    }

    free(nodes); // Free the nodes array
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
