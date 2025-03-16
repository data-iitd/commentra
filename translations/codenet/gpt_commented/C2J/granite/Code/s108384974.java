
import java.util.Scanner;

// Define the structure for a node in the binary search tree
class Node {
  int key;                // The key value of the node
  Node parent;           // Pointer to the parent node
  Node left;             // Pointer to the left child
  Node right;            // Pointer to the right child
}

public class s108384974{
  static Node root = null;  // Global variable for the root of the tree

  // Function to find a node with a specific key in the binary search tree
  static Node find(Node x, int k) {
    // Traverse the tree until the key is found or a null node is reached
    while (x!= null && k!= x.key) {
      if (k < x.key) {
        x = x.left;  // Move to the left child if the key is smaller
      } else {
        x = x.right;  // Move to the right child if the key is larger
      }
    }
    return x;  // Return the found node or null if not found
  }

  // Function to insert a new key into the binary search tree
  static void insert(int k) {
    Node y = null;  // Parent node of the new node
    Node x = root;  // Start from the root

    // Allocate memory for the new node and initialize its fields
    Node z = new Node();
    z.key = k;
    z.left = null;
    z.right = null;

    // Find the appropriate position for the new node
    while (x!= null) {
      y = x;  // Keep track of the parent node
      if (z.key < x.key) {
        x = x.left;  // Move to the left child
      } else {
        x = x.right;  // Move to the right child
      }
    }
    z.parent = y;  // Set the parent of the new node

    // Insert the new node in the tree
    if (y == null) {
      root = z;  // Tree was empty, new node becomes the root
    } else if (z.key < y.key) {
      y.left = z;  // Insert as the left child
    } else {
      y.right = z;  // Insert as the right child
    }
  }

  // Function to perform an inorder traversal of the tree
  static void inorder(Node u) {
    if (u == null) {
      return;  // Base case: if the node is null, return
    }
    inorder(u.left);  // Traverse the left subtree
    System.out.print(" " + u.key);  // Visit the current node
    inorder(u.right);  // Traverse the right subtree
  }

  // Function to perform a preorder traversal of the tree
  static void preorder(Node u) {
    if (u == null) {
      return;  // Base case: if the node is null, return
    }
    System.out.print(" " + u.key);  // Visit the current node
    preorder(u.left);  // Traverse the left subtree
    preorder(u.right);  // Traverse the right subtree
  }

  // Function to print the tree in both inorder and preorder
  static void print() {
    inorder(root);  // Print the inorder traversal
    System.out.println();  // New line after inorder
    preorder(root);  // Print the preorder traversal
    System.out.println();  // New line after preorder
  }

  // s108384974 function to drive the program
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n, i, j, z, x;  // Declare variables for input
    String s;  // Variable to hold command strings

    // Read the number of operations to perform
    n = scanner.nextInt();
    for (i = 0; i < n; i++) {
      s = scanner.next();  // Read the command
      if (s.equals("find")) {  // If the command is 'find'
        x = scanner.nextInt();  // Read the key to find
        Node t = find(root, x);  // Search for the key
        if (t == null) System.out.println("no");  // Key not found
        else System.out.println("yes");  // Key found
      } else if (s.equals("insert")) {  // If the command is 'insert'
        z = scanner.nextInt();  // Read the key to insert
        insert(z);  // Insert the key into the tree
      } else {  // If the command is 'print'
        print();  // Print the tree
      }
    }

    scanner.close();  // Close the scanner
  }
}

