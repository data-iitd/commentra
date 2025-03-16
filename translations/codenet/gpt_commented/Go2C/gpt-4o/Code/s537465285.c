#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000
#define INF MAX_N

// Function to read the next line from standard input
char* NextLine() {
    static char buffer[1000000];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}

// Function to read the next integer from standard input
int NextInt() {
    return atoi(NextLine());
}

// Function to check if the graph is bipartite
bool Bipartite(char S[MAX_N][MAX_N], int N) {
    int D[MAX_N] = {0}; // Distance array to store levels of nodes
    D[0] = 1; // Start with the first node at level 1
    int Q[MAX_N]; // Queue for BFS
    int pos = 0; // Position in the queue
    Q[pos++] = 0; // Start BFS from the first node
    bool ret = true; // Variable to track if the graph is bipartite

    // Perform BFS to check for bipartiteness
<<<<<<< HEAD
    for (int i = 0; i < pos; i++) {
        if (!ret) break; // Exit if already determined not bipartite
        int q = Q[i]; // Current node
=======
    while (pos > 0 && ret) {
        int q = Q[--pos]; // Current node
>>>>>>> 98c87cb78a (data updated)
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue; // Skip if there is no edge
            }
            if (D[j] == 0) {
                // Assign level to the adjacent node
                D[j] = D[q] + 1;
                Q[pos++] = j; // Add to queue
                continue;
            }
            // Check if the adjacent node has the same level
            if (D[j] % 2 == D[q] % 2) {
                ret = false; // Not bipartite
                break;
            }
        }
    }
    return ret; // Return the result of bipartiteness check
}

// Function to perform the Floyd-Warshall algorithm to find the longest shortest path
int WarshallFloyd(char S[MAX_N][MAX_N], int N) {
    int G[MAX_N][MAX_N]; // Initialize the graph matrix

    // Initialize the graph with distances
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0; // Distance to self is 0
            } else if (S[i][j] == '0') {
                G[i][j] = INF; // No edge, set to a large value
            } else {
                G[i][j] = 1; // Edge exists, set distance to 1
            }
        }
    }

    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                }
            }
        }
    }

    // Find the maximum distance in the graph
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans < G[i][j] && G[i][j] < INF) {
                ans = G[i][j]; // Update maximum distance
            }
        }
    }
    return ans + 1; // Return the maximum distance found
}

// Main function to execute the program
int main() {
    int N = NextInt(); // Read the number of nodes
    char S[MAX_N][MAX_N]; // Initialize the adjacency matrix
    for (int i = 0; i < N; i++) {
        strcpy(S[i], NextLine()); // Read each line of the adjacency matrix
    }
    
    // Check if the graph is bipartite and process accordingly
    if (!Bipartite(S, N)) {
        printf("-1\n"); // Output -1 if not bipartite
    } else {
        printf("%d\n", WarshallFloyd(S, N)); // Output the longest shortest path if bipartite
    }
    
    return 0; // End of program
}

// <END-OF-CODE>
