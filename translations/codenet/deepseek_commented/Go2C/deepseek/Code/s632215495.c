#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in a binary search tree (BST)
typedef struct Node {
    int key;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

// Define a structure for the BST
typedef struct Tree {
    Node *root;
} Tree;

// Function to insert a new node with the given key into the BST
void insert(Tree *tree, int key) {
    if (tree->root == NULL) {
        tree->root = (Node *)malloc(sizeof(Node));
        tree->root->key = key;
        tree->root->parent = NULL;
        tree->root->left = NULL;
        tree->root->right = NULL;
        return;
    }

    Node *currentNode = tree->root;
    Node *prevNode = NULL;

    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->parent = prevNode;
    if (prevNode->key < key) {
        prevNode->right = newNode;
    } else {
        prevNode->left = newNode;
    }
}

// Function to print the tree using inorder and preorder traversals
void printTree(Tree tree) {
    int inorder[100];
    int preorder[100];
    int inorderIndex = 0;
    int preorderIndex = 0;

    if (tree.root == NULL) {
        printf("\n");
        printf("\n");
        return;
    }

    visitPreorder(tree.root, preorder, &preorderIndex);
    visitInorder(tree.root, inorder, &inorderIndex);

    for (int i = 0; i < inorderIndex; i++) {
        printf("%d ", inorder[i]);
    }
    printf("\n");
    for (int i = 0; i < preorderIndex; i++) {
        printf("%d ", preorder[i]);
    }
    printf("\n");
}

// Helper function to perform a preorder traversal of the tree
void visitPreorder(Node *node, int *preorder, int *index) {
    if (node == NULL) {
        return;
    }
    preorder[*index] = node->key;
    (*index)++;
    visitPreorder(node->left, preorder, index);
    visitPreorder(node->right, preorder, index);
}

// Helper function to perform an inorder traversal of the tree
void visitInorder(Node *node, int *inorder, int *index) {
    if (node == NULL) {
        return;
    }
    visitInorder(node->left, inorder, index);
    inorder[*index] = node->key;
    (*index)++;
    visitInorder(node->right, inorder, index);
}

// Main function to read commands from standard input
int main() {
    Tree tree = {NULL};
    char command[10];
    int key;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "insert") == 0) {
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
