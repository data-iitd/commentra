#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define long long type for convenience
typedef long long ll;

// Direction vectors for 4 possible movements (right, down, left, up)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// Define constants for maximum vertices and modulo value
#define MAX_V 100001
#define MOD 1000000007

// Define a type for a graph represented as an adjacency list
typedef struct {
    int n;
    int *edges;
} Graph;

// Read the number of vertices (or nodes)
int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Read n-1 edges and count the occurrences for each vertex
void read_edges(Graph *g) {
    for (int i = 0; i < g->n - 1; i++) {
        int a;
        scanf("%d", &a);
        a--;
        g->edges[a]++;
    }
}

// Output the count of edges for each vertex
void print_edges(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d\n", g->edges[i]);
    }
}

int main() {
    // Read the number of vertices (or nodes)
    int n = read_int();

    // Initialize a vector to store the count of edges for each vertex
    Graph g = {n, (int *) malloc(n * sizeof(int))};

    // Read n-1 edges and count the occurrences for each vertex
    read_edges(&g);

    // Output the count of edges for each vertex
    print_edges(&g);
}

