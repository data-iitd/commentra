#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000
<<<<<<< HEAD
=======
#define MAX_EDGES 200000
>>>>>>> 98c87cb78a (data updated)

// Function to generate a unique identifier for an edge between two nodes.
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
    scanf("%d", &N);

    // Initialize arrays to store edges and an adjacency list for the graph.
    int ab[MAX_NODES][2];
    int edges[MAX_NODES][MAX_NODES];
<<<<<<< HEAD
    int edgeCount[MAX_NODES] = {0}; // To keep track of the number of edges for each node.
=======
    int edgeCount[MAX_NODES] = {0}; // To keep track of the number of edges for each node
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        ab[i][0] = a;
        ab[i][1] = b;
        edges[a][edgeCount[a]++] = b;
        edges[b][edgeCount[b]++] = a;
    }

    // Initialize an array to store the color of each edge.
<<<<<<< HEAD
    int colors[MAX_NODES * 2] = {0}; // Assuming a maximum of 2 edges per node for simplicity.
    int stack[MAX_NODES * 3]; // Stack for DFS traversal
    int stackSize = 0;

    // Push the initial node onto the stack.
=======
    int colors[MAX_NODES * 2] = {0}; // Assuming at most 2 edges per node
    int stack[MAX_NODES * 3]; // Stack for DFS traversal
    int stackSize = 0;

    // Push the initial node onto the stack
>>>>>>> 98c87cb78a (data updated)
    stack[stackSize++] = 0; // currentNode
    stack[stackSize++] = -1; // usedColor
    stack[stackSize++] = -1; // parentNode

    while (stackSize > 0) {
        // Pop the last element from the stack for DFS traversal.
        int parentNode = stack[--stackSize];
        int usedColor = stack[--stackSize];
        int currentNode = stack[--stackSize];

        int color = 1;
        for (int i = 0; i < edgeCount[currentNode]; i++) {
            int childNode = edges[currentNode][i];
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            colors[genid(currentNode, childNode)] = color;
<<<<<<< HEAD
            stack[stackSize++] = childNode; // Push childNode
            stack[stackSize++] = color; // Push color
            stack[stackSize++] = currentNode; // Push currentNode as parent
=======
            stack[stackSize++] = childNode; // childNode
            stack[stackSize++] = color; // usedColor
            stack[stackSize++] = currentNode; // parentNode
>>>>>>> 98c87cb78a (data updated)
            color++;
        }
    }

    // Determine the maximum degree of any node in the graph.
    int K = -1;
    for (int i = 0; i < N; i++) {
        if (edgeCount[i] > K) {
            K = edgeCount[i];
        }
    }
    printf("%d\n", K);

    // Output the colors of the edges.
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    return 0;
}

// <END-OF-CODE>
