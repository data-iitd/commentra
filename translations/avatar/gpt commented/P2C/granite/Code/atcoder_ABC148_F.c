
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a large prime number for modular arithmetic
#define MOD 100000007

// Define infinity for comparison purposes
#define INF INT_MAX

// Function to read a single integer from input
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from input
int* inpl(int n) {
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = inp();
    }
    return a;
}

// Read the number of nodes and the starting points for ta and ao
int n = inp(), ta = inp() - 1, ao = inp() - 1;

// Initialize the graph as an adjacency list
int** g = (int**)malloc(n * sizeof(int*));
for (int i = 0; i < n; i++) {
    g[i] = (int*)malloc(n * sizeof(int));
}

// Read the edges of the graph and populate the adjacency list
for (int i = 0; i < n - 1; i++) {
    int a = inp() - 1, b = inp() - 1;
    g[a][b] = g[b][a] = 1;  // Set the adjacency matrix
}

// Initialize distance arrays for ta and ao
int* ta_dist = (int*)malloc(n * sizeof(int));
int* ao_dist = (int*)malloc(n * sizeof(int));

// Breadth-first search (BFS) function to calculate distances from ta
void ta_bfs(int s) {
    int* q = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    q[rear++] = s;
    ta_dist[s] = 0;
    while (front < rear) {
        int u = q[front++];
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1 && ta_dist[v] == -1) {
                ta_dist[v] = ta_dist[u] + 1;
                q[rear++] = v;
            }
        }
    }
    free(q);
}

// Breadth-first search (BFS) function to calculate distances from ao
void ao_bfs(int s) {
    int* q = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    q[rear++] = s;
    ao_dist[s] = 0;
    while (front < rear) {
        int u = q[front++];
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 1 && ao_dist[v] == -1) {
                ao_dist[v] = ao_dist[u] + 1;
                q[rear++] = v;
            }
        }
    }
    free(q);
}

// Initialize result variable to track the maximum distance
int res = 0;

// Calculate the maximum distance where ta's distance is less than or equal to ao's distance
for (int i = 0; i < n; i++) {
    if (ta_dist[i] > ao_dist[i]) {
        continue;  // Skip if ta is further away than ao
    }
    res = fmax(res, ao_dist[i]);  // Update result with the maximum distance
}

// Print the result, subtracting 1 to adjust for zero-based indexing
printf("%d\n", res - 1);

