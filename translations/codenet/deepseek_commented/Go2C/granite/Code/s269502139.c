

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
typedef struct node {
    int32_t key;
    struct node *prev;
    struct node *next;
} node;

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node *n, char *buf) {
    if (n == NULL) {
        return;
    }
    sprintf(buf, "%d", n->key);
    if (n->next!= NULL) {
        strcat(buf, " ");
        rPrint(n->next, buf);
    }
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
void Delete(node *n, node **first, node **last) {
    if (n->prev!= NULL && n->next!= NULL) {
        //swap
        n->prev->next = n->next;
        n->next->prev = n->prev;
    } else if (n->next == NULL && n->prev == NULL) {
        *first = NULL;
        *last = NULL;
    } else if (n->prev == NULL) {
        *first = n->next;
        n->next->prev = NULL;
    } else if (n->next == NULL) {
        *last = n->prev;
        n->prev->next = NULL;
    }
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node *initNode(int32_t key) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
    char buf[1000];
    node *first = NULL, *last = NULL;
    char cmd[100];
    while (scanf("%s", cmd)!= EOF) {
        if (strcmp(cmd, "deleteFirst") == 0) {
            Delete(first, &first, &last);
        } else if (strcmp(cmd, "deleteLast") == 0) {
            Delete(last, &first, &last);
        } else {
            char xcmd[100];
            int32_t k;
            sscanf(cmd, "%s %d", xcmd, &k);
            if (strcmp(xcmd, "delete") == 0) {
                node *a = first;
                while (a!= NULL) {
                    if (a->key == k) {
                        Delete(a, &first, &last);
                        break;
                    }
                    a = a->next;
                }
            } else if (strcmp(xcmd, "insert") == 0) {
                node *n = initNode(k);
                n->next = first;
                if (first!= NULL) {
                    first->prev = n;
                }
                first = n;
                if (last == NULL) {
                    last = n;
                }
            }
        }
    }
    rPrint(first, buf);
    printf("%s\n", buf);
    return 0;
}

This code now includes comments that describe each logical block, making it easier to understand the structure and functionality of the C code.