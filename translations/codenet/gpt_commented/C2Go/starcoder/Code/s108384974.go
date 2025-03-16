package main

// Define the structure for a node in the binary search tree
type node struct {
  key int
  p   *node
  l   *node
  r   *node
}

// Define a type for a pointer to a node
type NodePointer *node

// Global variables for the root of the tree and a sentinel NIL node
var r, NIL *node

// Function to find a node with a specific key in the binary search tree
func find(x NodePointer, k int) NodePointer {
  // Traverse the tree until the key is found or a NIL node is reached
  for x!= NIL && k!= x.key {
    if k < x.key {
      x = x.l  // Move to the left child if the key is smaller
    } else {
      x = x.r  // Move to the right child if the key is larger
    }
  }
  return x  // Return the found node or NIL if not found
}

// Function to insert a new key into the binary search tree
func insert(k int) {
  y := NIL  // Parent node of the new node
  x := r    // Start from the root

  // Allocate memory for the new node and initialize its fields
  z := new(node)
  z.key = k
  z.l = NIL
  z.r = NIL

  // Find the appropriate position for the new node
  for x!= NIL {
    y = x  // Keep track of the parent node
    if z.key < x.key {
      x = x.l  // Move to the left child
    } else {
      x = x.r  // Move to the right child
    }
  }
  z.p = y  // Set the parent of the new node
  
  // Insert the new node in the tree
  if y == NIL {
    r = z  // Tree was empty, new node becomes the root
  } else if z.key < y.key {
    y.l = z  // Insert as the left child
  } else {
    y.r = z  // Insert as the right child
  }
}

// Function to perform an inorder traversal of the tree
func inorder(u NodePointer) {
  if u == NIL {
    return  // Base case: if the node is NIL, return
  }
  inorder(u.l)  // Traverse the left subtree
  fmt.Printf(" %d", u.key)  // Visit the current node
  inorder(u.r)  // Traverse the right subtree
}

// Function to perform a preorder traversal of the tree
func preorder(u NodePointer) {
  if u == NIL {
    return  // Base case: if the node is NIL, return
  }
  fmt.Printf(" %d", u.key)  // Visit the current node
  preorder(u.l)  // Traverse the left subtree
  preorder(u.r)  // Traverse the right subtree
}

// Function to print the tree in both inorder and preorder
func print() {
  inorder(r)  // Print the inorder traversal
  fmt.Println("")    // New line after inorder
  preorder(r) // Print the preorder traversal
  fmt.Println("")    // New line after preorder
}

// Main function to drive the program
func main() {
  var n, i, j, z, x int  // Declare variables for input
  var s [10]byte        // Array to hold command strings

  // Read the number of operations to perform
  fmt.Scanf("%d", &n)
  for i := 0; i < n; i++ {
    fmt.Scanf("%s", &s)  // Read the command
    if s[0] == 'f' {  // If the command is 'find'
      fmt.Scanf("%d", &x)  // Read the key to find
      t := find(r, x)  // Search for the key
      if t == NIL {
        fmt.Println("no")  // Key not found
      } else {
        fmt.Println("yes")  // Key found
      }

    } else if s[0] == 'i' {  // If the command is 'insert'
      fmt.Scanf("%d", &z)  // Read the key to insert
      insert(z)  // Insert the key into the tree
    } else {  // If the command is 'print'
      print()  // Print the tree
    }
  }
}

