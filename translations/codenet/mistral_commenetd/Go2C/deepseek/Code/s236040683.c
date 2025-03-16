#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a string from standard input
char* getString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Structure to represent a node in the graph
typedef struct Node {
    int *to;
    int to_size;
} Node;

// Function to print output
void out(int x, ...) {
    printf("%d\n", x);
}

int main() {
    // Read the number of nodes N and edges M
    int N = getInt();
    int M = getInt();

    // Create an array of Node structures
    Node *n = (Node*)malloc(N * sizeof(Node));

    // Initialize each node's to array
    for (int i = 0; i < N; i++) {
        n[i].to = (int*)malloc(N * sizeof(int));
        n[i].to_size = 0;
    }

    // Process each edge
    for (int i = 0; i < M; i++) {
        // Read the from and to nodes
        int from = getInt() - 1;
        int to = getInt() - 1;

        // Add the edge to the to array of the from node
        n[from].to[n[from].to_size++] = to;

        // Add the edge to the to array of the to node
        n[to].to[n[to].to_size++] = from;
    }

    // Print the number of neighbors for each node
    for (int i = 0; i < N; i++) {
        // Print the number of neighbors of the current node
        out(n[i].to_size);

        // Free the dynamically allocated memory for each node's to array
        free(n[i].to);
    }

    // Free the dynamically allocated memory for the array of nodes
    free(n);

    return 0;
}
