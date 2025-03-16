import java.util.Scanner;

// Define the structure for a node in the binary search tree
class Node {
    int key;          // The key value of the node
    Node p;          // Pointer to the parent node
    Node l;          // Pointer to the left child node
    Node r;          // Pointer to the right child node

    // Constructor to initialize a new node
    Node(int key) {
        this.key = key;
        this.l = null; // Initialize left child to null
        this.r = null; // Initialize right child to null
        this.p = null; // Initialize parent to null
    }
}

public class BinarySearchTree {
    private Node r; // Root of the tree
    private Node NIL; // NIL pointer

    // Constructor to initialize the tree
    public BinarySearchTree() {
        this.NIL = null; // In Java, we can use null as NIL
        this.r = NIL; // Initialize root to NIL
    }

    // Function to find a node with a given key in the binary search tree
    private Node find(Node x, int k) {
        while (x != NIL && k != x.key) {
            if (k < x.key) {
                x = x.l; // Move to the left child if the key is smaller
            } else {
                x = x.r; // Move to the right child if the key is larger
            }
        }
        return x; // Return the node with the key or NIL if not found
    }

    // Function to insert a new key into the binary search tree
    public void insert(int k) {
        Node y = NIL; // Parent of the new node
        Node x = r;   // Start from the root

        Node z = new Node(k); // Create a new node

        // Find the position to insert the new node
        while (x != NIL) {
            y = x; // Update the parent of the new node
            if (z.key < x.key) {
                x = x.l; // Move to the left child if the key is smaller
            } else {
                x = x.r; // Move to the right child if the key is larger
            }
        }
        z.p = y; // Set the parent of the new node

        if (y == NIL) {
            r = z; // If the tree was empty, the new node becomes the root
        } else if (z.key < y.key) {
            y.l = z; // Insert as the left child if the key is smaller
        } else {
            y.r = z; // Insert as the right child if the key is larger
        }
    }

    // Function to perform an inorder traversal of the tree and print the keys
    private void inorder(Node u) {
        if (u == NIL) {
            return; // Base case: if the node is NIL, return
        }
        inorder(u.l); // Recursively traverse the left subtree
        System.out.print(" " + u.key); // Print the key of the current node
        inorder(u.r); // Recursively traverse the right subtree
    }

    // Function to perform a preorder traversal of the tree and print the keys
    private void preorder(Node u) {
        if (u == NIL) {
            return; // Base case: if the node is NIL, return
        }
        System.out.print(" " + u.key); // Print the key of the current node
        preorder(u.l); // Recursively traverse the left subtree
        preorder(u.r); // Recursively traverse the right subtree
    }

    // Function to print the tree in both inorder and preorder traversals
    public void print() {
        inorder(r); // Perform inorder traversal
        System.out.println(); // Print a newline
        preorder(r); // Perform preorder traversal
        System.out.println(); // Print a newline
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree bst = new BinarySearchTree();
        int n = scanner.nextInt(); // Read the number of operations

        for (int i = 0; i < n; i++) {
            String command = scanner.next(); // Read the command
            if (command.charAt(0) == 'f') {
                int x = scanner.nextInt(); // Read the key to find
                Node t = bst.find(bst.r, x); // Find the key in the tree
                if (t == bst.NIL) {
                    System.out.println("no"); // Print "no" if not found
                } else {
                    System.out.println("yes"); // Print "yes" if found
                }
            } else if (command.charAt(0) == 'i') {
                int z = scanner.nextInt(); // Read the key to insert
                bst.insert(z); // Insert the key into the tree
            } else {
                bst.print(); // Print the tree in both traversals
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
