#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a dynamic array (list of neighbors)
typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

// Function to initialize the dynamic array
ArrayList* createArrayList(int capacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->capacity = capacity;
    list->size = 0;
    list->array = (int *)malloc(capacity * sizeof(int));
    return list;
}

// Function to add an element to the dynamic array
void add(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}

// Function to free the dynamic array
void freeArrayList(ArrayList *list) {
    free(list->array);
    free(list);
}

// Global variables
ArrayList **connect; // Array of lists to store neighbors
int *visited;        // Array to track visited nodes
bool *odd;          // Array to track odd components
char *print;        // String to store output
int printSize;      // Size of the output string

// Recursive depth-first search function
void dfs(int crt, int parent) {
    // Mark the current node as visited
    visited[crt] = 1;

    // Iterate through the neighbors of the current node
    for (int i = 0; i < connect[crt]->size; i++) {
        int child = connect[crt]->array[i];

        // Skip the neighbor if it is the parent node or already visited
        if (child == parent || visited[child] == 1) {
            continue;
        }

        // If the neighbor has already been assigned an odd component, add an edge
        // Otherwise, swap the components and continue the traversal
        if (visited[child] == 2) {
            printSize += sprintf(print + printSize, "%d %d\n", crt + 1, child + 1);
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if (odd[child]) {
                printSize += sprintf(print + printSize, "%d %d\n", child + 1, crt + 1);
                odd[child] = !odd[child];
            } else {
                printSize += sprintf(print + printSize, "%d %d\n", crt + 1, child + 1);
                odd[crt] = !odd[crt];
            }
        }
    }

    // Mark the current node as visited with component 2
    visited[crt] = 2;
}

// Main function
int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge); // Read number of nodes and edges

    // Initialize the connect array to store the list of neighbors for each node
    connect = (ArrayList **)malloc(numNode * sizeof(ArrayList *));
    for (int i = 0; i < numNode; i++) {
        connect[i] = createArrayList(2); // Initial capacity of 2
    }

    // Read the edges and add them to the connect array
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        add(connect[a], b); // Add b to a's list of neighbors
        add(connect[b], a); // Add a to b's list of neighbors
    }

    // Check if the number of edges is odd
    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    // Initialize the visited, odd arrays and print buffer
    visited = (int *)malloc(numNode * sizeof(int));
    odd = (bool *)malloc(numNode * sizeof(bool));
    print = (char *)malloc(10000 * sizeof(char)); // Initial buffer size
    printSize = 0;

    // Call the dfs function with the first node and -1 as the parent node
    dfs(0, -1);

    // Print the output
    printf("%s", print);

    // Free allocated memory
    for (int i = 0; i < numNode; i++) {
        freeArrayList(connect[i]);
    }
    free(connect);
    free(visited);
    free(odd);
    free(print);

    return 0;
}

// <END-OF-CODE>
