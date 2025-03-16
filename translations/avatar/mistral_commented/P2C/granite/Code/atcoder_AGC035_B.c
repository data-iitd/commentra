
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure to represent a vertex
typedef struct {
    int id;
    int degree;
    bool visited;
    bool parity;
    struct vertex *next;
} Vertex;

// Function to create a new vertex
Vertex* createVertex(int id) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->id = id;
    v->degree = 0;
    v->visited = false;
    v->parity = false;
    v->next = NULL;
    return v;
}

// Function to add an edge between two vertices
void addEdge(Vertex* u, Vertex* v) {
    Vertex* temp = u;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = v;
    v->degree++;
}

// Function to print the edges of a vertex
void printEdges(Vertex* v) {
    Vertex* temp = v->next;
    while (temp!= NULL) {
        printf("%d %d\n", v->id, temp->id);
        temp->parity =!temp->parity;
        temp = temp->next;
    }
}

// Function to perform a BFS traversal to print the edges of the graph
void bfs(Vertex* vertices, int n) {
    // Create a queue to store the vertices
    Vertex* queue[n];
    int front = 0, rear = 0;
    // Mark all vertices as unvisited
    for (int i = 0; i < n; i++) {
        vertices[i].visited = false;
    }
    // Start BFS from vertex 1
    vertices[0].visited = true;
    queue[rear++] = &vertices[0];
    while (front < rear) {
        Vertex* u = queue[front++];
        printEdges(u);
        for (Vertex* v = u->next; v!= NULL; v = v->next) {
            if (!v->visited) {
                v->visited = true;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Create an array of vertices
    Vertex* vertices = (Vertex*)malloc(n * sizeof(Vertex));
    for (int i = 0; i < n; i++) {
        vertices[i] = *createVertex(i+1);
    }
    // Read edges from input and add them to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&vertices[u-1], &vertices[v-1]);
        addEdge(&vertices[v-1], &vertices[u-1]);
    }
    // Check if number of edges is even, if not print -1 and exit
    if (m % 2!= 0) {
        printf("-1\n");
        return 0;
    }
    // Perform BFS traversal to print the edges of the graph
    bfs(vertices, n);
    return 0;
}
