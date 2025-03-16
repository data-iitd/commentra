
#include <iostream> // Include the iostream library for input and output operations
#include <vector> // Include the vector library for creating dynamic arrays

using namespace std; // Use the standard namespace for easier access to library functions

vector<int> G[100000]; // Declare an adjacency list named G with a maximum size of 100000
bool used[100000]; // Declare a boolean array named used to keep track of visited vertices
int grundy[100000]; // Declare an array named grundy to store the Grundy numbers of vertices

void dfs(int v){ // Define a recursive depth-first search function named dfs
    used[v] = true; // Set the visited status of the current vertex to true
    grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
    for(int i = 0; i < G[v].size(); i++){ // Iterate through all the neighbors of the current vertex
        int w = G[v][i]; // Assign the neighbor to a temporary variable w
        if(!used[w]){ // If the neighbor has not been visited yet
            dfs(w); // Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w]+1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
        }
    }
}

int main(){ // Define the main function
    int N; // Declare an integer variable named N to store the number of vertices
    cin >> N; // Read the number of vertices from the standard input
    for(int i = 0; i < N-1; i++){ // Iterate through all the edges except the last one
        int x, y; // Declare two integer variables named x and y to store the endpoints of an edge
        cin >> x >> y; // Read the endpoints of an edge from the standard input
        x--; y--; // Decrease the indices of x and y by 1 to make them zero-indexed
        G[x].push_back(y); // Add an edge from x to y to the adjacency list
        G[y].push_back(x); // Add a reciprocal edge from y to x to the adjacency list
    }
    dfs(0); // Call the dfs function starting from vertex 0
    if(grundy[0] != 0){ // Check if the Grundy number of the root vertex is non-zero
        cout << "Alice" << endl; // If so, print "Alice" to the standard output
    }else{ // Otherwise
        cout << "Bob" << endl; // Print "Bob" to the standard output
    }
}