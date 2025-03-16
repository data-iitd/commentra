#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

<<<<<<< HEAD
#define MAX_N 1000
#define INF MAX_N

char S[MAX_N][MAX_N]; // Adjacency matrix representation
int D[MAX_N]; // Distance array
int G[MAX_N][MAX_N]; // Graph for Warshall-Floyd
int N; // Number of vertices

// Function to read a line of input
void NextLine(char *buffer) {
    fgets(buffer, MAX_N, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
=======
#define MAX_N 1000 // Assuming a maximum size for the graph

// Function to read a line of input
char* NextLine() {
    char *line = malloc(1000000);
    if (fgets(line, 1000000, stdin) == NULL) {
        free(line);
        return NULL;
    }
    line[strcspn(line, "\n")] = 0; // Remove newline character
    return line;
>>>>>>> 98c87cb78a (data updated)
}

// Function to read an integer from input
int NextInt() {
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer
    return n;
}

<<<<<<< HEAD
// Function to check if the graph is bipartite
bool Bipartite() {
    memset(D, 0, sizeof(D)); // Initialize distance array
    D[0] = 1; // Start from the first vertex
    int Q[MAX_N]; // Queue for BFS
    int pos = 1; // Position in the queue
    Q[0] = 0; // Start BFS from vertex 0
=======
// Function to check if a graph is bipartite
bool Bipartite(char S[MAX_N][MAX_N], int N) {
    int D[MAX_N] = {0}; // Distance array
    D[0] = 1; // Start from the first vertex
    int Q[MAX_N]; // Queue for BFS
    int pos = 0; // Position in the queue
    Q[pos++] = 0; // Enqueue the first vertex
    bool ret = true; // Return value
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < pos; i++) {
        int q = Q[i];
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue;
            }
            if (D[j] == 0) {
                D[j] = D[q] + 1;
<<<<<<< HEAD
                Q[pos++] = j;
            } else if (D[j] % 2 == D[q] % 2) {
                return false; // Not bipartite
            }
        }
    }
    return true; // Is bipartite
}

// Function to compute the shortest paths between all pairs of vertices
int WarshallFloyd() {
=======
                Q[pos++] = j; // Enqueue the vertex
                continue;
            }
            if (D[j] % 2 == D[q] % 2) {
                ret = false;
                break;
            }
        }
        if (!ret) break;
    }
    return ret;
}

// Function to compute the shortest paths between all pairs of vertices
int WarshallFloyd(char S[MAX_N][MAX_N], int N) {
    int G[MAX_N][MAX_N];
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0; // Distance to self is 0
            } else if (S[i][j] == '0') {
<<<<<<< HEAD
                G[i][j] = INF; // Set distance to a large number
=======
                G[i][j] = N; // Set distance to a large number
>>>>>>> 98c87cb78a (data updated)
            } else {
                G[i][j] = 1; // Direct edge weight
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans < G[i][j]) {
                ans = G[i][j]; // Find the maximum distance
            }
        }
    }
    return ans + 1; // Return the result
}

// Main function to execute the program
int main() {
<<<<<<< HEAD
    N = NextInt();
    for (int i = 0; i < N; i++) {
        NextLine(S[i]); // Read each line of the adjacency matrix
    }

    if (!Bipartite()) {
        printf("-1\n"); // If not bipartite, print -1
    } else {
        printf("%d\n", WarshallFloyd()); // Otherwise, compute and print the result
    }

    return 0; // End of program
}

// <END-OF-CODE>
=======
    int N = NextInt();
    char S[MAX_N][MAX_N];

    for (int i = 0; i < N; i++) {
        char *line = NextLine();
        strcpy(S[i], line);
        free(line);
    }

    if (!Bipartite(S, N)) {
        printf("-1\n"); // If not bipartite, print -1
    } else {
        printf("%d\n", WarshallFloyd(S, N)); // Otherwise, compute and print the result
    }

    return 0;
}
>>>>>>> 98c87cb78a (data updated)
