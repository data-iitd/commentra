#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure with key, previous and next pointers
typedef struct node {
    int key;
    struct node* prev;
    struct node* next;
} node;

// Recursive function to print the linked list in reverse order
void rPrint(node* n) {
    if (n == NULL) return;
    printf("%d", n->key);
    if (n->next != NULL) {
        printf(" ");
        rPrint(n->next);
    }
}

// Function to delete a node from the linked list
node* Delete(node* n, node** first, node** last) {
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
        n->next->prev = NULL;
        free(n);
        return *first;
    }

    // Base case: if node is the last node
    if (n->next == NULL) {
        *last = n->prev;
        n->prev->next = NULL;
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
node* initNode(int key) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
    // Initialize first and last pointers to NULL
    node* first = NULL;
    node* last = NULL;

    char command[256];

    // Process each command until EOF is reached
    while (fgets(command, sizeof(command), stdin)) {
        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;

        // Switch statement to perform the corresponding action based on the command
        if (strcmp(command, "deleteFirst") == 0) {
            if (first != NULL) {
                first = Delete(first, &first, &last);
            }
        } else if (strcmp(command, "deleteLast") == 0) {
            if (last != NULL) {
                first = Delete(last, &first, &last);
            }
        } else {
            // Split the command into parts using space as delimiter
            char* xcmd = strtok(command, " ");
            if (xcmd != NULL) {
                char* keyStr = strtok(NULL, " ");
                if (keyStr != NULL) {
                    int k = atoi(keyStr);
                    // Switch statement to perform the corresponding action based on the command prefix
                    if (strcmp(xcmd, "delete") == 0) {
                        for (node* a = first; a != NULL; a = a->next) {
                            // If the current node matches the given key, delete it
                            if (a->key == k) {
                                first = Delete(a, &first, &last);
                                break;
                            }
                        }
                    } else if (strcmp(xcmd, "insert") == 0) {
                        // Create a new node with the given key
                        node* n = initNode(k);
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
        }
    }

    // Print the linked list in reverse order
    rPrint(first);
    printf("\n");

    // Free the linked list
    while (first != NULL) {
        node* temp = first;
        first = first->next;
        free(temp);
    }

    return 0;
}

// <END-OF-CODE>
