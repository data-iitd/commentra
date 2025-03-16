
#include <stdio.h>
#include <stdlib.h>

// Define constants for input buffer size
#define IO_BUFFER_SIZE 1048576 // 1 MB

// Define a structure to represent an edge in the graph
typedef struct {
    int a;
    int b;
} Edge;

// Define a structure to represent a node in the graph
typedef struct {
    int id;
    int parent;
    int color;
    int degree;
    int *children;
} Node;

// Function to generate a unique identifier for an edge between two nodes
int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a * 100000 + b;
}

// Function to read a string from standard input
char *readString() {
    char *buffer = (char *)malloc(IO_BUFFER_SIZE);
    fgets(buffer, IO_BUFFER_SIZE, stdin);
    char *result = (char *)malloc(strlen(buffer) + 1);
    strcpy(result, buffer);
    free(buffer);
    return result;
}

// Function to read an integer from standard input and handle any conversion errors
int readInt() {
    char *input = readString();
    int result = atoi(input);
    free(input);
    return result;
}

// Function to perform depth-first search (DFS) to assign colors to edges
void dfs(Node *nodes, int *colors, Edge *ab, int N, int *q, int *q_head, int *q_tail) {
    int currentNode = q[*q_head];
    int usedColor = nodes[currentNode].color;
    int parentNode = nodes[currentNode].parent;
    int color = 1;
    for (int i = 0; i < nodes[currentNode].degree; i++) {
        int childNode = nodes[currentNode].children[i];
        if (childNode == parentNode) {
            continue; // Skip the parent node to avoid backtracking
        }
        if (color == usedColor) {
            color++; // Skip the color that was used by the parent
        }
        colors[genid(nodes[currentNode].id, nodes[childNode].id)] = color;
        q[*q_tail] = childNode;
        (*q_tail)++;
        color++; // Move to the next color for the next edge
    }
    (*q_head)++;
}

int main() {
    // Read the number of nodes in the graph
    int N = readInt();

    // Initialize a slice to hold the edges and an adjacency list for the graph
    Edge *ab = (Edge *)malloc(sizeof(Edge) * (N - 1));
    int **edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * N);
    }

    // Read edges from input and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        ab[i].a = readInt() - 1; // Convert to zero-based index
        ab[i].b = readInt() - 1; // Convert to zero-based index
        edges[ab[i].a][ab[i].b] = 1;
        edges[ab[i].b][ab[i].a] = 1;
    }

    // Map to store colors assigned to edges
    int *colors = (int *)malloc(sizeof(int) * (N - 1));

    // Stack for depth-first search (DFS) with current node, used color, and parent node
    int *q = (int *)malloc(sizeof(int) * N);
    int q_head = 0;
    int q_tail = 0;
    q[q_tail] = 0; // Start DFS from node 0 with no used color and no parent
    q_tail++;

    // Perform DFS to assign colors to edges
    while (q_head < q_tail) {
        dfs(nodes, colors, ab, N, q, &q_head, &q_tail);
    }

    // Find the maximum degree of any node in the graph
    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = 0; // Degree of the current node
        for (int j = 0; j < N; j++) {
            if (edges[i][j] == 1) {
                t++; // Increment the degree if there is an edge to another node
            }
        }
        if (t > K) {
            K = t; // Update maximum degree if current node's degree is greater
        }
    }
    printf("%d\n", K); // Print the maximum degree

    // Print the colors assigned to each edge
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i].a, ab[i].b)]);
    }

    // Free memory
    free(ab);
    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(edges);
    free(colors);
    free(q);

    return 0;
}

