
#include<bits/stdc++.h>

using namespace std;

// Define the structure for a node in the AVL tree
struct node{
  int key; // The key value of the node
  struct node *p; // Pointer to the parent node
  struct node *l; // Pointer to the left child node
  struct node *r; // Pointer to the right child node
};

typedef struct node *NodePointer; // Define a NodePointer type

NodePointer r = NULL, NIL = NULL; // Initialize the root and NIL pointers

// Function to find a node with given key in the AVL tree
NodePointer find(NodePointer x,int k){
  while(x!= NIL && k!= x->key){ // Search for the node with the given key
    if(k < x->key){ // If the key is less than the current node's key
      x = x->l; // Move to the left subtree
    }else{
      x = x->r; // Move to the right subtree
    }
  }
  return x; // Return the node if found, otherwise return NIL
}

// Function to insert a new node with given key into the AVL tree
void insert(int k){
  NodePointer y = NIL, x = r; // Initialize y and x pointers
  NodePointer z = (NodePointer)malloc(sizeof(struct node)); // Allocate memory for the new node

  z->key = k; // Set the key value of the new node
  z->l = NIL; // Initialize the left and right child pointers of the new node
  z->r = NIL;

  // Traverse down the tree to find the position for the new node
  while(x!= NIL){
    y = x; // Move y pointer one level up
    if(z->key < x->key){ // If the new key is less than the current node's key
      x = x->l; // Move to the left subtree
    }else{
      x = x->r; // Move to the right subtree
    }
  }

  // Link the new node to its parent node
  z->p = y;

  // Update the left or right child of the parent node
  if(y == NULL){
    r = z; // If y is NIL, the new node is the root
  }else if(z->key < y->key){
    y->l = z;
  }else{
    y->r = z;
  }
}

// Function to perform inorder traversal of the AVL tree and print the keys
void inorder(NodePointer u){
  if(u == NULL){ // Base case: if the tree is empty, return
    return;
  }
  inorder(u->l); // Recursively traverse the left subtree
  cout << " " << u->key; // Print the key of the current node
  inorder(u->r); // Recursively traverse the right subtree
}

// Function to perform preorder traversal of the AVL tree and print the keys
void preorder(NodePointer u){
  if(u == NULL){ // Base case: if the tree is empty, return
    return;
  }
  cout << " " << u->key; // Print the key of the current node
  preorder(u->l); // Recursively traverse the left subtree
  preorder(u->r); // Recursively traverse the right subtree
}

// Function to print the keys of the AVL tree in inorder and preorder traversals
void print(){
  inorder(r); // Perform inorder traversal and print the keys
  cout << endl; // Print a newline character
  preorder(r); // Perform preorder traversal and print the keys
  cout << endl; // Print a newline character
}

// Main function to read commands from the standard input and perform the corresponding operations
int main(){
  int n,i,j,z,x; // Declare variables for the number of commands and their arguments
  char s[10]; // Declare a character array to read the command string

  cin >> n; // Read the number of commands from the standard input
  for(i=0;i<n;i++){ // Iterate through each command
    cin >> s; // Read the command string from the standard input

    if(s[0] == 'f'){ // If the command is to find a node
      cin >> x; // Read the key value to search for
      NodePointer t = find(r,x); // Find the node with the given key
      if(t == NULL){ // If the node is not found
        cout << "no" << endl;
      }else{ // If the node is found
        cout << "yes" << endl;
      }

    }else if(s[0] == 'i'){ // If the command is to insert a new node
      cin >> z; // Read the key value of the new node
      insert(z); // Insert the new node into the AVL tree

    }else{ // If the command is to print the keys of the AVL tree
      print(); // Print the keys in inorder and preorder traversals
    }
  }

  return 0; // Return 0 to indicate successful execution of the program
}

