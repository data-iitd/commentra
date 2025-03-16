#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the binary search tree
struct node{
  int key;          // The key value of the node
  struct node *p;   // Pointer to the parent node
  struct node *l;   // Pointer to the left child node
  struct node *r;   // Pointer to the right child node
};

// Alias for the structure pointer
typedef struct node *NodePointer;

// Global variables for the root of the tree and a NIL pointer
NodePointer r, NIL;

// Function to find a node with a given key in the binary search tree
NodePointer find(NodePointer x, int k) {
  while (x != NIL && k != x->key) {
    if (k < x->key) {
      x = x->l;  // Move to the left child if the key is smaller
    } else {
      x = x->r;  // Move to the right child if the key is larger
    }
  }
  return x;  // Return the node with the key or NIL if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
  NodePointer y = NIL;  // Parent of the new node
  NodePointer x = r;    // Start from the root

  NodePointer z = (NodePointer)malloc(sizeof(struct node));  // Allocate memory for the new node
  z->key = k;  // Set the key of the new node
  z->l = NIL;  // Initialize left child to NIL
  z->r = NIL;  // Initialize right child to NIL

  // Find the position to insert the new node
  while (x != NIL) {
    y = x;  // Update the parent of the new node
    if (z->key < x->key) {
      x = x->l;  // Move to the left child if the key is smaller
    } else {
      x = x->r;  // Move to the right child if the key is larger
    }
  }
  z->p = y;  // Set the parent of the new node

  if (y == NIL) {
    r = z;  // If the tree was empty, the new node becomes the root
  } else if (z->key < y->key) {
    y->l = z;  // Insert as the left child if the key is smaller
  } else {
    y->r = z;  // Insert as the right child if the key is larger
  }
}

// Function to perform an inorder traversal of the tree and print the keys
void inorder(NodePointer u) {
  if (u == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  inorder(u->l);  // Recursively traverse the left subtree
  printf(" %d", u->key);  // Print the key of the current node
  inorder(u->r);  // Recursively traverse the right subtree
}

// Function to perform a preorder traversal of the tree and print the keys
void preorder(NodePointer u) {
  if (u == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  printf(" %d", u->key);  // Print the key of the current node
  preorder(u->l);  // Recursively traverse the left subtree
  preorder(u->r);  // Recursively traverse the right subtree
}

// Function to print the tree in both inorder and preorder traversals
void print() {
  inorder(r);  // Perform inorder traversal
  puts("");  // Print a newline
  preorder(r);  // Perform preorder traversal
  puts("");  // Print a newline
}

// Main function to execute the program
int main() {
  int n, i, j, z, x;
  char s[10];

  scanf("%d", &n);  // Read the number of operations
  for (i = 0; i < n; i++) {
    scanf("%s", s);  // Read the command
    if (s[0] == 'f') {
      scanf("%d", &x);  // Read the key to find
      NodePointer t = find(r, x);  // Find the key in the tree
      if (t == NIL) printf("no\n");  // Print "no" if not found
      else printf("yes\n");  // Print "yes" if found

    } else if (s[0] == 'i') {
      scanf("%d", &z);  // Read the key to insert
      insert(z);  // Insert the key into the tree
    } else {
      print();  // Print the tree in both traversals
    }
  }

  return 0;  // Return 0 to indicate successful execution
}
