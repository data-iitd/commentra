#include <stdio.h> // Include the standard I/O library for input and output operations
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include <stdbool.h> // Include the library for using boolean type
#include <string.h> // Include the library for string manipulation

#define MAX 100000 // Define a constant for the maximum size of the graph

// Declare an adjacency list named G with a maximum size of MAX
int G[MAX][MAX]; // Adjacency list representation
int size[MAX]; // Array to keep track of the size of each adjacency list
bool used[MAX]; // Declare a boolean array named used to keep track of visited vertices
int grundy[MAX]; // Declare an array named grundy to store the Grundy numbers of vertices

void dfs(int v) { // Define a recursive depth-first search function named dfs
    used[v] = true; // Set the visited status of the current vertex to true
    grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
    for (int i = 0; i < size[v]; i++) { // Iterate through all the neighbors of the current vertex
        int w = G[v][i]; // Assign the neighbor to a temporary variable w
        if (!used[w]) { // If the neighbor has not been visited yet
            dfs(w); // Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w] + 1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
        }
    }
}

int main() { // Define the main function
    int N; // Declare an integer variable named N to store the number of vertices
    scanf("%d", &N); // Read the number of vertices from the standard input
    for (int i = 0; i < N - 1; i++) { // Iterate through all the edges except the last one
        int x, y; // Declare two integer variables named x and y to store the endpoints of an edge
        scanf("%d %d", &x, &y); // Read the endpoints of an edge from the standard input
        x--; y--; // Decrease the indices of x and y by 1 to make them zero-indexed
        G[x][size[x]++] = y; // Add an edge from x to y to the adjacency list
        G[y][size[y]++] = x; // Add a reciprocal edge from y to x to the adjacency list
    }
    memset(used, false, sizeof(used)); // Initialize the used array to false
    memset(grundy, 0, sizeof(grundy)); // Initialize the grundy array to 0
    dfs(0); // Call the dfs function starting from vertex 0
    if (grundy[0] != 0) { // Check if the Grundy number of the root vertex is non-zero
        printf("Alice\n"); // If so, print "Alice" to the standard output
    } else { // Otherwise
        printf("Bob\n"); // Print "Bob" to the standard output
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
