#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000000

// Structure to represent a node in the adjacency list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Depth First Search function
void dfs(Node** links, int n, int k, int v, int p, int* height_from_leaf, int* cut_count) {
    // Initialize height from the leaf node
    *height_from_leaf = 0;
    *cut_count = 0;

    // Iterate through all connected nodes (children) of the current node
    for (Node* u = links[v]; u != NULL; u = u->next) {
        int hgt, cut;
        dfs(links, n, k, u->value, v, &hgt, &cut);
        
        // Update the maximum height from the leaf node
        if (hgt > *height_from_leaf) {
            *height_from_leaf = hgt;
        }
        
        // Accumulate the cut count from the child nodes
        *cut_count += cut;
    }

    // Increment the height from the leaf node as we return to the parent
    (*height_from_leaf)++;

    // Check if the current height matches k and we are not at the root node
    if (p != 0 && *height_from_leaf == k) {
        // Reset height from leaf to 0 and increment cut count
        *height_from_leaf = 0;
        (*cut_count)++;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Create an adjacency list for the graph (tree) connections
    Node** links = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        links[i] = NULL;
    }

    // Read the connections and populate the links
    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        a--; // Adjust for 0-based indexing
        Node* newNode = createNode(i + 1); // i + 1 because we want to connect to the next node
        newNode->next = links[a];
        links[a] = newNode;
    }

    int height_from_leaf, ans = 0;
    dfs(links, n, k, 0, -1, &height_from_leaf, &ans);

    // If the first node is not the root, increment the answer
    if (links[0] != NULL) {
        ans++;
    }

    // Print the final answer (total cuts)
    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Node* current = links[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(links);

    return 0;
}

// <END-OF-CODE>
