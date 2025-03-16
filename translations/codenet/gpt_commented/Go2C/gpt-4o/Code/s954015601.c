#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000
#define MAX_EDGES 200000

// Structure to hold edges
typedef struct {
    int a, b;
} Edge;

// Function to generate a unique identifier for an edge
int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a * 100000 + b;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of nodes

    Edge ab[MAX_NODES];
    int edges[MAX_NODES][MAX_NODES];
    int edgeCount[MAX_NODES] = {0}; // To keep track of the number of edges for each node

    // Read edges from input and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to zero-based index
        b--; // Convert to zero-based index
        ab[i].a = a;
        ab[i].b = b;
        edges[a][edgeCount[a]++] = b;
        edges[b][edgeCount[b]++] = a;
    }

    // Map to store colors assigned to edges
<<<<<<< HEAD
    int colors[MAX_NODES * 2] = {0}; // Assuming a maximum of 2 * (N - 1) edges
=======
    int colors[MAX_NODES * 2] = {0}; // Assuming a maximum of 2 edges per node
>>>>>>> 98c87cb78a (data updated)
    int stack[MAX_NODES][3]; // Stack for DFS
    int stackSize = 0;

    // Start DFS from node 0 with no used color and no parent
    stack[stackSize][0] = 0; // currentNode
    stack[stackSize][1] = -1; // usedColor
    stack[stackSize][2] = -1; // parentNode
    stackSize++;

    // Perform DFS to assign colors to edges
    while (stackSize > 0) {
        stackSize--;
        int currentNode = stack[stackSize][0];
        int usedColor = stack[stackSize][1];
        int parentNode = stack[stackSize][2];
        int color = 1; // Start coloring from color 1

        // Iterate through child nodes of the current node
        for (int i = 0; i < edgeCount[currentNode]; i++) {
            int childNode = edges[currentNode][i];
            if (childNode == parentNode) {
                continue; // Skip the parent node to avoid backtracking
            }
            if (color == usedColor) {
                color++; // Skip the color that was used by the parent
            }
            // Assign color to the edge between currentNode and childNode
            colors[genid(currentNode, childNode)] = color;
            // Push the child node onto the stack for further exploration
            stack[stackSize][0] = childNode;
            stack[stackSize][1] = color;
            stack[stackSize][2] = currentNode;
            stackSize++;
            color++; // Move to the next color for the next edge
        }
    }

    // Find the maximum degree of any node in the graph
    int K = -1;
    for (int i = 0; i < N; i++) {
        if (edgeCount[i] > K) {
            K = edgeCount[i]; // Update maximum degree if current node's degree is greater
        }
    }
    printf("%d\n", K); // Print the maximum degree

    // Print the colors assigned to each edge
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i].a, ab[i].b)]);
    }

    return 0;
}

// <END-OF-CODE>
