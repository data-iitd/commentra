#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100005

// Function to read integers from input
void read_int(int *x) {
    scanf("%d", x);
}

// Function to read long long integers from input
void read_long_long(long long *x) {
    scanf("%lld", x);
}

<<<<<<< HEAD
int N, M; 
int H[MAX_N]; // Array to hold heights
int G[MAX_N][MAX_N]; // Adjacency list for the graph
int degree[MAX_N]; // To keep track of the degree of each node

int main() {
=======
// Main function
int main() {
    int N, M; 
    int H[MAX_N]; // Array to hold heights
    int G[MAX_N][MAX_N]; // Adjacency list for the graph
    int degree[MAX_N] = {0}; // To keep track of the degree of each node

>>>>>>> 98c87cb78a (data updated)
    // Read number of nodes (N) and edges (M)
    read_int(&N);
    read_int(&M);

    // Read heights of each node
    for (int i = 0; i < N; i++) {
        read_int(&H[i]);
<<<<<<< HEAD
        degree[i] = 0; // Initialize degree
=======
>>>>>>> 98c87cb78a (data updated)
    }

    // Read edges and build the graph
    for (int i = 0; i < M; i++) {
        int u, v;
        read_int(&u);
        read_int(&v);
        u--; v--; // Convert to 0-based indexing
        G[u][degree[u]++] = v; // Add edge u-v
        G[v][degree[v]++] = u; // Add edge v-u
    }

    long long ans = 0; // Variable to count the number of nodes that are taller than all their neighbors

    // Iterate through each node to check if it is taller than all its neighbors
    for (int u = 0; u < N; u++) {
        bool flag = true; // Flag to check if the current node is taller
<<<<<<< HEAD
        for (int i = 0; i < degree[u]; i++) {
            int v = G[u][i];
=======
        for (int j = 0; j < degree[u]; j++) {
            int v = G[u][j];
>>>>>>> 98c87cb78a (data updated)
            if (H[u] <= H[v]) {
                flag = false; // If any neighbor is taller or equal, set flag to false
                break; // No need to check further
            }
        }
        if (flag) ans++; // If the flag is still true, increment the answer
    }

    // Output the result
    printf("%lld\n", ans);
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
