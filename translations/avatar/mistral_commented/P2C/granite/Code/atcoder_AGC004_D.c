
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// Define the structure for the linked list
typedef struct LinkedList {
    Node *head;
} LinkedList;

// Initialize the linked list
LinkedList *initLinkedList() {
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll->head = NULL;
    return ll;
}

// Add a node to the linked list
void addNode(LinkedList *ll, int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (ll->head == NULL) {
        ll->head = node;
    } else {
        Node *cur = ll->head;
        while (cur->next!= NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
}

// Define the depth-first search function 'dfs'
int dfs(LinkedList **links, int n, int k, int v, int p) {
    // Initialize variables for height from leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;

    // Iterate through neighbors of the current node 'v'
    Node *cur = links[v]->head;
    while (cur!= NULL) {
        // Skip if the neighbor is not a valid node (0)
        if (cur->val == 0) {
            cur = cur->next;
            continue;
        }

        // Recursively call the 'dfs' function for the neighbor 'u'
        int hgt, cut;
        hgt = dfs(links, n, k, cur->val, v);
        cut = hgt;

        // Update the height from leaf and cut count
        height_from_leaf = height_from_leaf > hgt? height_from_leaf : hgt;
        cut_count += cut;

        cur = cur->next;
    }

    // Update the height from leaf and cut count for the current node 'v'
    height_from_leaf += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p!= 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }

    // Return the height from leaf and cut count for the current node 'v'
    return cut_count;
}

int main() {
    // Read input from standard input
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize the 'links' list with linked lists for each node
    LinkedList **links = (LinkedList **)malloc(sizeof(LinkedList *) * n);
    for (int i = 0; i < n; i++) {
        links[i] = initLinkedList();
    }

    // Process the input edges and add them to the 'links' list
    for (int i = 1; i < n; i++) {
        int a;
        scanf("%d", &a);
        a--;
        addNode(links[a], i);
    }

    // Call the 'dfs' function with the initial parameters
    int ans = dfs(links, n, k, 0, 0);

    // If the first node is not a root node, add 1 to the answer
    if (1!= 1) {
        ans += 1;
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free the memory allocated for the 'links' list
    for (int i = 0; i < n; i++) {
        Node *cur = links[i]->head;
        while (cur!= NULL) {
            Node *next = cur->next;
            free(cur);
            cur = next;
        }
        free(links[i]);
    }
    free(links);

    return 0;
}

Translate the above C code to Rust and end with comment "