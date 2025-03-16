
// Define the structure for a node in the binary search tree
class Node {
  int key;                // The key value of the node
  Node p;        // Pointer to the parent node
  Node l;        // Pointer to the left child
  Node r;        // Pointer to the right child
}

// Define a type for a pointer to a node
Node r;

// Function to find a node with a specific key in the binary search tree
Node find(Node x, int k) {
  // Traverse the tree until the key is found or a NIL node is reached
  while (x!= null && k!= x.key) {
    if (k < x.key) {
      x = x.l;  // Move to the left child if the key is smaller
    } else {
      x = x.r;  // Move to the right child if the key is larger
    }
  }
  return x;  // Return the found node or NIL if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
  Node y = null;  // Parent node of the new node
  Node x = r;    // Start from the root

  // Allocate memory for the new node and initialize its fields
  Node z = new Node();
  z.key = k;
  z.l = null;
  z.r = null;

  // Find the appropriate position for the new node
  while (x!= null) {
    y = x;  // Keep track of the parent node
    if (z.key < x.key) {
      x = x.l;  // Move to the left child
    } else {
      x = x.r;  // Move to the right child
    }
  }
  z.p = y;  // Set the parent of the new node
  
  // Insert the new node in the tree
  if (y == null) {
    r = z;  // Tree was empty, new node becomes the root
  } else if (z.key < y.key) {
    y.l = z;  // Insert as the left child
  } else {
    y.r = z;  // Insert as the right child
  }
}

// Function to perform an inorder traversal of the tree
void inorder(Node u) {
  if (u == null) {
    return;  // Base case: if the node is NIL, return
  }
  inorder(u.l);  // Traverse the left subtree
  System.out.print(" " + u.key);  // Visit the current node
  inorder(u.r);  // Traverse the right subtree
}

// Function to perform a preorder traversal of the tree
void preorder(Node u) {
  if (u == null) {
    return;  // Base case: if the node is NIL, return
  }
  System.out.print(" " + u.key);  // Visit the current node
  preorder(u.l);  // Traverse the left subtree
  preorder(u.r);  // Traverse the right subtree
}

// Function to print the tree in both inorder and preorder
void print() {
  inorder(r);  // Print the inorder traversal
  System.out.println("");    // New line after inorder
  preorder(r); // Print the preorder traversal
  System.out.println("");    // New line after preorder
}

// Main function to drive the program
public static void main(String[] args) {
  int n, i, j, z, x;  // Declare variables for input
  String s;        // Array to hold command strings

  // Read the number of operations to perform
  Scanner sc = new Scanner(System.in);
  n = sc.nextInt();
  for (i = 0; i < n; i++) {
    s = sc.next();  // Read the command
    if (s.charAt(0) == 'f') {  // If the command is 'find'
      x = sc.nextInt();  // Read the key to find
      Node t = find(r, x);  // Search for the key
      if (t == null) System.out.println("no");  // Key not found
      else System.out.println("yes");  // Key found

    } else if (s.charAt(0) == 'i') {  // If the command is 'insert'
      z = sc.nextInt();  // Read the key to insert
      insert(z);  // Insert the key into the tree
    } else {  // If the command is 'print'
      print();  // Print the tree
    }
  }
}

