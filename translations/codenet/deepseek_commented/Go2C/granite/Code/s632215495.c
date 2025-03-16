
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
} node;

typedef struct tree {
    node *root;
} tree;

void insert(tree *tree, int key) {
    if (tree->root == NULL) {
        tree->root = (node *)malloc(sizeof(node));
        tree->root->key = key;
        tree->root->parent = NULL;
        tree->root->left = NULL;
        tree->root->right = NULL;
    } else {
        node *currentNode = tree->root;
        node *prevNode = NULL;
        while (currentNode!= NULL) {
            prevNode = currentNode;
            if (currentNode->key < key) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }
        node *newNode = (node *)malloc(sizeof(node));
        newNode->key = key;
        newNode->parent = prevNode;
        if (prevNode->key < key) {
            prevNode->right = newNode;
        } else {
            prevNode->left = newNode;
        }
    }
}

void print(tree tree) {
    if (tree.root == NULL) {
        printf("\n");
        printf("\n");
    } else {
        int *acc = (int *)malloc(sizeof(int) * 1000);
        int accSize = 0;
        visitInorder(tree.root, acc, &accSize);
        printf(" ");
        for (int i = 0; i < accSize; i++) {
            printf("%d ", acc[i]);
        }
        printf("\n");
        accSize = 0;
        visitPreorder(tree.root, acc, &accSize);
        printf(" ");
        for (int i = 0; i < accSize; i++) {
            printf("%d ", acc[i]);
        }
        printf("\n");
    }
}

void visitPreorder(node *node, int *acc, int *accSize) {
    if (node == NULL) {
        return;
    }
    acc[(*accSize)++] = node->key;
    if (node->left!= NULL) {
        visitPreorder(node->left, acc, accSize);
    }
    if (node->right!= NULL) {
        visitPreorder(node->right, acc, accSize);
    }
}

void visitInorder(node *node, int *acc, int *accSize) {
    if (node == NULL) {
        return;
    }
    if (node->left!= NULL) {
        visitInorder(node->left, acc, accSize);
    }
    acc[(*accSize)++] = node->key;
    if (node->right!= NULL) {
        visitInorder(node->right, acc, accSize);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    tree tree;
    tree.root = NULL;
    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(&tree, key);
        } else if (strcmp(command, "print") == 0) {
            print(tree);
        } else {
            printf("unknown command: %s\n", command);
        }
    }
    return 0;
}

