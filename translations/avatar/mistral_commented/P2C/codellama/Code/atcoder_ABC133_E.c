#######
# Include necessary headers
#######
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#######
# Define necessary constants
#######
#define MAX_NODES 100000
#define MAX_COLORS 100000
#define MOD 1000000007

#######
# Define a struct to represent a graph
#######
typedef struct {
    int *neighbors;
    int numNeighbors;
} Graph;

#######
# Define a struct to represent a color
#######
typedef struct {
    int color;
    int numNeighbors;
} Color;

#######
# Define a function to calculate the answer
#######
int dfs(int fro, int to, int f, Graph *graph, Color *colors) {
    """
    Calculate the answer using Depth First Search.

    Parameters:
    fro (int): The current node.
    to (int): The target node.
    f (int): The current color.
    graph (Graph *): The graph.
    colors (Color *): The colors.

    Returns:
    int: The number of ways to color the graph.
    """

    // Initialize case number and color number
    int caseNum = 1;
    int colorNum = f == MAX_COLORS ? 0 : MAX_COLORS - 1;

    // Iterate through the neighbors of the current node
    for (int i = 0; i < graph[fro].numNeighbors; i++) {
        // Skip the target node
        if (graph[fro].neighbors[i] == to) {
            continue;
        }

        // Recursively call dfs on the neighbor and update case number
        int pat = dfs(graph[fro].neighbors[i], fro, colorNum, graph, colors);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;
        colorNum--;
    }

    // Return the final case number
    return caseNum;
}

#######
# Define a function to read input
#######
void readInput(int *N, int *K, Graph *graph) {
    // Read number of nodes and color limit
    scanf("%d %d", N, K);

    // Read edges between nodes and add them to the graph
    for (int i = 0; i < *N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1].neighbors = realloc(graph[a - 1].neighbors, (graph[a - 1].numNeighbors + 1) * sizeof(int));
        graph[a - 1].neighbors[graph[a - 1].numNeighbors++] = b - 1;
        graph[b - 1].neighbors = realloc(graph[b - 1].neighbors, (graph[b - 1].numNeighbors + 1) * sizeof(int));
        graph[b - 1].neighbors[graph[b - 1].numNeighbors++] = a - 1;
    }
}

#######
# Define a function to print the answer
#######
void printAnswer(int ans) {
    // Print the answer
    printf("%d\n", ans);
}

#######
# Define main function
#######
int main() {
    // Initialize graph and colors
    Graph graph[MAX_NODES];
    Color colors[MAX_NODES];

    // Read input
    int N, K;
    readInput(&N, &K, graph);

    // Call dfs function with initial values and print the result
    int ans = dfs(0, -1, K, graph, colors);
    printAnswer(ans);

    // End with comment "