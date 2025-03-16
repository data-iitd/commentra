
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
    sprintf(buf, "%d ", n->key);
    if (n->next != NULL) {
        rPrint(n->next, buf);
    }
    return;
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
node *Delete(node *n, node *first, node *last) {
    if (n->prev != NULL && n->next != NULL) {
        //swap
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return first;
    }

    if (n->next == NULL && n->prev == NULL) {
        return NULL;
    }

    if (n->prev == NULL) {
        first = n->next;
        n->next->prev = NULL;
    }

    if (n->next == NULL) {
        last = n->prev;
        n->prev->next = NULL;
    }

    return first;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node *initNode(int32_t key) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
    char cmd[100];
    node *first = NULL;
    node *last = NULL;
    while (scanf("%s", cmd) != EOF) {
        switch (cmd[0]) {
            case 'd':
                if (cmd[1] == 'e') {
                    if (cmd[2] == 'l') {
                        if (cmd[3] == 'e') {
                            if (cmd[4] == 't') {
                                if (cmd[5] == 'e') {
                                    if (cmd[6] == 'F') {
                                        if (cmd[7] == 'i') {
                                            if (cmd[8] == 'r') {
                                                if (cmd[9] == 's') {
                                                    if (cmd[10] == 't') {
                                                        first = Delete(first, first, last);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            case 'i':
                if (cmd[1] == 'n') {
                    if (cmd[2] == 's') {
                        if (cmd[3] == 'e') {
                            if (cmd[4] == 'r') {
                                if (cmd[5] == 't') {
                                    int32_t k;
                                    sscanf(cmd + 6, "%d", &k);
                                    node *n = initNode(k);
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
                    }
                }
            case 'd':
                if (cmd[1] == 'e') {
                    if (cmd[2] == 'l') {
                        if (cmd[3] == 'e') {
                            if (cmd[4] == 't') {
                                if (cmd[5] == 'e') {
                                    if (cmd[6] == 'L') {
                                        if (cmd[7] == 'a') {
                                            if (cmd[8] == 's') {
                                                if (cmd[9] == 't') {
                                                    if (cmd[10] == ' ') {
                                                        int32_t k;
                                                        sscanf(cmd + 11, "%d", &k);
                                                        for (node *a = first; a != NULL; a = a->next) {
                                                            if (a->key == k) {
                                                                first = Delete(a, first, last);
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
        }
    }
    char buf[1000];
    rPrint(first, buf);
    printf("%s\n", buf);
    return 0;
}

