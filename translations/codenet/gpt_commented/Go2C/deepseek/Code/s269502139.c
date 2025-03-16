#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a doubly linked list node structure
typedef struct Node {
    int key; // The value of the node
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
} Node;

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(Node *n) {
    printf("%d", n->key); // Print the current node's key
    if (n->next != NULL) {
        printf(" "); // Print a space if there is a next node
        rPrint(n->next); // Recursively print the next node
    }
    return;
}

// Method to delete the current node from the linked list
Node* delete(Node *n, Node **first, Node **last) {
    if (n->prev != NULL && n->next != NULL) {
        // Node is in the middle; update pointers of adjacent nodes
        n->prev->next = n->next;
        n->next->prev = n->prev;
        if (*first == n) {
            *first = n->next; // Update first if the node to be deleted is the first node
        }
        if (*last == n) {
            *last = n->prev; // Update last if the node to be deleted is the last node
        }
        free(n); // Free the memory of the deleted node
        return *first; // Return the new first node
    }

    if (n->next == NULL && n->prev == NULL) {
        // Node is the only node in the list
        *first = NULL; // Set first to NULL
        *last = NULL; // Set last to NULL
        free(n); // Free the memory of the node
        return *first; // Return the new first node
    }

    if (n->prev == NULL) {
        // Node is the first node
        *first = n->next; // Update first to the next node
        n->next->prev = NULL; // Set the previous pointer of the new first node to NULL
    }

    if (n->next == NULL) {
        // Node is the last node
        *last = n->prev; // Update last to the previous node
        n->prev->next = NULL; // Set the next pointer of the new last node to NULL
    }

    if (*first == n) {
        *first = NULL; // Update first if the node to be deleted is the first node
    }
    if (*last == n) {
        *last = NULL; // Update last if the node to be deleted is the last node
    }
    free(n); // Free the memory of the deleted node
    return *first; // Return the new first node
}

// Function to initialize a new node with a given key
Node* initNode(int key) {
    Node *n = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    n->key = key; // Set the key of the new node
    n->prev = NULL; // Set the previous pointer to NULL
    n->next = NULL; // Set the next pointer to NULL
    return n; // Return the new node
}

// Main function to execute the program
int main() {
    Node *first = NULL; // Initialize pointer for the first node of the list
    Node *last = NULL; // Initialize pointer for the last node of the list
    char cmd[10]; // Buffer to read commands
    int k; // Variable to store the key for insert and delete commands

    // Loop to process each command from the input
    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "deleteFirst") == 0) {
            // Command to delete the first node
            first = delete(first, &first, &last);
        } else if (strcmp(cmd, "deleteLast") == 0) {
            // Command to delete the last node
            last = delete(last, &first, &last);
        } else {
            // Handle commands that involve inserting or deleting specific keys
            scanf("%d", &k); // Read the key for the insert and delete commands
            if (strcmp(cmd, "delete") == 0) {
                // Command to delete a node with a specific key
                Node *a = first;
                while (a != NULL) {
                    if (a->key == k) {
                        first = delete(a, &first, &last); // Delete the node and update first and last
                        break;
                    }
                    a = a->next;
                }
            } else if (strcmp(cmd, "insert") == 0) {
                // Command to insert a new node at the beginning of the list
                Node *n = initNode(k); // Initialize a new node
                n->next = first; // Set the new node's next pointer to the current first node
                if (first != NULL) {
                    first->prev = n; // Update the previous pointer of the current first node
                }
                first = n; // Update first to the new node
                if (last == NULL) {
                    last = n; // If the list was empty, set last to the new node
                }
            }
        }
    }
    rPrint(first); // Print the keys of the linked list starting from the first node
    printf("\n"); // Print a newline character
    return 0;
}
