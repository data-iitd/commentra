
#include <stdio.h>
#include <stdlib.h>

// Node is a custom data structure for representing a node in the graph.
typedef struct Node {
    int *to;
    int to_len;
} Node;

// main is the entry point of the program.
int main() {
    // Set up the scanner to read words instead of lines.
    // sc.Split(bufio.ScanWords)

    // Read the number of nodes N and edges M from the input.
    int N, M;
    scanf("%d %d", &N, &M);

    // Create a slice n of size N to store the nodes.
    Node *n = (Node *)malloc(N * sizeof(Node));

    // Process each edge by adding it to the to slice of the corresponding nodes.
    for (int i = 0; i < M; i++) {
        // Read the from and to nodes from the input.
        int from, to;
        scanf("%d %d", &from, &to);

        // Add the edge to the to slice of the from node.
        n[from - 1].to = (int *)malloc(sizeof(int));
        n[from - 1].to[0] = to - 1;
        n[from - 1].to_len = 1;

        // Add the edge to the to slice of the to node.
        n[to - 1].to = (int *)malloc(sizeof(int));
        n[to - 1].to[0] = from - 1;
        n[to - 1].to_len = 1;
    }

    // Print the number of neighbors for each node.
    for (int i = 0; i < N; i++) {
        // Print the number of neighbors of the current node.
        printf("%d\n", n[i].to_len);
    }

    // Free the memory allocated for the nodes.
    for (int i = 0; i < N; i++) {
        free(n[i].to);
    }
    free(n);

    return 0;
}

// 