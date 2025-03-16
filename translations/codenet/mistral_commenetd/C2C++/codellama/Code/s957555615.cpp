#include<iostream>
#include<stdlib.h>

// Define a node structure for AVL tree
struct node{
  struct node *right; // pointer to the right child
  struct node *left;  // pointer to the left child
  struct node *parent; // pointer to the parent node
  int key;            // key value of the node
};
typedef struct node * Node;
#define NIL NULL

Node root; // Initialize root as NULL

// Function to find the minimum node in the tree
Node treeMinimum(Node x){
  // Traverse to the left most node
  while(x->left!=NIL) x=x->left;
  // Return the minimum node
  return x;

}

// Function to find the maximum node in the tree
Node treeMaximum(Node x){
  // Traverse to the right most node
  while(x->right!=NIL) x=x->right;
  // Return the maximum node
  return x;

}

