

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100000

// Maximum number of edges in the graph
#define MAX_EDGES 200000

// Structure to represent a graph
typedef struct {
    int v; // Number of vertices in the graph
    int e; // Number of edges in the graph
    int *adj; // Adjacency list to store the graph
    int *color; // Array to store the color of each vertex (0 for white, 1 for gray, 2 for black)
    int *parent; // Array to store the parent of each vertex in the breadth-first search
    int *dist; // Array to store the distance of each vertex from the source vertex in the breadth-first search
} Graph;

// Function to create a new graph
Graph *newGraph(int v, int e) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->v = v;
    g->e = e;
    g->adj = (int *)malloc(sizeof(int) * v);
    g->color = (int *)malloc(sizeof(int) * v);
    g->parent = (int *)malloc(sizeof(int) * v);
    g->dist = (int *)malloc(sizeof(int) * v);
    return g;
}

// Function to add an edge to the graph
void addEdge(Graph *g, int u, int v) {
    g->adj[u]++;
    g->adj[v]++;
}

// Function to perform breadth-first search on the graph
void bfs(Graph *g, int s) {
    // Initialize the color and parent arrays
    memset(g->color, 0, sizeof(int) * g->v);
    memset(g->parent, -1, sizeof(int) * g->v);

    // Initialize the queue and enqueue the source vertex
    int *queue = (int *)malloc(sizeof(int) * g->v);
    int front = 0, rear = 0;
    queue[rear++] = s;
    g->color[s] = 1;

    // Perform breadth-first search
    while (front < rear) {
        int u = queue[front++];
        for (int i = 0; i < g->adj[u]; i++) {
            int v = g->adj[u + 1 + i];
            if (g->color[v] == 0) {
                g->color[v] = 1;
                g->parent[v] = u;
                queue[rear++] = v;
            }
        }
        g->color[u] = 2;
    }

    // Free the queue
    free(queue);
}

// Function to find the maximum matching in the graph
int maxMatching(Graph *g) {
    int matching = 0;
    for (int u = 0; u < g->v; u++) {
        if (g->color[u] == 0) {
            bfs(g, u);
            for (int v = 0; v < g->v; v++) {
                if (g->color[v] == 2 && g->parent[v]!= -1) {
                    matching++;
                }
            }
        }
    }
    return matching;
}

int main() {
    // Read the number of vertices and edges in the graph
    int v, e;
    scanf("%d %d", &v, &e);

    // Create a new graph
    Graph *g = newGraph(v, e);

    // Read the edges and add them to the graph
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u - 1, v - 1);
    }

    // Find the maximum matching in the graph
    int matching = maxMatching(g);

    // Print the result based on whether all vertices have even degree or not
    if (matching == v) {
        printf("Second\n");
    } else {
        printf("First\n");
    }

    // Free the memory allocated for the graph
    free(g->adj);
    free(g->color);
    free(g->parent);
    free(g->dist);
    free(g);

    return 0;
}

