#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Set the recursion limit to a high value to handle deep recursions if needed
#define RECURSION_LIMIT 1000000000

// Define a constant for infinity
#define INF 1000000000

// Function to read input from standard input
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

// Function to split a string into tokens
char** split(char* line) {
    char** tokens = NULL;
    int count = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (count + 1));
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }
    tokens = realloc(tokens, sizeof(char*) * (count + 1));
    tokens[count] = NULL;
    return tokens;
}

// Function to convert a string to an integer
int toint(char* str) {
    return atoi(str) - 1;
}

// Function to perform BFS
void bfs(int** edge, bool* used, int node, int* ans) {
    // Initialize a queue for BFS
    int* queue = malloc(sizeof(int) * 1000000);
    int front = 0;
    int rear = 0;
    
    // Enqueue the current node
    queue[rear++] = node;
    
    // Perform BFS to mark all reachable nodes from the current node
    while (front < rear) {
        // Dequeue a node
        node = queue[front++];
        
        // Mark the node as visited
        used[node] = true;
        
        // Increment the count of connected components
        (*ans)++;
        
        // Explore all adjacent nodes
        for (int i = 0; i < 1000000; i++) {
            if (edge[node][i] != -1 && !used[edge[node][i]]) {
                // Enqueue the adjacent node
                queue[rear++] = edge[node][i];
            }
        }
    }
    
    // Free the queue
    free(queue);
}

// Function to find connected components
int find_connected_components(int** edge, int N) {
    // Initialize an array to track visited nodes
    bool* used = calloc(N, sizeof(bool));
    
    // Initialize a variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) {  // If the node has not been visited
            bfs(edge, used, i, &ans);  // Perform BFS from the current node
        }
    }
    
    // Free the used array
    free(used);
    
    // Return the number of connected components found
    return ans;
}

// Function to read the input from standard input
int** read_input() {
    // Read the number of nodes (N) and edges (M)
    char* line = input();
    char** tokens = split(line);
    int N = atoi(tokens[0]);
    int M = atoi(tokens[1]);
    
    // Initialize an adjacency list to represent the graph
    int** edge = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        edge[i] = malloc(sizeof(int) * 1000000);
        for (int j = 0; j < 1000000; j++) {
            edge[i][j] = -1;
        }
    }
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        line = input();
        tokens = split(line);
        int X = toint(tokens[0]);
        int Y = toint(tokens[1]);
        int Z = toint(tokens[2]);
        edge[X][Y] = Y;
        edge[Y][X] = X;
    }
    
    // Free the tokens array
    free(tokens);
    
    // Return the adjacency list
    return edge;
}

// Function to free the memory allocated for the adjacency list
void free_edge(int** edge, int N) {
    for (int i = 0; i < N; i++) {
        free(edge[i]);
    }
    free(edge);
}

// Entry point of the program
int main() {
    // Read the input from standard input
    int** edge = read_input();
    int N = atoi(input());
    
    // Find the connected components
    int ans = find_connected_components(edge, N);
    
    // Output the number of connected components found
    printf("%d\n", ans);
    
    // Free the memory allocated for the adjacency list
    free_edge(edge, N);
    
    // End of code
    return 0;
}

