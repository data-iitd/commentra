#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_COLOR 100000

// Function to generate unique id based on two integers
int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Multiply the larger number by 100000 and add the smaller number
    return a * 100000 + b;
}

// Structure to represent an edge
typedef struct {
    int to;
    struct Edge* next;
} Edge;

// Structure to represent a graph
typedef struct {
    Edge* head;
} Graph;

// Function to add an edge to the graph
void addEdge(Graph* graph, int from, int to) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = to;
    edge->next = graph[from].head;
    graph[from].head = edge;
}

// Function to read an integer from standard input
int readInt() {
    int result;
    scanf("%d", &result);
    return result;
}

// Main function
int main() {
    // Read the number of edges in the graph
    int N = readInt();

    // Initialize an adjacency list and a 2D array to store the edges between nodes
    int ab[MAX_N - 1][2];
    Graph graph[MAX_N] = {0};

    for (int i = 0; i < N - 1; i++) {
        // Read two integers representing the nodes connected by an edge
        int a = readInt() - 1;
        int b = readInt() - 1;
        // Store the nodes in the ab array
        ab[i][0] = a;
        ab[i][1] = b;
        // Add the edge to the adjacency list
        addEdge(graph, a, b);
        addEdge(graph, b, a);
    }

    // Initialize an array to store the colors of each connected component
    int colors[MAX_N] = {0};
    // Initialize a stack for DFS
    int stack[MAX_N][3];
    int stackSize = 0;

    // Add the first node to the stack with initial color and parent node set to -1
    stack[stackSize][0] = 0; // currentNode
    stack[stackSize][1] = -1; // usedColor
    stack[stackSize][2] = -1; // parentNode
    stackSize++;

    while (stackSize > 0) {
        // Pop the current node, its color, and its parent node
        stackSize--;
        int currentNode = stack[stackSize][0];
        int usedColor = stack[stackSize][1];
        int parentNode = stack[stackSize][2];

        // Set the color of the current node to the next available color
        int color = 1;
        for (Edge* childEdge = graph[currentNode].head; childEdge != NULL; childEdge = childEdge->next) {
            int childNode = childEdge->to;
            if (childNode == parentNode) {
                continue;
            }
            // If the color of the current node is the same as the color of the child node, increment the color
            if (color == usedColor) {
                color++;
            }
            // Assign the color to the child node
            colors[genid(currentNode, childNode)] = color;
            // Push the child node onto the stack with the current node as its parent node
            stack[stackSize][0] = childNode;
            stack[stackSize][1] = color;
            stack[stackSize][2] = currentNode;
            stackSize++;
            // Increment the color for the next iteration
            color++;
        }
    }

    // Initialize a variable to store the maximum number of edges in a connected component
    int K = -1;
    // Iterate through all nodes in the graph and update the maximum number of edges if necessary
    for (int i = 0; i < N; i++) {
        int t = 0;
        for (Edge* edge = graph[i].head; edge != NULL; edge = edge->next) {
            t++;
        }
        if (t > K) {
            K = t;
        }
    }
    // Print the maximum number of edges in a connected component
    printf("%d\n", K);

    // Iterate through all edges in the graph and print their colors
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    return 0;
}

// <END-OF-CODE>
