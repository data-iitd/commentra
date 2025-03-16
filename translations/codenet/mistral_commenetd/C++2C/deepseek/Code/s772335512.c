#include <stdio.h> // Include the standard input-output library for input and output operations
#include <stdlib.h> // Include the standard library for dynamic memory allocation and other utility functions

#define MAX_VERTICES 100000 // Define a macro named MAX_VERTICES with a value of 100000

int G[MAX_VERTICES][MAX_VERTICES]; // Declare a 2D array named G to store the adjacency matrix
int used[MAX_VERTICES]; // Declare an array named used to keep track of visited vertices
int grundy[MAX_VERTICES]; // Declare an array named grundy to store the Grundy numbers of vertices

void dfs(int v, int N){ // Define a recursive depth-first search function named dfs with an additional parameter for the number of vertices
    used[v] = 1; // Set the visited status of the current vertex to 1
    grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
    for(int i = 0; i < N; i++){ // Iterate through all the vertices
        if(G[v][i] == 1 && !used[i]){ // If there is an edge from v to i and i has not been visited yet
            dfs(i, N); // Recursively call the dfs function for the neighbor i
            grundy[v] ^= (grundy[i]+1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
        }
    }
}

int main(){ // Define the main function
    int N; // Declare an integer variable named N to store the number of vertices
    scanf("%d", &N); // Read the number of vertices from the standard input
    for(int i = 0; i < N-1; i++){ // Iterate through all the edges except the last one
        int x, y; // Declare two integer variables named x and y to store the endpoints of an edge
        scanf("%d %d", &x, &y); // Read the endpoints of an edge from the standard input
        x--; y--; // Decrease the indices of x and y by 1 to make them zero-indexed
        G[x][y] = 1; // Set the adjacency matrix entry for x to y to 1
        G[y][x] = 1; // Set the adjacency matrix entry for y to x to 1
    }
    dfs(0, N); // Call the dfs function starting from vertex 0
    if(grundy[0] != 0){ // Check if the Grundy number of the root vertex is non-zero
        printf("Alice\n"); // If so, print "Alice" to the standard output
    }else{ // Otherwise
        printf("Bob\n"); // Print "Bob" to the standard output
    }
}
