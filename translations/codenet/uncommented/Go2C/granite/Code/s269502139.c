
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node *prev;
    struct node *next;
} node;

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

void delete(node *n, node **first, node **last) {
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

node *initNode(int key) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int main() {
    char buf[1000];
    node *first = NULL, *last = NULL;
    char input[100];
    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "deleteFirst\n") == 0) {
            delete(first, &first, &last);
        } else if (strcmp(input, "deleteLast\n") == 0) {
            delete(last, &first, &last);
        } else {
            char *token = strtok(input, " ");
            if (strcmp(token, "delete") == 0) {
                token = strtok(NULL, " ");
                int key = atoi(token);
                node *n = first;
                while (n!= NULL) {
                    if (n->key == key) {
                        delete(n, &first, &last);
                        break;
                    }
                    n = n->next;
                }
            } else if (strcmp(token, "insert") == 0) {
                token = strtok(NULL, " ");
                int key = atoi(token);
                node *n = initNode(key);
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
