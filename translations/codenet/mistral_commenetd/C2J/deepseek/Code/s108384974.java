import java.util.Scanner;

// Define the class for a node in the AVL tree
class Node {
    int key; // The key value of the node
    Node p; // Pointer to the parent node
    Node l; // Pointer to the left child node
    Node r; // Pointer to the right child node

    Node(int key) {
        this.key = key;
        this.p = null;
        this.l = null;
        this.r = null;
    }
}

// Define the class for the AVL tree
class AVLTree {
    Node r = null; // Initialize the root pointer

    // Function to find a node with given key in the AVL tree
    Node find(Node x, int k) {
        while (x != null && k != x.key) {
            if (k < x.key) {
                x = x.l; // Move to the left subtree
            } else {
                x = x.r; // Move to the right subtree
            }
        }
        return x; // Return the node if found, otherwise return null
    }

    // Function to insert a new node with given key into the AVL tree
    void insert(int k) {
        Node y = null; // Initialize y pointer
        Node x = r; // Initialize x pointer
        Node z = new Node(k); // Create a new node with the given key

        // Traverse down the tree to find the position for the new node
        while (x != null) {
            y = x; // Move y pointer one level up
            if (z.key < x.key) { // If the new key is less than the current node's key
                x = x.l; // Move to the left subtree
            } else {
                x = x.r; // Move to the right subtree
            }
        }

        // Link the new node to its parent node
        z.p = y;

        // Update the left or right child of the parent node
        if (y == null) {
            r = z; // If y is null, the new node is the root
        } else if (z.key < y.key) {
            y.l = z;
        } else {
            y.r = z;
        }
    }

    // Function to perform inorder traversal of the AVL tree and print the keys
    void inorder(Node u) {
        if (u == null) { // Base case: if the tree is empty, return
            return;
        }
        inorder(u.l); // Recursively traverse the left subtree
        System.out.print(" " + u.key); // Print the key of the current node
        inorder(u.r); // Recursively traverse the right subtree
    }

    // Function to perform preorder traversal of the AVL tree and print the keys
    void preorder(Node u) {
        if (u == null) { // Base case: if the tree is empty, return
            return;
        }
        System.out.print(" " + u.key); // Print the key of the current node
        preorder(u.l); // Recursively traverse the left subtree
        preorder(u.r); // Recursively traverse the right subtree
    }

    // Function to print the keys of the AVL tree in inorder and preorder traversals
    void print() {
        inorder(r); // Perform inorder traversal and print the keys
        System.out.println(); // Print a newline character
        preorder(r); // Perform preorder traversal and print the keys
        System.out.println(); // Print a newline character
    }
}

// Main class to read commands from the standard input and perform the corresponding operations
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        AVLTree tree = new AVLTree();
        int n = scanner.nextInt(); // Read the number of commands from the standard input
        for (int i = 0; i < n; i++) {
            String s = scanner.next(); // Read the command string from the standard input
            if (s.equals("find")) { // If the command is to find a node
                int x = scanner.nextInt(); // Read the key value to search for
                Node t = tree.find(tree.r, x); // Find the node with the given key
                if (t == null) { // If the node is not found
                    System.out.println("no");
                } else { // If the node is found
                    System.out.println("yes");
                }
            } else if (s.equals("insert")) { // If the command is to insert a new node
                int z = scanner.nextInt(); // Read the key value of the new node
                tree.insert(z); // Insert the new node into the AVL tree
            } else { // If the command is to print the keys of the AVL tree
                tree.print(); // Print the keys in inorder and preorder traversals
            }
        }
        scanner.close(); // Close the scanner
    }
}
