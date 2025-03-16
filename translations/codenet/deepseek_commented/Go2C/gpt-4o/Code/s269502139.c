#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
typedef struct node {
    int key;
    struct node* prev;
    struct node* next;
} node;

// Recursive Print Function
// The `rPrint` function prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node* n) {
    if (n != NULL) {
        printf("%d", n->key);
        if (n->next != NULL) {
            printf(" ");
            rPrint(n->next);
        }
    }
}

// Delete Method
// The `Delete` function removes the current node from the list and adjusts the pointers of the surrounding nodes.
node* Delete(node* n, node** first, node** last) {
    if (n->prev != NULL && n->next != NULL) {
        // Node is in the middle
        n->prev->next = n->next;
        n->next->prev = n->prev;
    } else if (n->next == NULL && n->prev == NULL) {
        // Node is the only node
        *first = NULL;
        *last = NULL;
    } else if (n->prev == NULL) {
        // Node is the first node
        *first = n->next;
        n->next->prev = NULL;
    } else if (n->next == NULL) {
        // Node is the last node
        *last = n->prev;
        n->prev->next = NULL;
    }
    free(n);
    return *first;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node* initNode(int key) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
    node* first = NULL;
    node* last = NULL;
    char command[100];

    while (fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = 0; // Remove newline character
        if (strcmp(command, "deleteFirst") == 0) {
            if (first != NULL) {
                first = Delete(first, &first, &last);
            }
        } else if (strcmp(command, "deleteLast") == 0) {
            if (last != NULL) {
                last = Delete(last, &first, &last);
            }
        } else {
            char* xcmd = strtok(command, " ");
            int k = atoi(strtok(NULL, " "));
            switch (xcmd[0]) {
                case 'd': // delete
                    for (node* a = first; a != NULL; a = a->next) {
                        if (a->key == k) {
                            first = Delete(a, &first, &last);
                            break;
                        }
                    }
                    break;
                case 'i': // insert
                    node* n = initNode(k);
                    n->next = first;
                    if (first != NULL) {
                        first->prev = n;
                    }
                    first = n;
                    if (last == NULL) {
                        last = n;
                    }
                    break;
            }
        }
    }

    rPrint(first);
    printf("\n");
    return 0;
}

// <END-OF-CODE>
