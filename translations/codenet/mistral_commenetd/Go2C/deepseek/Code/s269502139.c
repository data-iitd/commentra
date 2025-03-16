#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure with key, previous and next pointers
typedef struct Node {
    int key;
    struct Node *prev;
    struct Node *next;
} Node;

// Recursive function to print the linked list in reverse order
void rPrint(Node *n) {
    printf("%d", n->key);
    if (n->next != NULL) {
        printf(" ");
        rPrint(n->next);
    }
    return;
}

// Function to delete a node from the linked list
Node* delete(Node *n, Node **first, Node **last) {
    // Base case: if node is the first and last node
    if (n->prev == NULL && n->next == NULL) {
        *first = NULL;
        *last = NULL;
        free(n);
        return NULL;
    }

    // Base case: if node is the first node
    if (n->prev == NULL) {
        *first = n->next;
        if (*first != NULL) {
            (*first)->prev = NULL;
        }
        free(n);
        return *first;
    }

    // Base case: if node is the last node
    if (n->next == NULL) {
        *last = n->prev;
        (*last)->next = NULL;
        free(n);
        return *first;
    }

    // General case: swap the pointers of previous and next nodes
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    return *first;
}

// Initialize a new node with given key
Node* initNode(int key) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
    Node *first = NULL;
    Node *last = NULL;
    char cmd[10];
    int k;

    // Read commands from stdin until EOF is reached
    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "deleteFirst") == 0) {
            // Delete the first node from the linked list
            first = delete(first, &first, &last);
        } else if (strcmp(cmd, "deleteLast") == 0) {
            // Delete the last node from the linked list
            last = delete(last, &first, &last);
        } else {
            // Split the command into parts using space as delimiter
            scanf("%d", &k);
            // Convert the key to int32 type
            int k32 = k;
            // Switch statement to perform the corresponding action based on the command prefix
            if (strcmp(cmd, "delete") == 0) {
                // Search for the node with the given key in the linked list
                Node *a = first;
                while (a != NULL) {
                    // If the current node matches the given key, delete it
                    if (a->key == k32) {
                        first = delete(a, &first, &last);
                        break;
                    }
                    a = a->next;
                }
            } else if (strcmp(cmd, "insert") == 0) {
                // Create a new node with the given key
                Node *n = initNode(k32);
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
            }
        }
    }
    // Print the linked list in reverse order
    rPrint(first);
    // Print a newline character to separate the output
    printf("\n");
    // End of the code
    return 0;
}
