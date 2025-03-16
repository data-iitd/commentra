
#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the binary search tree
class Node{
  int key;          // The key value of the node
  Node p;   // Pointer to the parent node
  Node l;   // Pointer to the left child node
  Node r;   // Pointer to the right child node

  public Node(int k, Node p, Node l, Node r){
    this.key = k;
    this.p = p;
    this.l = l;
    this.r = r;
  }

  public Node(int k){
    this(k, null, null, null);
  }

  public Node(){
    this(0, null, null, null);
  }

  public int getKey(){
    return key;
  }

  public Node getParent(){
    return p;
  }

  public Node getLeft(){
    return l;
  }

  public Node getRight(){
    return r;
  }

  public void setKey(int k){
    key = k;
  }

  public void setParent(Node p){
    this.p = p;
  }

  public void setLeft(Node l){
    this.l = l;
  }

  public void setRight(Node r){
    this.r = r;
  }
}

// Alias for the structure pointer
class NodePointer{
  Node n;

  public NodePointer(Node n){
    this.n = n;
  }

  public NodePointer(){
    this(null);
  }

  public Node getNode(){
    return n;
  }

  public void setNode(Node n){
    this.n = n;
  }
}

// Global variables for the root of the tree and a NIL pointer
NodePointer r, NIL;

// Function to find a node with a given key in the binary search tree
NodePointer find(NodePointer x, int k) {
  while (x.getNode() != NIL && k != x.getNode().getKey()) {
    if (k < x.getNode().getKey()) {
      x = new NodePointer(x.getNode().getLeft());  // Move to the left child if the key is smaller
    } else {
      x = new NodePointer(x.getNode().getRight());  // Move to the right child if the key is larger
    }
  }
  return x;  // Return the node with the key or NIL if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
  NodePointer y = NIL;  // Parent of the new node
  NodePointer x = r;    // Start from the root

  Node z = new Node(k);  // Allocate memory for the new node
  z.setLeft(NIL);  // Initialize left child to NIL
  z.setRight(NIL);  // Initialize right child to NIL

  // Find the position to insert the new node
  while (x.getNode() != NIL) {
    y = x;  // Update the parent of the new node
    if (z.getKey() < x.getNode().getKey()) {
      x = new NodePointer(x.getNode().getLeft());  // Move to the left child if the key is smaller
    } else {
      x = new NodePointer(x.getNode().getRight());  // Move to the right child if the key is larger
    }
  }
  z.setParent(y.getNode());  // Set the parent of the new node

  if (y.getNode() == NIL) {
    r = new NodePointer(z);  // If the tree was empty, the new node becomes the root
  } else if (z.getKey() < y.getNode().getKey()) {
    y.getNode().setLeft(z);  // Insert as the left child if the key is smaller
  } else {
    y.getNode().setRight(z);  // Insert as the right child if the key is larger
  }
}

// Function to perform an inorder traversal of the tree and print the keys
void inorder(NodePointer u) {
  if (u.getNode() == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  inorder(new NodePointer(u.getNode().getLeft()));  // Recursively traverse the left subtree
  System.out.print(" " + u.getNode().getKey());  // Print the key of the current node
  inorder(new NodePointer(u.getNode().getRight()));  // Recursively traverse the right subtree
}

// Function to perform a preorder traversal of the tree and print the keys
void preorder(NodePointer u) {
  if (u.getNode() == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  System.out.print(" " + u.getNode().getKey());  // Print the key of the current node
  preorder(new NodePointer(u.getNode().getLeft()));  // Recursively traverse the left subtree
  preorder(new NodePointer(u.getNode().getRight()));  // Recursively traverse the right subtree
}

// Function to print the tree in both inorder and preorder traversals
void print() {
  inorder(r);  // Perform inorder traversal
  System.out.println("");  // Print a newline
  preorder(r);  // Perform preorder traversal
  System.out.println("");  // Print a newline
}

// Main function to execute the program
public class Main {
  public static void main(String[] args) {
    int n, i, j, z, x;
    String s;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();  // Read the number of operations
    for (i = 0; i < n; i++) {
      s = sc.next();  // Read the command
      if (s.charAt(0) == 'f') {
        x = sc.nextInt();  // Read the key to find
        NodePointer t = find(r, x);  // Find the key in the tree
        if (t.getNode() == NIL) System.out.println("no");  // Print "no" if not found
        else System.out.println("yes");  // Print "yes" if found

      } else if (s.charAt(0) == 'i') {
        z = sc.nextInt();  // Read the key to insert
        insert(z);  // Insert the key into the tree
      } else {
        print();  // Print the tree in both traversals
      }
    }
  }
}

