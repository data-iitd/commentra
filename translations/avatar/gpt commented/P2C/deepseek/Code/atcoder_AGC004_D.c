#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Define a structure for the adjacency list
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

// Function to add an edge to the graph
void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to perform DFS and count the cuts
int dfs(Node* adjList[], int n, int k, int v, int p) {
    // Initialize height from the leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;
    
    // Iterate through all connected nodes (children) of the current node
    Node* u = adjList[v];
    while (u != NULL) {
        // Skip if the child node is 0 (indicating no further connections)
        if (u->value == 0) {
            u = u->next;
            continue;
        }
        
        // Recursively perform DFS on the child node and get its height and cut count
        int hgt = dfs(adjList, n, k, u->value, v);
        
        // Update the maximum height from the leaf node
        height_from_leaf = (height_from_leaf > hgt) ? height_from_leaf : hgt;
        
        // Accumulate the cut count from the child nodes
        cut_count += cut_count;
        
        u = u->next;
    }
    
    // Increment the height from the leaf node as we return to the parent
    height_from_leaf += 1;
    
    // Check if the current height matches k and we are not at the root node
    if (p != 0 && height_from_leaf == k) {
        // Reset height from leaf to 0 and increment cut count
        height_from_leaf = 0;
        cut_count += 1;
    }
    
    // Return the height from the leaf and the total cut count
    return height_from_leaf;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Create an array of adjacency lists
    Node* adjList[MAX_N];
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    
    // Read the connections and populate the adjacency list
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;  // Adjust for 0-based indexing
        addEdge(adjList, a[i], i);
    }
    
    // Perform DFS starting from the root node (0) and get the total cuts
    int ans = dfs(adjList, n, k, 0, 0);
    
    // If the first node is not the root, increment the answer
    if (a[0] != -1) {
        ans += 1;
    }
    
    // Print the final answer (total cuts)
    printf("%d\n", ans);
    
    return 0;
}
