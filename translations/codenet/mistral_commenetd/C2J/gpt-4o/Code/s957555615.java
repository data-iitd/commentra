// Define a node class for AVL tree
class Node {
    Node right;  // pointer to the right child
    Node left;   // pointer to the left child
    Node parent; // pointer to the parent node
    int key;     // key value of the node

    // Constructor to initialize a node
    public Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.parent = null;
    }
}

public class AVLTree {
    Node root; // Initialize root as null

    // Function to find the minimum node in the tree
    public Node treeMinimum(Node x) {
        // Traverse to the left most node
        while (x.left != null) {
            x = x.left;
        }
        // Return the minimum node
        return x;
    }

    // Function to find the maximum node in the tree
    public Node treeMaximum(Node x) {
        // Traverse to the right most node
        while (x.right != null) {
            x = x.right;
        }
        // Return the maximum node
        return x;
    }
}

// <END-OF-CODE>
