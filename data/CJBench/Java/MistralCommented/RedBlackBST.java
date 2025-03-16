
import java.util.Scanner;

public class Main {
    // Constants for colors of nodes in the tree
    private static final int RED = 0;
    private static final int BLACK = 1;

    // Inner class Node to represent each node in the tree
    private class Node {
        // Key of the node
        int key;
        // Color of the node (RED or BLACK)
        int color = BLACK;
        // Left and right children of the node
        Node left = nil, right = nil;
        // Parent of the node
        Node p = nil;

        // Constructor for a new Node with given key
        Node(int key) {
            this.key = key;
        }
    }

    // Sentinel node representing nil (null)
    private final Node nil = new Node(-1);

    // Root of the tree
    private Node root = nil;

    // Method to print the tree in-order (left, root, right)
    public void printTree(Node node) {
        // Base case: if node is nil, return
        if (node == nil) return;

        // Recursively print left subtree
        printTree(node.left);

        // Print the node's key and color
        System.out.print(((node.color == RED) ? "R " : "B ") + node.key + " ");

        // Recursively print right subtree
        printTree(node.right);
    }

    // Method to insert a new key into the tree
    public void insert(int key) {
        // Create a new Node with the given key
        Node node = new Node(key);

        Node temp = root;

        // Base case: if the tree is empty, make the new node the root
        if (root == nil) {
            root = node;
            node.color = BLACK;
        } else {
            // New node is red, so we'll insert it as a leaf
            node.color = RED;

            // While we haven't reached the correct position to insert the new node
            while (true) {
                // If the key is less than the current node's key, go left
                if (key < temp.key) {
                    if (temp.left == nil) {
                        // Found the correct position, insert the new node here
                        temp.left = node;
                        node.p = temp;
                        break;
                    }
                    temp = temp.left;
                } else {
                    // If the key is greater than the current node's key, go right
                    if (temp.right == nil) {
                        // Found the correct position, insert the new node here
                        temp.right = node;
                        node.p = temp;
                        break;
                    }
                    temp = temp.right;
                }
            }

            // Fix the tree to maintain the red-black tree properties
            fixTree(node);
        }
    }

    // Method to fix the tree after inserting a new node
    private void fixTree(Node node) {
        // Base case: if the node's parent is black, we're done
        while (node.p.color == RED) {
            // Case 1: uncle is red
            Node y = node.p.p;
            if (y.color == RED) {
                // Make both grandparents black, and make the current node's parent black
                node.p.color = BLACK;
                y.color = BLACK;

                // Make the current node's grandparent red
                node.p.p.color = RED;

                // Recursively fix the tree
                node = node.p.p;
            } else {
                // Case 2: uncle is black, so we'll perform a rotation to rebalance the tree
                if (node == node.p.left) {
                    // Perform a left rotation
                    node = node.p;
                    rotateLeft(node);
                }

                // Perform a right rotation on the node's parent
                node.p.color = BLACK;
                node.p.p.color = RED;
                rotateRight(node.p.p);
            }
        }

        // Make the root black
        root.color = BLACK;
    }

    // Method to perform a left rotation on a node
    private void rotateLeft(Node node) {
        // Save the right child
        Node temp = node.right;

        // Set the right child of the node to the left child of the right child
        node.right = temp.left;

        // If the left child of the right child is not nil, set its parent to the node
        if (temp.left != nil) temp.left.p = node;

        // Set the left child of the right child as the new node's left child
        temp.left = node;

        // Set the parent of the right child to the node's parent
        temp.p = node.p;

        // If the node's parent is nil, make the new right child the root
        if (node.p == nil) root = temp;

        // If the node is the left child of its parent, set the parent's left child to the new right child
        else if (node == node.p.left) node.p.left = temp;

        // Otherwise, set the parent's right child to the new right child
        else node.p.right = temp;

        // Set the new right child as the node's left child
        node.left = temp;

        // Set the node as the new right child of the right child
        temp.p = node;
    }

    // Method to perform a right rotation on a node
    private void rotateRight(Node node) {
        // Save the left child
        Node temp = node.left;

        // Set the left child of the node to the right child of the left child
        node.left = temp.right;

        // If the right child of the left child is not nil, set its parent to the node
        if (temp.right != nil) temp.right.p = node;

        // Set the right child of the left child as the new node's right child
        temp.right = node;

        // Set the parent of the left child to the node's parent
        temp.p = node.p;

        // If the node's parent is nil, make the new left child the root
        if (node.p == nil) root = temp;

        // If the node is the right child of its parent, set the parent's right child to the new left child
        else if (node == node.p.right) node.p.right = temp;

        // Otherwise, set the parent's left child to the new left child
        else node.p.left = temp;

        // Set the new left child as the node's right child
        node.right = temp;

        // Set the node as the new left child of the left child
        temp.p = node;
    }

    // Method to print the tree in-order (left, root, right) and separate the output with a space
    public void printInOrder() {
        printTree(root);
        System.out.println();
    }

    // Main method to read keys from the standard input and insert them into the tree
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main rbTree = new Main();
        int n = scanner.nextInt();

        // Insert n keys into the tree
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt();
            rbTree.insert(key);
        }

        // Print the in-order traversal of the tree
        System.out.println("In-order traversal:");
        rbTree.printInOrder();

        scanner.close();
    }
}