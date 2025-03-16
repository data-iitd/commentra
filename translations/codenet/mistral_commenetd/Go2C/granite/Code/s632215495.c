
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
        node *parent = NULL;
        node *current = tree->root;
        while (current!= NULL) {
            parent = current;
            if (current->key < key) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        node *newNode = (node *)malloc(sizeof(node));
        newNode->key = key;
        newNode->parent = parent;
        if (parent->key < key) {
            parent->right = newNode;
        } else {
            parent->left = newNode;
        }
    }
}

void printInorder(node *node, int *acc, int *index) {
    if (node!= NULL) {
        printInorder(node->left, acc, index);
        acc[*index] = node->key;
        *index += 1;
        printInorder(node->right, acc, index);
    }
}

void printPreorder(node *node, int *acc, int *index) {
    if (node!= NULL) {
        acc[*index] = node->key;
        *index += 1;
        printPreorder(node->left, acc, index);
        printPreorder(node->right, acc, index);
    }
}

void printTree(tree tree) {
    if (tree.root == NULL) {
        printf("\n");
        printf("\n");
        return;
    }
    int *acc = (int *)malloc(sizeof(int) * 1000);
    int index = 0;
    printInorder(tree.root, acc, &index);
    printf("Inorder traversal: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");
    index = 0;
    printPreorder(tree.root, acc, &index);
    printf("Preorder traversal: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");
}

int main() {
    tree tree;
    tree.root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(&tree, key);
        } else if (strcmp(command, "print") == 0) {
            printTree(tree);
        } else {
            printf("unknown command: %s\n", command);
        }
    }
    return 0;
}
