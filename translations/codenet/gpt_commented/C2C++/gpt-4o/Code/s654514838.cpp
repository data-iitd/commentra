#include <iostream>
#include <memory>
#define NIL nullptr

// Definition of the node structure for the treap
struct Node {
    int key;            // Key of the node
    int priority;       // Priority of the node
    Node *right;       // Pointer to the right child
    Node *left;        // Pointer to the left child

    Node(int x, int y) : key(x), priority(y), left(NIL), right(NIL) {} // Constructor
};

// Function prototypes for delete operations
Node* Delete(Node*&, int);
Node* deleteNode(Node*&, int);

// Function to find a key in the treap
bool find(Node* p, int x) {
    while (p != NIL) { // Traverse until a leaf is reached
        if (p->key == x) return true; // Key found
        else if (p->key > x) p = p->left; // Move to the left child
        else p = p->right; // Move to the right child
    }
    return false; // Key not found
}

// Function for inorder traversal of the treap
void inorder(Node* a) {
    if (a->left != NIL) inorder(a->left); // Traverse left subtree
    std::cout << " " << a->key; // Print the current node's key
    if (a->right != NIL) inorder(a->right); // Traverse right subtree
}

// Function for preorder traversal of the treap
void preorder(Node* p) {
    std::cout << " " << p->key; // Print the current node's key
    if (p->left != NIL) preorder(p->left); // Traverse left subtree
    if (p->right != NIL) preorder(p->right); // Traverse right subtree
}

// Function to print the treap in both inorder and preorder
void print(Node* p) {
    inorder(p); // Print inorder
    std::cout << "\n";
    preorder(p); // Print preorder
    std::cout << "\n";
}

// Function to perform a right rotation on the treap
Node* rightRotate(Node* p) {
    Node* q = p->left; // Store the left child
    p->left = q->right; // Move the right child of left child to the left of p
    q->right = p; // Perform the rotation
    return q; // Return the new root after rotation
}

// Function to perform a left rotation on the treap
Node* leftRotate(Node* p) {
    Node* q = p->right; // Store the right child
    p->right = q->left; // Move the left child of right child to the right of p
    q->left = p; // Perform the rotation
    return q; // Return the new root after rotation
}

// Function to insert a new node into the treap
Node* insert(Node*& t, int key, int priority) {
    if (t == NIL)
        return new Node(key, priority); // Create a new node if leaf is reached
    if (t->key == key)
        return t; // Ignore duplicate keys

    if (key < t->key) { // Move to the left child
        t->left = insert(t->left, key, priority); // Update left child pointer
        if (t->priority < t->left->priority) // Right rotation if left child has higher priority
            t = rightRotate(t);
    } else { // Move to the right child
        t->right = insert(t->right, key, priority); // Update right child pointer
        if (t->priority < t->right->priority) // Left rotation if right child has higher priority
            t = leftRotate(t);
    }
    return t; // Return the updated root
}

// Function to delete a node from the treap
Node* Delete(Node*& t, int key) {
    if (t == NIL)
        return NIL; // Return NIL if the tree is empty

    if (key < t->key) // Search for the key in the left subtree
        t->left = Delete(t->left, key);
    else if (key > t->key) // Search for the key in the right subtree
        t->right = Delete(t->right, key);
    else 
        return deleteNode(t, key); // Key found, proceed to delete it
    return t; // Return the updated root
}

// Helper function to handle the actual deletion of a node
Node* deleteNode(Node*& t, int key) {
    if (t->left == NIL && t->right == NIL) { // Case: Leaf node
        delete t; // Remove the leaf node
        return NIL; // Return NIL
    } else if (t->left == NIL) { // Case: Node with only right child
        Node* temp = t;
        t = t->right; // Update root to right child
        delete temp; // Delete the old root
    } else if (t->right == NIL) { // Case: Node with only left child
        Node* temp = t;
        t = t->left; // Update root to left child
        delete temp; // Delete the old root
    } else { // Case: Node with both children
        if (t->left->priority > t->right->priority) // Compare priorities
            t = rightRotate(t); // Rotate right if left child has higher priority
        else
            t = leftRotate(t); // Rotate left otherwise
    }
    return Delete(t, key); // Continue deletion process
}

// Main function to execute the program
int main() {
    int num, x, y; // Variables for number of commands and key/priority values
    char com[8]; // Command buffer
    Node* root = NIL; // Initialize the root of the treap
    std::cin >> num; // Read the number of commands

    for (int i = 0; i < num; i++) {
        std::cin >> com; // Read the command
        switch (com[0]) { // Determine the command type
            case 'i': // Insert command
                std::cin >> x >> y; // Read key and priority
                root = insert(root, x, y); // Insert the new node
                break;
            case 'd': // Delete command
                std::cin >> x; // Read key to delete
                root = Delete(root, x); // Delete the node
                break;
            case 'f': // Find command
                std::cin >> x; // Read key to find
                if (find(root, x)) std::cout << "yes\n"; // Print "yes" if found
                else std::cout << "no\n"; // Print "no" if not found
                break;
            case 'p': // Print command
                print(root); // Print the treap
                break;
        }
    }
    return 0; // Exit the program
}

// <END-OF-CODE>
