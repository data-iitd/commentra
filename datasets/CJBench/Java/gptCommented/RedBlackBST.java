import java.util.Scanner;

public class Main {
    // Constants representing the colors of the nodes
    private static final int RED = 0;
    private static final int BLACK = 1;

    // Inner class representing a node in the Red-Black Tree
    private class Node {
        int key; // The key value of the node
        int color = BLACK; // The color of the node, default is BLACK
        Node left = nil, right = nil, p = nil; // Pointers to left child, right child, and parent

        // Constructor to create a new node with a given key
        Node(int key) {
            this.key = key;
        }
    }

    // Sentinel node representing the nil node (leaf node)
    private final Node nil = new Node(-1);
    private Node root = nil; // The root of the Red-Black Tree

    // Method to print the tree in-order
    public void printTree(Node node) {
        if (node == nil) return; // Base case: if the node is nil, return
        printTree(node.left); // Recursively print the left subtree
        // Print the current node with its color
        System.out.print(((node.color == RED) ? "R " : "B ") + node.key + " ");
        printTree(node.right); // Recursively print the right subtree
    }

    // Method to insert a new key into the Red-Black Tree
    public void insert(int key) {
        Node node = new Node(key); // Create a new node for the key
        Node temp = root; // Start from the root

        // If the tree is empty, set the new node as the root and color it black
        if (root == nil) {
            root = node;
            node.color = BLACK;
        } else {
            node.color = RED; // New nodes are always red
            while (true) {
                // Traverse the tree to find the correct position for the new node
                if (key < temp.key) {
                    if (temp.left == nil) {
                        temp.left = node; // Insert as left child
                        node.p = temp; // Set parent
                        break;
                    }
                    temp = temp.left; // Move to left child
                } else {
                    if (temp.right == nil) {
                        temp.right = node; // Insert as right child
                        node.p = temp; // Set parent
                        break;
                    }
                    temp = temp.right; // Move to right child
                }
            }
            // Fix the tree to maintain Red-Black properties
            fixTree(node);
        }
    }

    // Method to fix the tree after insertion to maintain Red-Black properties
    private void fixTree(Node node) {
        while (node.p.color == RED) { // While the parent is red
            if (node.p == node.p.p.left) { // If the parent is a left child
                Node y = node.p.p.right; // Uncle node
                if (y.color == RED) { // Case 1: Uncle is red
                    // Recoloring
                    node.p.color = BLACK;
                    y.color = BLACK;
                    node.p.p.color = RED;
                    node = node.p.p; // Move up the tree
                } else {
                    // Case 2: Node is a right child
                    if (node == node.p.right) {
                        node = node.p; // Move node up
                        rotateLeft(node); // Perform left rotation
                    }
                    // Case 3: Node is a left child
                    node.p.color = BLACK;
                    node.p.p.color = RED;
                    rotateRight(node.p.p); // Perform right rotation
                }
            } else { // If the parent is a right child
                Node y = node.p.p.left; // Uncle node
                if (y.color == RED) { // Case 1: Uncle is red
                    // Recoloring
                    node.p.color = BLACK;
                    y.color = BLACK;
                    node.p.p.color = RED;
                    node = node.p.p; // Move up the tree
                } else {
                    // Case 2: Node is a left child
                    if (node == node.p.left) {
                        node = node.p; // Move node up
                        rotateRight(node); // Perform right rotation
                    }
                    // Case 3: Node is a right child
                    node.p.color = BLACK;
                    node.p.p.color = RED;
                    rotateLeft(node.p.p); // Perform left rotation
                }
            }
        }
        root.color = BLACK; // Ensure the root is always black
    }

    // Method to perform a left rotation on a given node
    private void rotateLeft(Node node) {
        Node temp = node.right; // Store the right child
        node.right = temp.left; // Move the left child of right to the right of the node
        if (temp.left != nil) temp.left.p = node; // Update parent pointer if not nil
        temp.p = node.p; // Update parent of temp
        if (node.p == nil) root = temp; // If node is root, update root
        else if (node == node.p.left) node.p.left = temp; // Update parent's left child
        else node.p.right = temp; // Update parent's right child
        temp.left = node; // Make node the left child of temp
        node.p = temp; // Update parent pointer of node
    }

    // Method to perform a right rotation on a given node
    private void rotateRight(Node node) {
        Node temp = node.left; // Store the left child
        node.left = temp.right; // Move the right child of left to the left of the node
        if (temp.right != nil) temp.right.p = node; // Update parent pointer if not nil
        temp.p = node.p; // Update parent of temp
        if (node.p == nil) root = temp; // If node is root, update root
        else if (node == node.p.right) node.p.right = temp; // Update parent's right child
        else node.p.left = temp; // Update parent's left child
        temp.right = node; // Make node the right child of temp
        node.p = temp; // Update parent pointer of node
    }

    // Method to print the tree in-order
    public void printInOrder() {
        printTree(root); // Call the printTree method starting from the root
        System.out.println(); // Print a new line after traversal
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Main rbTree = new Main(); // Create an instance of the Red-Black Tree
        int n = scanner.nextInt(); // Read the number of keys to insert
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt(); // Read each key
            rbTree.insert(key); // Insert the key into the tree
        }
        System.out.println("In-order traversal:"); // Print message before traversal
        rbTree.printInOrder(); // Print the tree in-order
        scanner.close(); // Close the scanner
    }
}
