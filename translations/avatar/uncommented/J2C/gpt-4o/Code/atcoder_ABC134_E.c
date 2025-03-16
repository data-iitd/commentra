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
    newNode->value = 1;
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
        root->value++;
    }
    return root;
}

Node* lowerKey(Node* root, int key) {
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

Node* removeNode(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if (root->value > 1) {
            root->value--;
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                free(root);
                return temp;
            }
            Node* temp = root->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            root->key = temp->key;
            root->value = temp->value;
            root->right = removeNode(root->right, temp->key);
        }
    }
    return root;
}

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return root->value + countNodes(root->left) + countNodes(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    while (n-- > 0) {
        int num;
        scanf("%d", &num);
        Node* lower = lowerKey(root, num);
        if (lower == NULL) {
            root = insert(root, num);
        } else {
            root = removeNode(root, lower->key);
            root = insert(root, num);
        }
    }
    int ans = countNodes(root);
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
