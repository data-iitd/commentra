#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000
#define INF MAX_N

// Function to read a single line from standard input
char* NextLine() {
    static char buffer[MAX_N];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}

// Function to read an integer from standard input
int NextInt() {
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character
    return n;
}

// Function to check if a given graph is bipartite
bool Bipartite(char S[MAX_N][MAX_N], int N) {
    int D[MAX_N] = {0}; // Degree array
    D[0] = 1; // Start with the first vertex

    int Q[MAX_N]; // Queue for BFS
    int pos = 1; // Position in queue
    Q[0] = 0; // Start from the first vertex

    bool ret = true; // Result

    // Iterate over each vertex
    for (int i = 0; i < N && ret; i++) {
        int q = Q[i];

        // Iterate over each neighbor of the current vertex
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue;
            }

            // If neighbor is not visited yet
            if (D[j] == 0) {
                // Mark neighbor as visited
                D[j] = D[q] + 1;

                // Add neighbor to queue
                Q[pos++] = j;
                continue;
            }

            // If degrees of current and neighbor are different
            if (D[j] % 2 != D[q] % 2) {
                // Graph is not bipartite
                ret = false;
                break;
            }
        }
    }

    // Return result
    return ret;
}

// Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
int WarshallFloyd(char S[MAX_N][MAX_N], int N) {
    int G[MAX_N][MAX_N];

    // Initialize adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0;
            } else if (S[i][j] == '0') {
                G[i][j] = INF;
            } else {
                G[i][j] = 1;
            }
        }
    }

    // Iterate over all vertices k
    for (int k = 0; k < N; k++) {
        // Iterate over all vertices i
        for (int i = 0; i < N; i++) {
            // Iterate over all vertices j
            for (int j = 0; j < N; j++) {
                // Update shortest distance if found
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }

    // Initialize answer as maximum distance
    int ans = 0;

    // Iterate over all vertices i
    for (int i = 0; i < N; i++) {
        // Iterate over all vertices j
        for (int j = 0; j < N; j++) {
            // Update answer if found
            if (ans < G[i][j] && G[i][j] < INF) {
                ans = G[i][j];
            }
        }
    }

    // Return answer plus one
    return ans + 1;
}

// Main function
int main() {
    // Read number of vertices
    int N = NextInt();

    // Initialize graph
    char S[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        strcpy(S[i], NextLine());
    }

    // Check if graph is bipartite
    if (!Bipartite(S, N)) {
        // Write -1 if graph is not bipartite
        printf("-1\n");
    } else {
        // Write shortest distance between all pairs of vertices
        printf("%d\n", WarshallFloyd(S, N));
    }

    return 0;
}

// <END-OF-CODE>
