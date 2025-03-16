#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining node and tree structures
typedef struct Node {
    int key;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

// Method to insert a new node into the tree
void insert(Tree *tree, int key) {
    // Base case: If the tree is empty, create a new root node
    if (tree->root == NULL) {
        tree->root = (Node *)malloc(sizeof(Node));
        tree->root->key = key;
        tree->root->parent = NULL;
        tree->root->left = NULL;
        tree->root->right = NULL;
        return;
    }

    // Variables to keep track of current and previous nodes
    Node *currentNode = tree->root;
    Node *prevNode = NULL;

    // Traverse the tree to find the correct position for the new node
    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    // Create a new node with the given key
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->parent = prevNode;
    newNode->left = NULL;
    newNode->right = NULL;

    // Set the new node's parent to the previous node
    if (prevNode->key < key) {
        prevNode->right = newNode;
    } else {
        prevNode->left = newNode;
    }
}

// Method to print the tree in inorder and preorder traversals
void print(Node *node) {
    // Base case: If the node is nil, return
    if (node == NULL) {
        printf("\n");
        printf("\n");
        return;
    }

    // Variable to store the visited nodes in inorder traversal
    int acc[1000];
    int index = 0;

    // Print the tree in inorder and preorder traversals
    printf("Inorder traversal: ");
    inorderTraversal(node, acc, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(node, acc, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");
}

// Helper functions for depth-first traversals of the tree
void preorderTraversal(Node *node, int *acc, int *index) {
    // Base case: If the node is nil, return
    if (node == NULL) {
        return;
    }

    // Add the current node's key to the accumulator array
    acc[(*index)++] = node->key;

    // Recursively traverse the left and right subtrees
    preorderTraversal(node->left, acc, index);
    preorderTraversal(node->right, acc, index);
}

void inorderTraversal(Node *node, int *acc, int *index) {
    // Base case: If the node is nil, return
    if (node == NULL) {
        return;
    }

    // Recursively traverse the left subtree and add its keys to the accumulator array
    inorderTraversal(node->left, acc, index);

    // Add the current node's key to the accumulator array
    acc[(*index)++] = node->key;

    // Recursively traverse the right subtree and add its keys to the accumulator array
    inorderTraversal(node->right, acc, index);
}

// Main function to read input and call the appropriate methods
int main() {
    Tree tree = {NULL};
    char command[10];
    int key;

    // Reading the number of nodes in the tree
    scanf("%d", &key);

    // Reading the commands and calling the appropriate methods
    for (int i = 0; i < key; i++) {
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            scanf("%d", &key);
            insert(&tree, key);
        } else if (strcmp(command, "print") == 0) {
            print(tree.root);
        } else {
            printf("unknown command: %s\n", command);
        }
    }

    return 0;
}

// Helper functions to read integers from the stdin
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}
