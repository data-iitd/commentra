
#include <stdio.h> // Include the standard input/output library
#include <stdbool.h> // Include the boolean library
#include <stdlib.h> // Include the standard library

#define MAX_SIZE 100000 // Define a macro named MAX_SIZE with a value of 100000

typedef struct{ // Define a structure named Edge
    int to; // Declare an integer variable named to to store the endpoint of an edge
    struct Edge *next; // Declare a pointer to an Edge structure named next to store the next edge
}Edge;

typedef struct{ // Define a structure named Vertex
    int grundy; // Declare an integer variable named grundy to store the Grundy number of a vertex
    bool used; // Declare a boolean variable named used to keep track of visited vertices
    struct Edge *edges; // Declare a pointer to an Edge structure named edges to store the edges of a vertex
}Vertex;

void dfs(Vertex *v){ // Define a recursive depth-first search function named dfs
    v->used = true; // Set the visited status of the current vertex to true
    v->grundy = 0; // Initialize the Grundy number of the current vertex to 0
    for(Edge *e = v->edges; e != NULL; e = e->next){ // Iterate through all the edges of the current vertex
        Vertex *w = e->to; // Assign the neighbor to a temporary variable w
        if(!w->used){ // If the neighbor has not been visited yet
            dfs(w); // Recursively call the dfs function for the neighbor
            v->grundy ^= (w->grundy+1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
        }
    }
}

int main(){ // Define the main function
    int N; // Declare an integer variable named N to store the number of vertices
    scanf("%d", &N); // Read the number of vertices from the standard input
    Vertex *G = (Vertex*)malloc(N*sizeof(Vertex)); // Allocate memory for an array of Vertex structures named G with a size of N
    for(int i = 0; i < N-1; i++){ // Iterate through all the edges except the last one
        int x, y; // Declare two integer variables named x and y to store the endpoints of an edge
        scanf("%d %d", &x, &y); // Read the endpoints of an edge from the standard input
        x--; y--; // Decrease the indices of x and y by 1 to make them zero-indexed
        Edge *e = (Edge*)malloc(sizeof(Edge)); // Allocate memory for an Edge structure named e
        e->to = &G[y]; // Set the endpoint of the edge to the y-th vertex
        e->next = G[x].edges; // Set the next edge of the x-th vertex to the current edge
        G[x].edges = e; // Set the edges of the x-th vertex to the current edge
        e = (Edge*)malloc(sizeof(Edge)); // Allocate memory for an Edge structure named e
        e->to = &G[x]; // Set the endpoint of the edge to the x-th vertex
        e->next = G[y].edges; // Set the next edge of the y-th vertex to the current edge
        G[y].edges = e; // Set the edges of the y-th vertex to the current edge
    }
    dfs(&G[0]); // Call the dfs function starting from vertex 0
    if(G[0].grundy != 0){ // Check if the Grundy number of the root vertex is non-zero
        printf("Alice\n"); // If so, print "Alice" to the standard output
    }else{ // Otherwise
        printf("Bob\n"); // Print "Bob" to the standard output
    }
    free(G); // Free the memory allocated for the array of Vertex structures named G
    return 0; // Return 0 to indicate successful execution
}

