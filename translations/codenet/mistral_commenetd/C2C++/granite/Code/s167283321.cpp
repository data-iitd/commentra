
#include <iostream>
#define NIL -1

// Define a structure for a node in the binary tree
struct Node {
  int parent, left, right;
};

// Initialize an array of nodes R with size 10000
struct Node R[10000];

// Set the number of nodes n
int n;

// Recursive function to perform preorder traversal
void preorder(int x) {
  // Base case: if x is NIL, return
  if (x == NIL)
    return;

  // Print the current node x
  std::cout << " " << x;

  // Recursively traverse the left subtree
  preorder(R[x].left);

  // Recursively traverse the right subtree
  preorder(R[x].right);
}

// Recursive function to perform inorder traversal
void inorder(int x) {
  // Base case: if x is NIL, return
  if (x == NIL)
    return;

  // Recursively traverse the left subtree
  inorder(R[x].left);

  // Print the current node x
  std::cout << " " << x;

  // Recursively traverse the right subtree
  inorder(R[x].right);
}

// Recursive function to perform postorder traversal
void postorder(int x) {
  // Base case: if x is NIL, return
  if (x == NIL)
    return;

  // Recursively traverse the left subtree
  postorder(R[x].left);

  // Recursively traverse the right subtree
  postorder(R[x].right);

  // Print the current node x
  std::cout << " " << x;
}

// Main function to read input and call traversal functions
int main() {
  int i, a, b, c, root;

  // Read the number of nodes n
  std::cin >> n;

  // Initialize all nodes as NIL
  for (i = 0; i < n; i++)
    R[i].parent = NIL;

  // Read the edges and build the tree
  for (i = 0; i < n; i++) {
    std::cin >> a >> b >> c;
    R[a].left = b;
    R[a].right = c;
    if (b!= NIL)
      R[b].parent = a; // Set the parent of left child
    if (c!= NIL)
      R[c].parent = a; // Set the parent of right child
  }

  // Find the root node by searching for the node with no parent
  for (i = 0; i < n; i++) {
    if (R[i].parent == NIL) {
      root = i;
      break;
    }
  }

  // Perform preorder traversal and print the result
  std::cout << "Preorder\n";
  preorder(root);
  std::cout << "\n";

  // Perform inorder traversal and print the result
  std::cout << "Inorder\n";
  inorder(root);
  std::cout << "\n";

  // Perform postorder traversal and print the result
  std::cout << "Postorder\n";
  postorder(root);
  std::cout << "\n";

  // Return 0 to indicate successful execution
  return 0;
}

