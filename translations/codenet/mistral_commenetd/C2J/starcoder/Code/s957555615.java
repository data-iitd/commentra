
// Define a node structure for AVL tree
class Node{
  Node left, right, parent;
  int key;
}

Node root; // Initialize root as NULL

// Function to find the minimum node in the tree
Node treeMinimum(Node x){
  // Traverse to the left most node
  while(x.left!=null) x=x.left;
  // Return the minimum node
  return x;

}

// Function to find the maximum node in the tree
Node treeMaximum(Node x){
  // Traverse to the right most node
  while(x.right!=null) x=x.right;
  // Return the maximum node
  return x;

}

