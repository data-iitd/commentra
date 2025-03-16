
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

void print(tree tree) {
    if (tree.root == NULL) {
        printf("\n");
        printf("\n");
    } else {
        int *acc = (int *)malloc(sizeof(int) * 1000);
        int accSize = 0;
        printf(" %s\n", inorder(tree.root, acc, &accSize));
        printf(" %s\n", preorder(tree.root, acc, &accSize));
    }
}

char *inorder(node *node, int *acc, int *accSize) {
    if (node == NULL) {
        return "";
    }
    char *left = inorder(node->left, acc, accSize);
    acc[(*accSize)++] = node->key;
    char *right = inorder(node->right, acc, accSize);
    char *result = (char *)malloc(sizeof(char) * (strlen(left) + strlen(right) + 10));
    sprintf(result, "%s %d %s", left, node->key, right);
    return result;
}

char *preorder(node *node, int *acc, int *accSize) {
    if (node == NULL) {
        return "";
    }
    acc[(*accSize)++] = node->key;
    char *left = preorder(node->left, acc, accSize);
    char *right = preorder(node->right, acc, accSize);
    char *result = (char *)malloc(sizeof(char) * (strlen(left) + strlen(right) + 10));
    sprintf(result, "%d %s %s", node->key, left, right);
    return result;
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

// Translate the above C code to Go and end with comment "