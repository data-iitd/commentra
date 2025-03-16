#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil 0

#define MAX_SIZE 100000

typedef struct node {
    int key;
    struct node *next;
    struct node *prev;
} Node;

Node *nil;

Node *listSearch(int key) {
    Node *cur = nil->next;
    while (cur!= nil && cur->key!= key)
        cur = cur->next;
    return cur;
}

void init(void) {
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void printList(void) {
    Node *cur = nil->next;
    int isf = 1;
    while (1) {
        if (cur == nil) break;
        if (isf == 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
        isf = 0;
    }
    printf("\n");
}

void deleteNode(Node *t) {
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst(void) {
    Node *t = nil->next;
    if (t == nil)
        return;
    deleteNode(t);
}

void deleteLast(void) {
    Node *t = nil->prev;
    if (t == nil)
        return;
    deleteNode(t);
}

void delete(int key) {
    Node *t = listSearch(key);
    if (t == nil)
        return;
    deleteNode(t);
}

void insert(int key) {
    Node *x;
    x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main() {
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;

    scanf("%d", &n);
    init();
    for (i = 0; i < n; i++) {
        scanf("%s%d", com, &key);
        if (com[0] == 'i') {
            insert(key);
            np++;
            size++;
        } else if (com[0] == 'd') {
            if (strlen(com) > 6) {
                if (com[6] == 'F') {
                    deleteFirst();
                } else if (com[6] == 'L') {
                    deleteLast();
                }
            } else {
                delete(key);
                nd++;
            }
            size--;
        }
    }
    printList();
    return 0;
}

