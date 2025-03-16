#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1; // Initialize frequency to 1
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        root->value++; // Increment frequency
    }
    return root;
}

Node* findLowerKey(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key <= root->key) {
        return findLowerKey(root->left, key);
    }
    Node* rightResult = findLowerKey(root->right, key);
    return rightResult ? rightResult : root;
}

void decrement(Node* root, int key) {
    if (root == NULL) return;
    if (key < root->key) {
        decrement(root->left, key);
    } else if (key > root->key) {
        decrement(root->right, key);
    } else {
        root->value--;
        if (root->value == 0) {
            // Handle removal of the node (not implemented for simplicity)
        }
    }
}

int sumFrequencies(Node* root) {
    if (root == NULL) return 0;
    return root->value + sumFrequencies(root->left) + sumFrequencies(root->right);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n); // Reading the integer n from the input
    Node* root = NULL; // Initializing the root of the TreeMap

    // Looping n times to read n numbers
    while (n-- > 0) {
        int num;
        scanf("%d", &num); // Reading the next integer from the input

        Node* lowerKeyNode = findLowerKey(root, num);
        if (lowerKeyNode == NULL) {
            // No key less than the current number
            root = insert(root, num); // Insert the current number
        } else {
            // Found the largest key less than the current number
            decrement(root, lowerKeyNode->key); // Decrement the frequency of the found key
            root = insert(root, num); // Insert the current number
        }
    }

    // Calculating the sum of all frequencies in the tree
    int ans = sumFrequencies(root);

    // Printing the sum of frequencies
    printf("%d\n", ans);

    // Freeing the allocated memory for the tree
    freeTree(root);

    return 0;
}

// <END-OF-CODE>
