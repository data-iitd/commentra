<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

// Define a node structure for AVL tree
type node struct {
  right *node
  left *node
  parent *node
  key int
}

var root *node

// Function to find the minimum node in the tree
func treeMinimum(x *node) *node {
  // Traverse to the left most node
  for x.left!= nil {
    x = x.left
  }
  // Return the minimum node
  return x
}

// Function to find the maximum node in the tree
func treeMaximum(x *node) *node {
  // Traverse to the right most node
  for x.right!= nil {
    x = x.right
  }
  // Return the maximum node
  return x
}

