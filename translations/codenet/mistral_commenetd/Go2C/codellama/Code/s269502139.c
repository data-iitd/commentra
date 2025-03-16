
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure with key, previous and next pointers
typedef struct node {
    int32_t key;
    struct node *prev;
    struct node *next;
} node;

// Recursive function to print the linked list in reverse order
void rPrint(node *n, char *buf) {
    sprintf(buf, "%d ", n->key);
    if (n->next != NULL) {
        // Recursively call rPrint function for next node
        rPrint(n->next, buf + strlen(buf));
    }
    // Return from the function
    return;
}

// Function to delete a node from the linked list
node *Delete(node *n, node **first, node **last) {
    // Base case: if node is the first and last node
    if (n->prev == NULL && n->next == NULL) {
        *first = NULL;
        *last = NULL;
        return NULL;
    }

    // Base case: if node is the first node
    if (n->prev == NULL) {
        *first = n->next;
        n->next->prev = NULL;
        return *first;
    }

    // Base case: if node is the last node
    if (n->next == NULL) {
        *last = n->prev;
        n->prev->next = NULL;
        return *last;
    }

    // General case: swap the pointers of previous and next nodes
    n->prev->next = n->next;
    n->next->prev = n->prev;
    // Return the first and last nodes after deletion
    return *first;
}

// Initialize a new node with given key
node *initNode(int32_t key) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    return n;
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
    // Initialize standard input scanner
    char cmd[100];
    // Initialize first and last pointers to NULL
    node *first = NULL;
    node *last = NULL;

    // Read the first command from stdin
    scanf("%s", cmd);

    // Process each command until EOF is reached
    while (scanf("%s", cmd) != EOF) {
        // Switch statement to perform the corresponding action based on the command
        switch (cmd[0]) {
        case 'd':
            // Delete the first node from the linked list
            first = Delete(first, &first, &last);
            break;
        case 'i':
            // Create a new node with the given key
            int32_t k;
            sscanf(cmd, "insert %d", &k);
            node *n = initNode(k);
            // Insert the new node at the beginning of the linked list
            n->next = first;
            if (first != NULL) {
                first->prev = n;
            }

            // Update the first and last pointers
            first = n;
            if (last == NULL) {
                last = n;
            }
            break;
        }
    }
    // Print the linked list in reverse order
    char buf[1000];
    rPrint(first, buf);
    // Print the reversed linked list on the console
    printf("%s\n", buf);
    // End of the code
    return 0;
}

