

#include <stdio.h> // Include the standard input/output library for input and output operations
#include <stdlib.h> // Include the standard library for dynamic memory allocation

#define MAXN 100000 // Define a constant MAXN to represent the maximum number of vertices

int G[MAXN][MAXN]; // Declare a 2D array named G to store the adjacency matrix
int used[MAXN]; // Declare an integer array named used to keep track of visited vertices
int grundy[MAXN]; // Declare an integer array named grundy to store the Grundy numbers of vertices

void dfs(int v){ // Define a recursive depth-first search function named dfs
    used[v] = 1; // Set the visited status of the current vertex to true
    grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
    for(int i = 0; i < MAXN; i++){ // Iterate through all the neighbors of the current vertex
        int w = G[v][i]; // Assign the neighbor to a temporary variable w
        if(w!= 0 && used[w] == 0){ // If the neighbor has not been visited yet
            dfs(w); // Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w]+1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
        }
    }
}

int main(){ // Define the main function
    int N; // Declare an integer variable named N to store the number of vertices
    scanf("%d", &N); // Read the number of vertices from the standard input
    for(int i = 0; i < N-1; i++){ // Iterate through all the edges except the last one
        int x, y; // Declare two integer variables named x and y to store the endpoints of an edge
        scanf("%d %d", &x, &y); // Read the endpoints of an edge from the standard input
        G[x][y] = 1; // Set the adjacency matrix entry from x to y to 1
        G[y][x] = 1; // Set the reciprocal adjacency matrix entry from y to x to 1
    }
    dfs(1); // Call the dfs function starting from vertex 1
    if(grundy[1]!= 0){ // Check if the Grundy number of the root vertex is non-zero
        printf("Alice\n"); // If so, print "Alice" to the standard output
    }else{ // Otherwise
        printf("Bob\n"); // Print "Bob" to the standard output
    }
    return 0; // Return 0 to indicate successful execution of the program
}

