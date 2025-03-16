#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the binary search tree
struct node {
  int key;                // The key value of the node
  struct node *p;        // Pointer to the parent node
  struct node *l;        // Pointer to the left child
  struct node *r;        // Pointer to the right child
};

// Define a type for a pointer to a node
typedef struct node *NodePointer;

// Global variables for the root of the tree and a sentinel NIL node
NodePointer r, NIL;

// Function to find a node with a specific key in the binary search tree
NodePointer find(NodePointer x, int k) {
  // Traverse the tree until the key is found or a NIL node is reached
  while (x != NIL && k != x->key) {
    if (k < x->key) {
      x = x->l;  // Move to the left child if the key is smaller
    } else {
      x = x->r;  // Move to the right child if the key is larger
    }
  }
  return x;  // Return the found node or NIL if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
  NodePointer y = NIL;  // Parent node of the new node
  NodePointer x = r;    // Start from the root

  // Allocate memory for the new node and initialize its fields
  NodePointer z = (NodePointer)malloc(sizeof(struct node));
  z->key = k;
  z->l = NIL;
  z->r = NIL;

  // Find the appropriate position for the new node
  while (x != NIL) {
    y = x;  // Keep track of the parent node
    if (z->key < x->key) {
      x = x->l;  // Move to the left child
    } else {
      x = x->r;  // Move to the right child
    }
  }
  z->p = y;  // Set the parent of the new node
  
  // Insert the new node in the tree
  if (y == NIL) {
    r = z;  // Tree was empty, new node becomes the root
  } else if (z->key < y->key) {
    y->l = z;  // Insert as the left child
  } else {
    y->r = z;  // Insert as the right child
  }
}

// Function to perform an inorder traversal of the tree
void inorder(NodePointer u) {
  if (u == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  inorder(u->l);  // Traverse the left subtree
  printf(" %d", u->key);  // Visit the current node
  inorder(u->r);  // Traverse the right subtree
}

// Function to perform a preorder traversal of the tree
void preorder(NodePointer u) {
  if (u == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  printf(" %d", u->key);  // Visit the current node
  preorder(u->l);  // Traverse the left subtree
  preorder(u->r);  // Traverse the right subtree
}

// Function to print the tree in both inorder and preorder
void print() {
  inorder(r);  // Print the inorder traversal
  puts("");    // New line after inorder
  preorder(r); // Print the preorder traversal
  puts("");    // New line after preorder
}

// Main function to drive the program
int main() {
  int n, i, j, z, x;  // Declare variables for input
  char s[10];        // Array to hold command strings

  // Read the number of operations to perform
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s);  // Read the command
    if (s[0] == 'f') {  // If the command is 'find'
      scanf("%d", &x);  // Read the key to find
      NodePointer t = find(r, x);  // Search for the key
      if (t == NIL) printf("no\n");  // Key not found
      else printf("yes\n");  // Key found

    } else if (s[0] == 'i') {  // If the command is 'insert'
      scanf("%d", &z);  // Read the key to insert
      insert(z);  // Insert the key into the tree
    } else {  // If the command is 'print'
      print();  // Print the tree
    }
  }

  return 0;  // Exit the program
}
