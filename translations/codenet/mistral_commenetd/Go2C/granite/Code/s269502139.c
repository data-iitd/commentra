
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
    if (n == NULL) {
        return;
    }
    sprintf(buf, "%d", n->key);
    if (n->next!= NULL) {
        // Recursively call rPrint function for next node
        strcat(buf, " ");
        rPrint(n->next, buf);
    }
}

// Function to delete a node from the linked list
void deleteNode(node *n, node **first, node **last) {
    if (n == NULL) {
        return;
    }
    if (n->prev == NULL && n->next == NULL) {
        *first = NULL;
        *last = NULL;
        return;
    }
    if (n->prev == NULL) {
        *first = n->next;
        n->next->prev = NULL;
        return;
    }
    if (n->next == NULL) {
        *last = n->prev;
        n->prev->next = NULL;
        return;
    }
    // General case: swap the pointers of previous and next nodes
    n->prev->next = n->next;
    n->next->prev = n->prev;
}

// Initialize a new node with given key
node *initNode(int32_t key) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int main() {
    // Initialize first and last pointers to NULL
    node *first = NULL;
    node *last = NULL;

    char buf[1024];
    char cmd[1024];
    int32_t k;

    // Read the first command from stdin
    fgets(cmd, sizeof(cmd), stdin);

    // Process each command until EOF is reached
    while (fgets(cmd, sizeof(cmd), stdin)) {
        // Split the command into parts using space as delimiter
        char *xcmd = strtok(cmd, " ");
        // Parse the key from the second part of the command
        sscanf(xcmd, "%d", &k);

        // Switch statement to perform the corresponding action based on the command
        if (strcmp(cmd, "deleteFirst\n") == 0) {
            // Delete the first node from the linked list
            deleteNode(first, &first, &last);
        } else if (strcmp(cmd, "deleteLast\n") == 0) {
            // Delete the last node from the linked list
            deleteNode(last, &first, &last);
        } else {
            // Convert the key to int32 type
            int32_t k32 = k;
            // Switch statement to perform the corresponding action based on the command prefix
            if (strcmp(xcmd, "delete") == 0) {
                // Search for the node with the given key in the linked list
                node *a = first;
                while (a!= NULL) {
                    // If the current node matches the given key, delete it
                    if (a->key == k32) {
                        deleteNode(a, &first, &last);
                        break;
                    }
                    a = a->next;
                }
            } else if (strcmp(xcmd, "insert") == 0) {
                // Create a new node with the given key
                node *n = initNode(k32);
                // Insert the new node at the beginning of the linked list
                n->next = first;
                if (first!= NULL) {
                    first->prev = n;
                }
                // Update the first and last pointers
                first = n;
                if (last == NULL) {
                    last = n;
                }
            }
        }
    }
    // Print the linked list in reverse order
    rPrint(first, buf);
    // Print the reversed linked list on the console
    printf("%s\n", buf);
    // End of the code
}
