#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
struct Graph
{
    int V; // Number of vertices
    int E; // Number of edges
    int **adj; // Adjacency list
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    // Create an array of adjacency lists
    graph->adj = (int**) malloc(V * sizeof(int*));

    // Create a list for each vertex and set head node to NULL
    for (int i = 0; i < V; i++)
        graph->adj[i] = (int*) malloc(sizeof(int));

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest. A new node is added to the adjacency list of src. The node is added at the beginning
    graph->adj[src][0] = dest;
}

// Function to perform DFS traversal from a given vertex 'x'
bool dfs(struct Graph* graph, int x)
{
    // Create a stack to store vertices to be traversed
    int* stk = (int*) malloc(graph->V * sizeof(int));
    int top = -1;

    // Create a visited array to keep track of visited vertices
    bool* vis = (bool*) malloc(graph->V * sizeof(bool));

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->V; i++)
        vis[i] = false;

    // Push the current vertex 'x' into the stack with color '1'
    stk[++top] = x;
    vis[x] = true;

    // Traverse the graph until the stack is empty
    while (top != -1)
    {
        // Pop a vertex 'u' from the stack
        int u = stk[top--];

        // If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
        if (vis[u])
        {
            // If the colors of the current vertex 'u' and the previous vertex are different, then return False
            if (vis[u] != 1)
                return false;
            else
                continue;
        }

        // Mark the current vertex 'u' as visited with the current color 'col'
        vis[u] = 1;

        // Recursively traverse all the adjacent vertices of 'u'
        for (int i = 0; i < graph->adj[u][0]; i++)
        {
            int v = graph->adj[u][i + 1];

            // If the current vertex 'v' is not visited yet, then push it into the stack with color '3 - col'
            if (!vis[v])
            {
                stk[++top] = v;
                vis[v] = 3 - vis[u];
            }
        }
    }

    // Return True if all vertices in the connected component have the same color
    return true;
}

// Function to find the number of isolated vertices and connected components
void findComponents(struct Graph* graph)
{
    // Create a visited array to keep track of visited vertices
    bool* vis = (bool*) malloc(graph->V * sizeof(bool));

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->V; i++)
        vis[i] = false;

    // Initialize the number of isolated vertices and connected components
    int ci = 0, cb = 0, cc = 0;

    // Traverse all the vertices
    for (int i = 0; i < graph->V; i++)
    {
        // If the current vertex 'i' is not visited yet
        if (!vis[i])
        {
            // If the current vertex 'i' has no edges, then it is an isolated vertex
            if (graph->adj[i][0] == 0)
                ci++;
            // Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
            else
            {
                if (dfs(graph, i))
                    cb++;
                else
                    cc++;
            }
        }
    }

    // Print the final answer
    printf("%d\n", ci * ci + 2 * ci * (graph->V - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
}

// Driver program to test the above functions
int main()
{
    // Read the number of vertices and edges
    int V, E;
    scanf("%d %d", &V, &E);

    // Create a graph with V vertices and E edges
    struct Graph* graph = createGraph(V, E);

    // Read the edges
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add an edge from u to v
        addEdge(graph, u, v);
    }

    // Find the number of isolated vertices and connected components
    findComponents(graph);

    // Free memory
    free(graph->adj);
    free(graph);

    return 0;
}

