import java.util.*;

public class Main {
  // Define a structure to represent a node in the tree
  static class node{
    int l, r, par;  // l: left child, r: right child, par: parent
  }

  static node N[] = new node[25];  // Array to hold the nodes of the tree

  // Function prototypes for tree operations
  static void init(int n);
  static void Preorder(int p);
  static void Inorder(int p);
  static void Postorder(int p);

  public static void main(String[] args) {
    int n, i, id, l, r;  // Variables for number of nodes, node id, left and right children
    int p;  // Variable to hold the root node id

    // Read the number of nodes in the tree
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    init(n);  // Initialize the tree nodes

    // Read the tree structure from input
    for(i = 0; i < n; i++){
      id = sc.nextInt();
      l = sc.nextInt();
      r = sc.nextInt();

      // If left child is not -1, set the left child and parent
      if(l!= -1){
        N[id].l = l;  // Set left child
        N[l].par = id;  // Set parent of left child
      }
      // If right child is not -1, set the right child and parent
      if(r!= -1){
        N[id].r = r;  // Set right child
        N[r].par = id;  // Set parent of right child
      }
    }

    // Find the root of the tree (the node with no parent)
    for(i = 0; i < n; i++){
      if(N[i].par == -1){
        p = i;  // Store the root node id
        break;  // Exit the loop once the root is found
      }
    }

    // Perform and display the tree traversals
    System.out.println("Preorder");
    Preorder(p);  // Call Preorder traversal starting from the root
    System.out.println("");

    System.out.println("Inorder");
    Inorder(p);  // Call Inorder traversal starting from the root
    System.out.println("");

    System.out.println("Postorder");
    Postorder(p);  // Call Postorder traversal starting from the root
    System.out.println("");
  }

  // Function to initialize the tree nodes
  static void init(int n){
    int i;

    // Set parent, left, and right of each node to -1 (indicating no children)
    for(i = 0; i < n; i++){
      N[i].par = N[i].l = N[i].r = -1;
    }
  }

  // Preorder traversal: Root -> Left -> Right
  static void Preorder(int p){
    if(p!= -1){  // Check if the node is valid
      System.out.printf(" %d", p);  // Print the current node
      Preorder(N[p].l);  // Recursively traverse the left subtree
      Preorder(N[p].r);  // Recursively traverse the right subtree
    }
  }

  // Inorder traversal: Left -> Root -> Right
  static void Inorder(int p){
    if(p!= -1){  // Check if the node is valid
      Inorder(N[p].l);  // Recursively traverse the left subtree
      System.out.printf(" %d", p);  // Print the current node
      Inorder(N[p].r);  // Recursively traverse the right subtree
    }
  }

  // Postorder traversal: Left -> Right -> Root
  static void Postorder(int p){
    if(p!= -1){  // Check if the node is valid
      Postorder(N[p].l);  // Recursively traverse the left subtree
      Postorder(N[p].r);  // Recursively traverse the right subtree
      System.out.printf(" %d", p);  // Print the current node
    }
  }
}

