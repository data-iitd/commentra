#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
// Node structure for the binary search tree (BST)
=======
// Node represents a node in a binary search tree (BST)
>>>>>>> 98c87cb78a (data updated)
typedef struct Node {
    int key;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

<<<<<<< HEAD
// Tree structure for the binary search tree
=======
// Tree represents a binary search tree
>>>>>>> 98c87cb78a (data updated)
typedef struct Tree {
    Node* root;
} Tree;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

<<<<<<< HEAD
// Function to insert a new key into the BST
=======
// Function to insert a new node with the given key to the BST
>>>>>>> 98c87cb78a (data updated)
void insert(Tree* tree, int key) {
    if (tree->root == NULL) {
        tree->root = createNode(key);
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

    Node* newNode = createNode(key);
    newNode->parent = prevNode;
    if (prevNode->key < key) {
        prevNode->right = newNode;
    } else {
        prevNode->left = newNode;
    }
}

// Helper function for inorder traversal
void visitInorder(Node* node, int* acc, int* index) {
    if (node == NULL) {
        return;
    }
    visitInorder(node->left, acc, index);
    acc[(*index)++] = node->key;
    visitInorder(node->right, acc, index);
}

// Helper function for preorder traversal
void visitPreorder(Node* node, int* acc, int* index) {
    if (node == NULL) {
        return;
    }
    acc[(*index)++] = node->key;
    visitPreorder(node->left, acc, index);
    visitPreorder(node->right, acc, index);
}

<<<<<<< HEAD
// Function to print the tree
=======
// Function to print the tree using inorder and preorder traversals
>>>>>>> 98c87cb78a (data updated)
void print(Tree* tree) {
    if (tree->root == NULL) {
        printf("\n\n");
        return;
    }

    int acc[100]; // Assuming a maximum of 100 nodes for simplicity
    int index = 0;

    // Inorder traversal
    visitInorder(tree->root, acc, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");

    index = 0; // Reset index for preorder traversal
    // Preorder traversal
    visitPreorder(tree->root, acc, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");
}

// Function to read an integer from input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Main function
int main() {
    Tree tree = {NULL};
    int n = nextInt();

    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key = nextInt();
            insert(&tree, key);
        } else if (strcmp(command, "print") == 0) {
            print(&tree);
        } else {
            fprintf(stderr, "unknown command: %s\n", command);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

// <END-OF-CODE>
