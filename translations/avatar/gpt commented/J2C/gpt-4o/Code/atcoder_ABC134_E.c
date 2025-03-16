#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int count;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
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
        root->count++;
    }
    return root;
}

Node* findLowerKey(Node* root, int key) {
    Node* current = root;
    Node* last = NULL;
    while (current != NULL) {
        if (key > current->key) {
            last = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return last;
}

void deleteNode(Node** root, int key) {
    if (*root == NULL) return;

    if (key < (*root)->key) {
        deleteNode(&(*root)->left, key);
    } else if (key > (*root)->key) {
        deleteNode(&(*root)->right, key);
    } else {
        if ((*root)->count > 1) {
            (*root)->count--;
        } else {
            Node* temp = *root;
            if ((*root)->left == NULL) {
                *root = (*root)->right;
            } else if ((*root)->right == NULL) {
                *root = (*root)->left;
            } else {
                Node* successor = (*root)->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                (*root)->key = successor->key;
                (*root)->count = successor->count;
                deleteNode(&(*root)->right, successor->key);
            }
            free(temp);
        }
    }
}

int sumCounts(Node* root) {
    if (root == NULL) return 0;
    return root->count + sumCounts(root->left) + sumCounts(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    while (n-- > 0) {
        int num;
        scanf("%d", &num);

        Node* lowerKeyNode = findLowerKey(root, num);
        if (lowerKeyNode == NULL) {
            root = insert(root, num);
        } else {
            int lowerKey = lowerKeyNode->key;
            if (lowerKeyNode->count == 1) {
                deleteNode(&root, lowerKey);
            } else {
                lowerKeyNode->count--;
            }
            root = insert(root, num);
        }
    }

    int ans = sumCounts(root);
    printf("%d\n", ans);

    return 0;
}
// <END-OF-CODE>
