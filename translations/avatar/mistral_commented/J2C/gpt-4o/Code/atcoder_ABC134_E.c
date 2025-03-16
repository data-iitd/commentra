#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key, int value) {
    if (root == NULL) {
        return createNode(key, value);
    }
    if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    } else {
        root->value = value;
    }
    return root;
}

Node* findLowerKey(Node* root, int key) {
    Node* current = root;
    Node* result = NULL;
    while (current != NULL) {
        if (key > current->key) {
            result = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return result;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int n;
    scanf("%d", &n);  // Reading the number of test cases

    Node* map = NULL;  // Creating an empty TreeMap

    while (n-- > 0) {
        int num;
        scanf("%d", &num);  // Reading the number

        Node* lowerNode = findLowerKey(map, num);  // Find the lower key
        if (lowerNode == NULL) {  // If the number is not present
            map = insert(map, num, 1);  // Insert the number with frequency 1
        } else {  // If the number is already present
            int key = lowerNode->key;  // Get the key (previous number)
            int val = lowerNode->value;  // Get the value (frequency) of the previous number

            if (val == 1) {  // If the frequency of the previous number is 1
                // Remove the previous number from the TreeMap
                // This requires a more complex removal function which is not implemented here
            } else {  // If the frequency of the previous number is greater than 1
                lowerNode->value--;  // Decrement the frequency of the previous number
            }

            Node* currentNode = findLowerKey(map, num);
            if (currentNode == NULL || currentNode->key != num) {
                map = insert(map, num, 1);  // Insert the current number with frequency 1
            } else {
                currentNode->value++;  // Increment the value of the current number
            }
        }
    }

    int ans = 0;  // Initializing the answer variable to 0

    // Calculate the total frequency
    // This requires a traversal function which is not implemented here

    printf("%d\n", ans);  // Printing the answer

    freeTree(map);  // Free the allocated memory for the TreeMap
    return 0;
}

// <END-OF-CODE>
