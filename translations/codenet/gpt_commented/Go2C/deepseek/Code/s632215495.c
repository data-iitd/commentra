#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the binary tree
typedef struct Node {
    int key; // The key value of the node
    struct Node *parent; // Pointer to the parent node
    struct Node *left; // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
} Node;

// Define a structure for the binary tree
typedef struct Tree {
    Node *root; // Pointer to the root node of the tree
} Tree;

// Insert a new key into the binary tree
void insert(Tree *tree, int key) {
    // If the tree is empty, create a new root node
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
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->parent = prevNode;
    newNode->left = NULL;
    newNode->right = NULL;
    // Attach the new node to the correct position in the tree
    if (prevNode->key < key) {
        prevNode->right = newNode; // Insert as right child
    } else {
        prevNode->left = newNode; // Insert as left child
    }
}

// Print the keys in the tree in both inorder and preorder traversal
void print(Node *node) {
    if (node == NULL) {
        printf("\n");
        printf("\n");
        return;
    }

    // Print inorder traversal
    int inorder[100];
    int index = 0;
    Node *current = node;
    while (current != NULL) {
        if (current->left != NULL) {
            current = current->left;
        } else {
            inorder[index++] = current->key;
            if (current->right != NULL) {
                current = current->right;
            } else {
                while (index > 0 && (current == NULL || current->parent != NULL && current->parent->right == NULL || current->parent != NULL && current->parent->right != NULL && current->parent->right->key <= current->key)) {
                    current = current->parent;
                    index--;
                }
                if (current != NULL && current->parent != NULL && current->parent->right != NULL) {
                    current = current->parent->right;
                } else {
                    current = NULL;
                }
            }
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%d ", inorder[i]);
    }
    printf("\n");

    // Print preorder traversal
    int preorder[100];
    index = 0;
    current = node;
    while (current != NULL) {
        preorder[index++] = current->key;
        if (current->left != NULL) {
            current = current->left;
        } else {
            while (index > 0 && (current == NULL || current->parent != NULL && current->parent->right == NULL || current->parent != NULL && current->parent->right != NULL && current->parent->right->key <= current->key)) {
                current = current->parent;
                index--;
            }
            if (current != NULL && current->parent != NULL && current->parent->right != NULL) {
                current = current->parent->right;
            } else {
                current = NULL;
            }
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%d ", preorder[i]);
    }
    printf("\n");
}

// Main function to read commands and manipulate the binary tree
int main() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;

    char command[10];
    int key;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "insert") == 0) {
            scanf("%d", &key);
            insert(tree, key);
        } else if (strcmp(command, "print") == 0) {
            print(tree->root);
        } else {
            printf("unknown command: %s\n", command);
        }
    }

    return 0;
}
