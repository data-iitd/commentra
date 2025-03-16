
// Define the structure for a node in the binary search tree
class Node {
  int key;          // The key value of the node
  Node p;           // Pointer to the parent node
  Node l;           // Pointer to the left child node
  Node r;           // Pointer to the right child node
}

// Global variables for the root of the tree and a NIL pointer
Node r, NIL;

// Function to find a node with a given key in the binary search tree
Node find(Node x, int k) {
  while (x!= NIL && k!= x.key) {
    if (k < x.key) {
      x = x.l;  // Move to the left child if the key is smaller
    } else {
      x = x.r;  // Move to the right child if the key is larger
    }
  }
  return x;  // Return the node with the key or NIL if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
  Node y = NIL;  // Parent of the new node
  Node x = r;    // Start from the root

  Node z = new Node();  // Allocate memory for the new node
  z.key = k;  // Set the key of the new node
  z.l = NIL;  // Initialize left child to NIL
  z.r = NIL;  // Initialize right child to NIL

  // Find the position to insert the new node
  while (x!= NIL) {
    y = x;  // Update the parent of the new node
    if (z.key < x.key) {
      x = x.l;  // Move to the left child if the key is smaller
    } else {
      x = x.r;  // Move to the right child if the key is larger
    }
  }
  z.p = y;  // Set the parent of the new node

  if (y == NIL) {
    r = z;  // If the tree was empty, the new node becomes the root
  } else if (z.key < y.key) {
    y.l = z;  // Insert as the left child if the key is smaller
  } else {
    y.r = z;  // Insert as the right child if the key is larger
  }
}

// Function to perform an inorder traversal of the tree and print the keys
void inorder(Node u) {
  if (u == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  inorder(u.l);  // Recursively traverse the left subtree
  System.out.print(" " + u.key);  // Print the key of the current node
  inorder(u.r);  // Recursively traverse the right subtree
}

// Function to perform a preorder traversal of the tree and print the keys
void preorder(Node u) {
  if (u == NIL) {
    return;  // Base case: if the node is NIL, return
  }
  System.out.print(" " + u.key);  // Print the key of the current node
  preorder(u.l);  // Recursively traverse the left subtree
  preorder(u.r);  // Recursively traverse the right subtree
}

// Function to print the tree in both inorder and preorder traversals
void print() {
  inorder(r);  // Perform inorder traversal
  System.out.println("");  // Print a newline
  preorder(r);  // Perform preorder traversal
  System.out.println("");  // Print a newline
}

// Main function to execute the program
public static void main(String[] args) {
  int n, i, j, z, x;
  String s;

  Scanner sc = new Scanner(System.in);
  n = sc.nextInt();  // Read the number of operations
  for (i = 0; i < n; i++) {
    s = sc.next();  // Read the command
    if (s.charAt(0) == 'f') {
      x = sc.nextInt();  // Read the key to find
      Node t = find(r, x);  // Find the key in the tree
      if (t == NIL) System.out.println("no");  // Print "no" if not found
      else System.out.println("yes");  // Print "yes" if found

    } else if (s.charAt(0) == 'i') {
      z = sc.nextInt();  // Read the key to insert
      insert(z);  // Insert the key into the tree
    } else {
      print();  // Print the tree in both traversals
    }
  }
}

