#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the binary search tree
class Node{
  Node right; // Pointer to the right child
  Node left;  // Pointer to the left child
  Node parent; // Pointer to the parent node
  int key;            // Key value of the node

  public Node(int k){
    key = k;
    right = null;
    left = null;
    parent = null;
  }
}

Node root; // Root of the binary search tree

// Function to find the minimum node in a subtree
Node treeMinimum(Node x){
  while(x.left != null) // Traverse to the leftmost node
    x = x.left;
  return x; // Return the minimum node
}

// Function to find the maximum node in a subtree
Node treeMaximum(Node x){
  while(x.right != null) // Traverse to the rightmost node
    x = x.right;
  return x; // Return the maximum node
}

// Function to search for a node with a specific key in the tree
Node treeSearch(Node u, int k){
  if(u == null || k == u.key) // Base case: found the node or reached a leaf
    return u;

  // Recursively search in the left or right subtree based on the key
  if(k < u.key) 
    return treeSearch(u.left, k);
  else 
    return treeSearch(u.right, k);
}

// Function to find the successor of a given node in the binary search tree
Node treeSuccessor(Node x){
  Node y;
  if(x.right != null) // If right child exists, successor is the minimum in the right subtree
    return treeMinimum(x.right);
  
  y = x.parent; // Start with the parent of the current node
  // Traverse up the tree until we find a node that is a left child
  while(y != null && x == y.right){
    x = y;
    y = y.parent;
  }
  return y; // Return the successor node
}

// Function to delete a node from the binary search tree
void treeDelete(Node z){
  Node y; // Node to be deleted
  Node x; // Child of y

  // Determine the node to delete (y) based on the number of children
  if(z.left == null || z.right == null) 
    y = z; // If z has one or no children, y is z
  else 
    y = treeSuccessor(z); // If z has two children, find its successor

  // Determine the child of y
  if(y.left != null) 
    x = y.left;
  else 
    x = y.right;

  // Update the parent of x if it exists
  if(x != null) 
    x.parent = y.parent;

  // Update the parent's child pointer to x
  if(y.parent == null) 
    root = x; // If y is root, update root
  else if(y == y.parent.left) 
    y.parent.left = x; // If y is a left child, update left pointer
  else 
    y.parent.right = x; // If y is a right child, update right pointer

  // Copy the key from y to z if they are different
  if(y != z) 
    z.key = y.key;
}

// Function to insert a new key into the binary search tree
void insert(int k){
  Node y = null; // Parent node
  Node x = root; // Current node
  Node z; // New node to be inserted

  // Allocate memory for the new node and set its key
  z = new Node(k);

  // Find the appropriate position for the new node
  while (x != null){
    y = x; // Keep track of the parent
    if(z.key < x.key){
      x = x.left; // Move to the left child
    }
    else{
      x = x.right; // Move to the right child
    }
  }
  z.parent = y; // Set the parent of the new node
  if(y == null) 
    root = z; // If tree was empty, new node is root
  else if(z.key < y.key) 
    y.left = z; // Insert as left child
  else 
    y.right = z; // Insert as right child
}

// Function for inorder traversal of the tree
void inorder(Node u){
  if(u == null) return; // Base case: if the node is null, return
  inorder(u.left); // Traverse left subtree
  System.out.print(" " + u.key); // Print the key of the current node
  inorder(u.right); // Traverse right subtree
}

// Function for preorder traversal of the tree
void preorder(Node u){
  if(u == null) return; // Base case: if the node is null, return
  System.out.print(" " + u.key); // Print the key of the current node
  preorder(u.left); // Traverse left subtree
  preorder(u.right); // Traverse right subtree
}

// Main function to execute the program
public static void main(String[] args){
  int n, i, x; // Variables for number of commands, loop index, and key value
  String com; // Array to hold command strings
  Scanner sc = new Scanner(System.in); // Create a scanner to read input
  n = sc.nextInt(); // Read the number of commands

  // Loop to process each command
  for (i = 0; i < n; i++){
    com = sc.next(); // Read the command
    if (com.equals("find")){ // If command is 'find'
      x = sc.nextInt(); // Read the key to find
      Node t = treeSearch(root, x); // Search for the key
      if (t != null) 
        System.out.println("yes"); // Key found
      else 
        System.out.println("no"); // Key not found
    } else if (com.equals("insert")){ // If command is 'insert'
      x = sc.nextInt(); // Read the key to insert
      insert(x); // Insert the key into the tree
    } else if (com.equals("print")){ // If command is 'print'
      inorder(root); // Print the tree in inorder
      System.out.println();
      preorder(root); // Print the tree in preorder
      System.out.println();
    } else if (com.equals("delete")){ // If command is 'delete'
      x = sc.nextInt(); // Read the key to delete
      treeDelete(treeSearch(root, x)); // Delete the node with the key
    }
  }

  sc.close(); // Close the scanner
  return; // Exit the program
}

