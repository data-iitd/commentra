
// Define the structure for a node in the AVL tree
class Node{
  int key; // The key value of the node
  Node p; // Pointer to the parent node
  Node l; // Pointer to the left child node
  Node r; // Pointer to the right child node

  // Constructor to initialize the node
  Node(int k){
    key = k;
    p = null;
    l = null;
    r = null;
  }
}

// Define the AVL tree class
class AVL{
  Node r = null; // Initialize the root and NIL pointers
  Node NIL = null;

  // Function to find a node with given key in the AVL tree
  Node find(Node x,int k){
    while(x != NIL && k != x.key){ // Search for the node with the given key
      if(k < x.key){ // If the key is less than the current node's key
        x = x.l; // Move to the left subtree
      }else{
        x = x.r; // Move to the right subtree
      }
    }
    return x; // Return the node if found, otherwise return NIL
  }

  // Function to insert a new node with given key into the AVL tree
  void insert(int k){
    Node y = NIL, x = r; // Initialize y and x pointers
    Node z = new Node(k); // Allocate memory for the new node

    z.p = y;

    // Traverse down the tree to find the position for the new node
    while(x != NIL){
      y = x; // Move y pointer one level up
      if(z.key < x.key){ // If the new key is less than the current node's key
        x = x.l; // Move to the left subtree
      }else{
        x = x.r; // Move to the right subtree
      }
    }

    // Link the new node to its parent node
    z.p = y;

    // Update the left or right child of the parent node
    if(y == null){
      r = z; // If y is NIL, the new node is the root
    }else if(z.key < y.key){
      y.l = z;
    }else{
      y.r = z;
    }
  }

  // Function to perform inorder traversal of the AVL tree and print the keys
  void inorder(Node u){
    if(u == null){ // Base case: if the tree is empty, return
      return;
    }
    inorder(u.l); // Recursively traverse the left subtree
    System.out.print(" " + u.key); // Print the key of the current node
    inorder(u.r); // Recursively traverse the right subtree
  }

  // Function to perform preorder traversal of the AVL tree and print the keys
  void preorder(Node u){
    if(u == null){ // Base case: if the tree is empty, return
      return;
    }
    System.out.print(" " + u.key); // Print the key of the current node
    preorder(u.l); // Recursively traverse the left subtree
    preorder(u.r); // Recursively traverse the right subtree
  }

  // Function to print the keys of the AVL tree in inorder and preorder traversals
  void print(){
    inorder(r); // Perform inorder traversal and print the keys
    System.out.println(); // Print a newline character
    preorder(r); // Perform preorder traversal and print the keys
    System.out.println(); // Print a newline character
  }

  // Main function to read commands from the standard input and perform the corresponding operations
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in); // Create a Scanner object to read from the standard input
    int n = sc.nextInt(); // Read the number of commands from the standard input
    AVL avl = new AVL(); // Create an AVL tree object

    for(int i=0;i<n;i++){ // Iterate through each command
      String s = sc.next(); // Read the command string from the standard input

      if(s.equals("f")){ // If the command is to find a node
        int x = sc.nextInt(); // Read the key value to search for
        Node t = avl.find(avl.r,x); // Find the node with the given key
        if(t == null){ // If the node is not found
          System.out.println("no");
        }else{ // If the node is found
          System.out.println("yes");
        }

      }else if(s.equals("i")){ // If the command is to insert a new node
        int z = sc.nextInt(); // Read the key value of the new node
        avl.insert(z); // Insert the new node into the AVL tree

      }else{ // If the command is to print the keys of the AVL tree
        avl.print(); // Print the keys in inorder and preorder traversals
      }
    }
    sc.close(); // Close the Scanner object
  }
}

