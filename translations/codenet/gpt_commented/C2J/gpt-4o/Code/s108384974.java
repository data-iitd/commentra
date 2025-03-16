import java.util.Scanner;

// Define the structure for a node in the binary search tree
class Node {
    int key;                // The key value of the node
    Node p;                // Pointer to the parent node
    Node l;                // Pointer to the left child
    Node r;                // Pointer to the right child

    // Constructor to initialize a new node
    Node(int key) {
        this.key = key;
        this.l = null;
        this.r = null;
        this.p = null;
    }
}

// Define a class for the binary search tree
public class BinarySearchTree {
    private Node r;        // Root of the tree
    private Node NIL;      // Sentinel NIL node

    // Constructor to initialize the tree
    public BinarySearchTree() {
        this.NIL = new Node(-1); // Create a sentinel NIL node
        this.r = NIL;            // Initially, the tree is empty
    }

    // Function to find a node with a specific key in the binary search tree
    private Node find(Node x, int k) {
        // Traverse the tree until the key is found or a NIL node is reached
        while (x != NIL && k != x.key) {
            if (k < x.key) {
                x = x.l;  // Move to the left child if the key is smaller
            } else {
                x = x.r;  // Move to the right child if the key is larger
            }
        }
        return x;  // Return the found node or NIL if not found
    }

    // Function to insert a new key into the binary search tree
    public void insert(int k) {
        Node y = NIL;  // Parent node of the new node
        Node x = r;    // Start from the root

        // Allocate memory for the new node and initialize its fields
        Node z = new Node(k);

        // Find the appropriate position for the new node
        while (x != NIL) {
            y = x;  // Keep track of the parent node
            if (z.key < x.key) {
                x = x.l;  // Move to the left child
            } else {
                x = x.r;  // Move to the right child
            }
        }
        z.p = y;  // Set the parent of the new node

        // Insert the new node in the tree
        if (y == NIL) {
            r = z;  // Tree was empty, new node becomes the root
        } else if (z.key < y.key) {
            y.l = z;  // Insert as the left child
        } else {
            y.r = z;  // Insert as the right child
        }
    }

    // Function to perform an inorder traversal of the tree
    private void inorder(Node u) {
        if (u == NIL) {
            return;  // Base case: if the node is NIL, return
        }
        inorder(u.l);  // Traverse the left subtree
        System.out.print(" " + u.key);  // Visit the current node
        inorder(u.r);  // Traverse the right subtree
    }

    // Function to perform a preorder traversal of the tree
    private void preorder(Node u) {
        if (u == NIL) {
            return;  // Base case: if the node is NIL, return
        }
        System.out.print(" " + u.key);  // Visit the current node
        preorder(u.l);  // Traverse the left subtree
        preorder(u.r);  // Traverse the right subtree
    }

    // Function to print the tree in both inorder and preorder
    public void print() {
        inorder(r);  // Print the inorder traversal
        System.out.println(); // New line after inorder
        preorder(r); // Print the preorder traversal
        System.out.println(); // New line after preorder
    }

    // Main function to drive the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree bst = new BinarySearchTree();
        int n = scanner.nextInt(); // Read the number of operations to perform

        for (int i = 0; i < n; i++) {
            String command = scanner.next(); // Read the command
            if (command.equals("find")) {  // If the command is 'find'
                int x = scanner.nextInt();  // Read the key to find
                Node t = bst.find(bst.r, x);  // Search for the key
                if (t == bst.NIL) {
                    System.out.println("no");  // Key not found
                } else {
                    System.out.println("yes");  // Key found
                }
            } else if (command.equals("insert")) {  // If the command is 'insert'
                int z = scanner.nextInt();  // Read the key to insert
                bst.insert(z);  // Insert the key into the tree
            } else {  // If the command is 'print'
                bst.print();  // Print the tree
            }
        }
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
