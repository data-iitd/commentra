#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
typedef struct node {
    int key;
    struct node *prev;
    struct node *next;
} Node;

// Recursive Print Function
// The `rPrint` function prints the keys of the nodes in the list from the current node to the last node.
void rPrint(Node *n, char *buffer) {
    char temp[12];
    sprintf(temp, "%d", n->key);
    strcat(buffer, temp);
    if (n->next != NULL) {
        strcat(buffer, " ");
        rPrint(n->next, buffer);
    }
}

// Delete Method
// The `Delete` function removes the current node from the list and adjusts the pointers of the surrounding nodes.
Node* Delete(Node *n) {
    if (n->prev != NULL && n->next != NULL) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        free(n);
        return NULL; // Return NULL to indicate the list is now empty
    }

    if (n->next == NULL && n->prev == NULL) {
        return NULL;
    }

    if (n->prev == NULL) {
        Node *temp = n->next;
        free(n);
        return temp;
    }

    if (n->next == NULL) {
        n->prev->next = NULL;
        Node *temp = n->prev;
        free(n);
        return temp;
    }

    return NULL;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
Node* initNode(int key) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
    Node *first = NULL;
    Node *last = NULL;
    char cmd[10];
    int k;

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "deleteFirst") == 0) {
            if (first != NULL) {
                first = first->Delete(first);
                if (first == NULL) {
                    last = NULL;
                }
            }
        } else if (strcmp(cmd, "deleteLast") == 0) {
            if (last != NULL) {
                last = last->Delete(last);
                if (last == NULL) {
                    first = NULL;
                }
            }
        } else {
            sscanf(cmd, "%d", &k);
            if (strcmp(cmd, "delete") == 0) {
                Node *current = first;
                while (current != NULL) {
                    if (current->key == k) {
                        if (current == first) {
                            first = current->next;
                            if (first != NULL) {
                                first->prev = NULL;
                            }
                        } else if (current == last) {
                            last = current->prev;
                            if (last != NULL) {
                                last->next = NULL;
                            }
                        } else {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }
                        free(current);
                        break;
                    }
                    current = current->next;
                }
            } else if (strcmp(cmd, "insert") == 0) {
                Node *n = initNode(k);
                n->next = first;
                if (first != NULL) {
                    first->prev = n;
                }
                first = n;
                if (last == NULL) {
                    last = n;
                }
            }
        }
    }

    char buffer[1000] = "";
    if (first != NULL) {
        rPrint(first, buffer);
    }
    printf("%s\n", buffer);

    // Free the remaining nodes
    Node *current = first;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
