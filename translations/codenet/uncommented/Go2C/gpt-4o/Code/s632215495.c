#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

void insert(Tree* tree, int key) {
    if (tree->root == NULL) {
        tree->root = (Node*)malloc(sizeof(Node));
        tree->root->key = key;
        tree->root->parent = NULL;
        tree->root->left = NULL;
        tree->root->right = NULL;
        return;
    }

    Node* currentNode = tree->root;
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->parent = prevNode;
    newNode->left = NULL;
    newNode->right = NULL;

    if (prevNode->key < key) {
        prevNode->right = newNode;
    } else {
        prevNode->left = newNode;
    }
}

void visitPreorder(Node* node, int* acc, int* index) {
    if (node == NULL) {
        return;
    }
    acc[(*index)++] = node->key;
    visitPreorder(node->left, acc, index);
    visitPreorder(node->right, acc, index);
}

void visitInorder(Node* node, int* acc, int* index) {
    if (node == NULL) {
        return;
    }
    visitInorder(node->left, acc, index);
    acc[(*index)++] = node->key;
    visitInorder(node->right, acc, index);
}

void print(Tree* tree) {
    if (tree->root == NULL) {
        printf("\n\n");
        return;
    }

    int acc[100]; // Assuming a maximum of 100 nodes for simplicity
    int index = 0;

    // Inorder
    visitInorder(tree->root, acc, &index);
    for (int i = 0; i < index; i++) {
        printf(" %d", acc[i]);
    }
    printf("\n");

    index = 0; // Reset index for preorder
    // Preorder
    visitPreorder(tree->root, acc, &index);
    for (int i = 0; i < index; i++) {
        printf(" %d", acc[i]);
    }
    printf("\n");
}

int main() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(tree, key);
        } else if (strcmp(command, "print") == 0) {
            print(tree);
        } else {
            fprintf(stderr, "unknown command: %s\n", command);
            exit(EXIT_FAILURE);
        }
    }

    // Free memory (not shown for simplicity)
    // In a real application, you should free all allocated nodes.

    free(tree);
    return 0;
}

// <END-OF-CODE>
