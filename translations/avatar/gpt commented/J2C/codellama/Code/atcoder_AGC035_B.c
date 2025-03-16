#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_NODE 100000 
#define MAX_EDGE 100000 

// Structure to represent a graph 
struct Graph { 
    int numNode; 
    int numEdge; 
    int connect[MAX_NODE][MAX_EDGE]; 
    int visited[MAX_NODE]; 
    int odd[MAX_NODE]; 
    char print[MAX_NODE * MAX_NODE]; 
}; 

// Function to perform depth-first search starting from node 0
void dfs(struct Graph *graph, int crt, int parent) { 
    graph->visited[crt] = 1; // Mark the current node as visited
    int crtConnect[MAX_EDGE]; // Get the current node's connections
    memcpy(crtConnect, graph->connect[crt], sizeof(int) * MAX_EDGE); 
    
    // Iterate through each child node connected to the current node
    for (int i = 0; i < MAX_EDGE; i++) { 
        // Skip the parent node and already visited nodes
        if (crtConnect[i] == parent || graph->visited[crtConnect[i]] == 1) { 
            continue; 
        } else if (graph->visited[crtConnect[i]] == 2) { 
            // If the child has been fully processed, append the edge to output
            sprintf(graph->print + strlen(graph->print), "%d %d\n", crt + 1, crtConnect[i] + 1); 
            graph->odd[crt] = !graph->odd[crt]; // Toggle the odd/even state
        } else { 
            // Recursively call DFS on the child node
            dfs(graph, crtConnect[i], crt); 
            
            // Check the odd/even state of the child node after DFS
            if (graph->odd[crtConnect[i]]) { 
                sprintf(graph->print + strlen(graph->print), "%d %d\n", crtConnect[i] + 1, crt + 1); 
                graph->odd[crtConnect[i]] = !graph->odd[crtConnect[i]]; // Toggle the state
            } else { 
                sprintf(graph->print + strlen(graph->print), "%d %d\n", crt + 1, crtConnect[i] + 1); 
                graph->odd[crt] = !graph->odd[crt]; // Toggle the state
            } 
        } 
    } 
    graph->visited[crt] = 2; // Mark the current node as fully processed
} 

// Function to read input and perform DFS
void solve() { 
    // Initialize scanner to read input
    int numNode, numEdge; 
    scanf("%d %d", &numNode, &numEdge); 
    
    // Create an adjacency list to represent the graph
    struct Graph graph; 
    graph.numNode = numNode; 
    graph.numEdge = numEdge; 
    memset(graph.connect, -1, sizeof(int) * MAX_NODE * MAX_EDGE); 
    memset(graph.visited, 0, sizeof(int) * MAX_NODE); 
    memset(graph.odd, 0, sizeof(int) * MAX_NODE); 
    memset(graph.print, 0, sizeof(char) * MAX_NODE * MAX_NODE); 
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < numEdge; i++) { 
        int a, b; 
        scanf("%d %d", &a, &b); 
        graph.connect[a - 1][graph.connect[a - 1][0] + 1] = b - 1; 
        graph.connect[b - 1][graph.connect[b - 1][0] + 1] = a - 1; 
    } 
    
    // Check if the number of edges is odd; if so, output -1 and exit
    if (numEdge % 2 != 0) { 
        printf("-1\n"); 
        return; 
    } 
    
    // Perform depth-first search starting from node 0
    dfs(&graph, 0, -1); 
    
    // Output the result
    printf("%s", graph.print); 
} 

int main() { 
    solve(); 
    return 0; 
} 

