#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int32_t key;
    struct node* prev;
    struct node* next;
} node;

void rPrint(node* n) {
    if (n != NULL) {
        printf("%d", n->key);
        if (n->next != NULL) {
            printf(" ");
            rPrint(n->next);
        }
    }
}

void deleteNode(node** first, node** last, node* n) {
    if (n->prev != NULL && n->next != NULL) {
        // swap
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
    free(n);
}

node* initNode(int32_t key) {
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int main() {
    char command[256];
    node* first = NULL;
    node* last = NULL;

    while (fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = 0; // Remove newline character
        if (strcmp(command, "deleteFirst") == 0) {
            if (first != NULL) {
                deleteNode(&first, &last, first);
            }
        } else if (strcmp(command, "deleteLast") == 0) {
            if (last != NULL) {
                deleteNode(&first, &last, last);
            }
        } else {
            char* xcmd = strtok(command, " ");
            if (xcmd != NULL) {
                if (strcmp(xcmd, "delete") == 0) {
                    int32_t k = atoi(strtok(NULL, " "));
                    for (node* a = first; a != NULL; a = a->next) {
                        if (a->key == k) {
                            deleteNode(&first, &last, a);
                            break;
                        }
                    }
                } else if (strcmp(xcmd, "insert") == 0) {
                    int32_t k = atoi(strtok(NULL, " "));
                    node* n = initNode(k);
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
    }

    rPrint(first);
    printf("\n");

    // Free remaining nodes
    while (first != NULL) {
        node* temp = first;
        first = first->next;
        free(temp);
    }

    return 0;
}

// <END-OF-CODE>
