#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining node and tree structures
typedef struct node {
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
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

// Function to insert a new node into the tree
void insert(Tree* tree, int key) {
    // Base case: If the tree is empty, create a new root node
    if (tree->root == NULL) {
        tree->root = createNode(key);
        return;
    }

    // Variables to keep track of current and previous nodes
    Node* currentNode = tree->root;
    Node* prevNode = NULL;

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
    Node* newNode = createNode(key);
    newNode->parent = prevNode;

    // Set the new node as the left or right child of the previous node
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

// Function to print the tree in inorder and preorder traversals
void printTree(Tree* tree) {
    if (tree->root == NULL) {
        printf("\n\n");
        return;
    }

    // Arrays to store the visited nodes
    int accInorder[100]; // Assuming a maximum of 100 nodes
    int accPreorder[100];
    int indexInorder = 0;
    int indexPreorder = 0;

    // Print the tree in inorder and preorder traversals
    visitInorder(tree->root, accInorder, &indexInorder);
    visitPreorder(tree->root, accPreorder, &indexPreorder);

    printf("Inorder traversal: ");
    for (int i = 0; i < indexInorder; i++) {
        printf("%d ", accInorder[i]);
    }
    printf("\n");

    printf("Preorder traversal: ");
    for (int i = 0; i < indexPreorder; i++) {
        printf("%d ", accPreorder[i]);
    }
    printf("\n");
}

// Main function to read input and call the appropriate methods
int main() {
    // Creating a new tree object
    Tree tree = {NULL};

    // Reading the number of nodes in the tree
    int n;
    scanf("%d", &n);

    // Reading the commands and calling the appropriate methods
    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(&tree, key);
        } else if (strcmp(command, "print") == 0) {
            printTree(&tree);
        } else {
            fprintf(stderr, "unknown command: %s\n", command);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

// <END-OF-CODE>
