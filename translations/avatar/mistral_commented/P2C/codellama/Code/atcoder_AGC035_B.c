#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a vertex
typedef struct Vertex {
    int degree;
    int parity;
    bool visited;
    struct Vertex *adjacent[1000];
} Vertex;

// Function to print the edges
void printEdges(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vertices[i].degree; j++) {
            if (vertices[i].parity == 0) {
                printf("%d %d\n", i + 1, vertices[i].adjacent[j]->id + 1);
            } else {
                printf("%d %d\n", vertices[i].adjacent[j]->id + 1, i + 1);
            }
        }
    }
}

// Function to initialize the graph
void initGraph(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i].id = i;
        vertices[i].degree = 0;
        vertices[i].parity = 0;
        vertices[i].visited = false;
    }
}

// Function to add an edge between two vertices
void addEdge(Vertex *vertices, int u, int v) {
    vertices[u].adjacent[vertices[u].degree++] = &vertices[v];
    vertices[v].adjacent[vertices[v].degree++] = &vertices[u];
}

// Function to sort the vertices based on their degrees
void sortVertices(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vertices[i].degree > vertices[j].degree) {
                Vertex temp = vertices[i];
                vertices[i] = vertices[j];
                vertices[j] = temp;
            }
        }
    }
}

// Function to print the edges in the graph
void printGraph(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vertices[i].degree; j++) {
            printf("%d %d\n", vertices[i].id + 1, vertices[i].adjacent[j]->id + 1);
        }
    }
}

// Function to check if the graph is bipartite
bool isBipartite(Vertex *vertices, int n) {
    for (int i = 0; i < n; i++) {
        if (vertices[i].degree % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Function to find the bipartite graph
void findBipartite(Vertex *vertices, int n) {
    // Initialize the graph
    initGraph(vertices, n);

    // Read the edges from input
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(vertices, u - 1, v - 1);
    }

    // Check if the graph is bipartite
    if (!isBipartite(vertices, n)) {
        printf("-1\n");
        return;
    }

    // Sort the vertices based on their degrees
    sortVertices(vertices, n);

    // Print the edges in the graph
    printEdges(vertices, n);
}

int main() {
    // Read the number of vertices and edges from input
    int n, m;
    scanf("%d %d", &n, &m);

    // Create an array of vertices
    Vertex *vertices = (Vertex *)malloc(n * sizeof(Vertex));

    // Find the bipartite graph
    findBipartite(vertices, n);

    // Free the memory allocated to the array of vertices
    free(vertices);

    return 0;
}

