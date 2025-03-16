#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

// Define a structure for the adjacency list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* links[MAX_N];
int n, k;

// Function to add an edge to the adjacency list
void add_edge(int a, int b) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = b;
    new_node->next = links[a];
    links[a] = new_node;
}

// Depth-first search function
void dfs(int v, int p, int* height_from_leaf, int* cut_count) {
    int hgt = 0;
    int cut = 0;
    Node* current = links[v];

    while (current != NULL) {
        int u = current->value;
        current = current->next;

        // Skip if the neighbor is not a valid node (0)
        if (u == 0) {
            continue;
        }

        // Recursively call the 'dfs' function for the neighbor 'u'
        int hgt_u = 0;
        int cut_u = 0;
        dfs(u, v, &hgt_u, &cut_u);

        // Update the height from leaf and cut count
        hgt = (hgt > hgt_u) ? hgt : hgt_u;
        cut += cut_u;
    }

    // Update the height from leaf and cut count for the current node 'v'
    hgt += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p != 0 && hgt == k) {
        hgt = 0;
        cut += 1;
    }

    *height_from_leaf = hgt;
    *cut_count = cut;
}

int main() {
    // Read input
    scanf("%d %d", &n, &k);
    int* aaa = (int*)malloc((n - 1) * sizeof(int));

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &aaa[i]);
        aaa[i]--; // Convert to 0-based index
        add_edge(aaa[i], i + 1); // Add edge from aaa[i] to i + 1
    }

    int height_from_leaf = 0;
    int ans = 0;
    dfs(0, 0, &height_from_leaf, &ans);

    // If the first node is not a root node, add 1 to the answer
    if (aaa[0] != 0) {
        ans += 1;
    }

    // Print the final answer
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
    free(aaa);

    return 0;
}

// <END-OF-CODE>
