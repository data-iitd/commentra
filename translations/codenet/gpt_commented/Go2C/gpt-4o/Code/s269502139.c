#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a doubly linked list node structure
typedef struct node {
    int32_t key;          // The value of the node
    struct node* prev;    // Pointer to the previous node
    struct node* next;    // Pointer to the next node
} node;

// Function to recursively print the keys of the linked list starting from the current node
void rPrint(node* n) {
<<<<<<< HEAD
    if (n != NULL) {
        printf("%d", n->key); // Print the current node's key
        if (n->next != NULL) {
            printf(" "); // Add a space if there is a next node
        }
=======
    if (n == NULL) return;
    printf("%d", n->key); // Print the current node's key
    if (n->next != NULL) {
        printf(" "); // Add a space if there is a next node
>>>>>>> 98c87cb78a (data updated)
        rPrint(n->next); // Recursively print the next node
    }
}

// Function to delete the current node from the linked list
node* Delete(node* n, node** first, node** last) {
    if (n->prev != NULL && n->next != NULL) {
        // Node is in the middle; update pointers of adjacent nodes
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return *first; // Return unchanged first pointer
    }

    if (n->next == NULL && n->prev == NULL) {
        // Node is the only node in the list
        *first = NULL;
        *last = NULL;
        free(n);
        return NULL; // Return NULL for both first and last
    }

    if (n->prev == NULL) {
        // Node is the first node
        *first = n->next; // Update first to the next node
        if (n->next != NULL) {
            n->next->prev = NULL; // Set the previous pointer of the new first node to NULL
        }
    }

    if (n->next == NULL) {
        // Node is the last node
        *last = n->prev; // Update last to the previous node
        n->prev->next = NULL; // Set the next pointer of the new last node to NULL
    }

    free(n); // Free the memory of the deleted node
    return *first; // Return updated first pointer
}

// Function to initialize a new node with a given key
node* initNode(int32_t key) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key; // Set the key of the new node
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Main function to execute the program
int main() {
<<<<<<< HEAD
    char command[100]; // Buffer to read commands
    node* first = NULL; // Initialize pointers for the first and last nodes of the list
    node* last = NULL;

    // Read the first line of input (not used)
    fgets(command, sizeof(command), stdin);

    // Loop to process each command from the input
    while (fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = 0; // Remove newline character
=======
    char command[100]; // Buffer to hold commands
    node* first = NULL; // Initialize pointers for the first and last nodes of the list
    node* last = NULL;

    // Loop to process each command from the input
    while (fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = 0; // Remove newline character

>>>>>>> 98c87cb78a (data updated)
        if (strcmp(command, "deleteFirst") == 0) {
            if (first != NULL) {
                first = Delete(first, &first, &last);
            }
        } else if (strcmp(command, "deleteLast") == 0) {
            if (last != NULL) {
                last = Delete(last, &first, &last);
            }
        } else {
<<<<<<< HEAD
            char* xcmd = strtok(command, " "); // Split the command into parts
            int k = atoi(strtok(NULL, " "));    // Convert the second part to an integer
            int32_t k32 = (int32_t)k;            // Convert the integer to int32_t
            if (strcmp(xcmd, "delete") == 0) {
                for (node* a = first; a != NULL; a = a->next) {
                    if (a->key == k32) {
                        first = Delete(a, &first, &last); // Delete the node and update first
                        break;
                    }
                }
            } else if (strcmp(xcmd, "insert") == 0) {
                node* n = initNode(k32); // Initialize a new node
                n->next = first;          // Set the new node's next pointer to the current first node
                if (first != NULL) {
                    first->prev = n; // Update the previous pointer of the current first node
                }
                first = n; // Update first to the new node
                if (last == NULL) {
                    last = n; // If the list was empty, set last to the new node
=======
            char* xcmd = strtok(command, " ");
            char* keyStr = strtok(NULL, " ");
            if (xcmd != NULL && keyStr != NULL) {
                int32_t k = atoi(keyStr); // Convert the second part to an integer
                if (strcmp(xcmd, "delete") == 0) {
                    for (node* a = first; a != NULL; a = a->next) {
                        if (a->key == k) {
                            first = Delete(a, &first, &last); // Delete the node and update first
                            break;
                        }
                    }
                } else if (strcmp(xcmd, "insert") == 0) {
                    node* n = initNode(k); // Initialize a new node
                    n->next = first; // Set the new node's next pointer to the current first node
                    if (first != NULL) {
                        first->prev = n; // Update the previous pointer of the current first node
                    }
                    first = n; // Update first to the new node
                    if (last == NULL) {
                        last = n; // If the list was empty, set last to the new node
                    }
>>>>>>> 98c87cb78a (data updated)
                }
            }
        }
    }

    rPrint(first); // Print the keys of the linked list starting from the first node
<<<<<<< HEAD
    printf("\n");  // Output the result

    // Free the remaining nodes in the list
    while (first != NULL) {
        node* temp = first;
        first = first->next;
        free(temp);
    }

=======
    printf("\n"); // Output the result
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
