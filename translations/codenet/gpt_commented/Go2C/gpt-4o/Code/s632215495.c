#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the binary tree
typedef struct node {
    int key;                // The key value of the node
    struct node* parent;    // Pointer to the parent node
    struct node* left;      // Pointer to the left child node
    struct node* right;     // Pointer to the right child node
} Node;

// Define a structure for the binary tree
typedef struct tree {
    Node* root;            // Pointer to the root node of the tree
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

// Insert a new key into the binary tree
void insert(Tree* tree, int key) {
    // If the tree is empty, create a new root node
    if (tree->root == NULL) {
        tree->root = createNode(key);
        return;
    }

    Node* currentNode = tree->root;
    Node* prevNode = NULL;

    // Traverse the tree to find the correct position for the new key
    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right; // Move to the right child
        } else {
            currentNode = currentNode->left; // Move to the left child
        }
    }

    // Create a new node for the key and set its parent
    Node* newNode = createNode(key);
    newNode->parent = prevNode;

    // Attach the new node to the correct position in the tree
    if (prevNode->key < key) {
        prevNode->right = newNode; // Insert as right child
    } else {
        prevNode->left = newNode; // Insert as left child
    }
}

// Function to perform inorder traversal of the tree
void visitInorder(Node* node, int* acc, int* index) {
    if (node == NULL) return; // Return if node is NULL
    visitInorder(node->left, acc, index); // Traverse left subtree
    acc[(*index)++] = node->key; // Add the current node's key
    visitInorder(node->right, acc, index); // Traverse right subtree
}

// Function to perform preorder traversal of the tree
void visitPreorder(Node* node, int* acc, int* index) {
    if (node == NULL) return; // Return if node is NULL
    acc[(*index)++] = node->key; // Add the current node's key
    visitPreorder(node->left, acc, index); // Traverse left subtree
    visitPreorder(node->right, acc, index); // Traverse right subtree
}

// Print the keys in the tree in both inorder and preorder traversal
void print(Tree* tree) {
    if (tree->root == NULL) {
        printf("\n\n");
        return;
    }

    int acc[100]; // Assuming a maximum of 100 nodes for simplicity
    int index = 0;

    // Print inorder traversal
    visitInorder(tree->root, acc, &index);
    printf(" ");
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");

    index = 0; // Reset index for preorder traversal
    // Print preorder traversal
    visitPreorder(tree->root, acc, &index);
    printf(" ");
    for (int i = 0; i < index; i++) {
        printf("%d ", acc[i]);
    }
    printf("\n");
}

// Main function to read commands and manipulate the binary tree
int main() {
    Tree tree = {NULL}; // Initialize a new binary tree
    int n;
    
    // Read the number of commands
    if (scanf("%d", &n) != 1) {
        perror("Failed to read number of commands");
        return EXIT_FAILURE;
    }

    // Process each command
    for (int i = 0; i < n; i++) {
        char command[10];
        int key;

        // Read the command
        if (scanf("%s", command) != 1) {
            perror("Failed to read command");
            return EXIT_FAILURE;
        }

        if (strcmp(command, "insert") == 0) {
            // Read the key to insert
            if (scanf("%d", &key) != 1) {
                perror("Failed to read key");
                return EXIT_FAILURE;
            }
            insert(&tree, key); // Insert the key into the tree
        } else if (strcmp(command, "print") == 0) {
            print(&tree); // Print the tree's keys
        } else {
            fprintf(stderr, "unknown command: %s\n", command); // Handle unknown commands
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

// <END-OF-CODE>
