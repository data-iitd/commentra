import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    private static final int RED = 0; // Constant for red color
    private static final int BLACK = 1; // Constant for black color

    // Inner class Node representing a node in the Red-Black Tree
    private class Node {
        int key; // The key value of the node
        int color = BLACK; // Color of the node, default is black
        Node left = nil, right = nil, p = nil; // Pointers to left, right children and parent

        // Constructor for Node class
        Node(int key) {
            this.key = key;
        }
    }

    // Sentinel node to represent null in the tree
    private final Node nil = new Node(-1);
    private Node root = nil; // Root of the Red-Black Tree

    // Method to print the tree in an in-order traversal manner
    public void printTree(Node node) {
        if (node == nil) return; // Base case for recursion
        printTree(node.left); // Recursively print left subtree
        System.out.print(((node.color == RED) ? "R " : "B ") + node.key + " "); // Print current node color and key
        printTree(node.right); // Recursively print right subtree
    }

    // Method to insert a new node into the Red-Black Tree
    public void insert(int key) {
        Node node = new Node(key); // Create a new node with the given key
        Node temp = root; // Temporary node to traverse the tree
        if (root == nil) {
            root = node; // If tree is empty, new node becomes the root
            node.color = BLACK; // Root is always black
        } else {
            node.color = RED; // New node is red
            while (true) {
                if (key < temp.key) { // Traverse left subtree if key is less than current node's key
                    if (temp.left == nil) { // If left child is nil, insert here
                        temp.left = node;
                        node.p = temp; // Set parent of the new node
                        break;
                    }
                    temp = temp.left; // Move to the left child
                } else { // Traverse right subtree if key is greater than or equal to current node's key
                    if (temp.right == nil) { // If right child is nil, insert here
                        temp.right = node;
                        node.p = temp; // Set parent of the new node
                        break;
                    }
                    temp = temp.right; // Move to the right child
                }
            }
            fixTree(node); // Call fixTree to maintain Red-Black properties
        }
    }

    // Method to fix the tree after insertion to maintain Red-Black properties
    private void fixTree(Node node) {
        while (node.p.color == RED) { // Continue until parent is red
            if (node.p == node.p.p.left) { // If parent is left child of grandparent
                Node y = node.p.p.right; // Uncle node
                if (y.color == RED) { // Case 1: Uncle is red
                    node.p.color = BLACK; // Change parent and uncle to black
                    y.color = BLACK;
                    node.p.p.color = RED; // Change grandparent to red
                    node = node.p.p; // Move node up to grandparent
                } else {
                    if (node == node.p.right) { // Case 2: Node is right child, left rotate on parent
                        node = node.p;
                        rotateLeft(node);
                    }
                    node.p.color = BLACK; // Case 3: Node is left child, right rotate on grandparent
                    node.p.p.color = RED;
                    rotateRight(node.p.p);
                }
            } else { // Symmetric cases for when parent is right child of grandparent
                Node y = node.p.p.left;
                if (y.color == RED) {
                    node.p.color = BLACK;
                    y.color = BLACK;
                    node.p.p.color = RED;
                    node = node.p.p;
                } else {
                    if (node == node.p.left) {
                        node = node.p;
                        rotateRight(node);
                    }
                    node.p.color = BLACK;
                    node.p.p.color = RED;
                    rotateLeft(node.p.p);
                }
            }
        }
        root.color = BLACK; // Ensure root is black
    }

    // Method to perform left rotation on a given node
    private void rotateLeft(Node node) {
        Node temp = node.right; // Assign right child of node to temp
        node.right = temp.left; // Assign left child of temp to right child of node
        if (temp.left != nil) temp.left.p = node; // Update parent of temp's left child
        temp.p = node.p; // Update parent of temp
        if (node.p == nil) root = temp; // If node was root, update root
        else if (node == node.p.left) node.p.left = temp; // Update parent's child pointer
        else node.p.right = temp;
        temp.left = node; // Assign node as left child of temp
        node.p = temp; // Update parent of node
    }

    // Method to perform right rotation on a given node
    private void rotateRight(Node node) {
        Node temp = node.left; // Assign left child of node to temp
        node.left = temp.right; // Assign right child of temp to left child of node
        if (temp.right != nil) temp.right.p = node; // Update parent of temp's right child
        temp.p = node.p; // Update parent of temp
        if (node.p == nil) root = temp; // If node was root, update root
        else if (node == node.p.right) node.p.right = temp; // Update parent's child pointer
        else node.p.left = temp;
        temp.right = node; // Assign node as right child of temp
        node.p = temp; // Update parent of node
    }

    // Method to print the tree in an in-order traversal manner
    public void printInOrder() {
        printTree(root); // Call printTree starting from root
        System.out.println(); // Print newline for better readability
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        Main rbTree = new Main(); // Create an instance of Main class
        int n = scanner.nextInt(); // Read the number of nodes to be inserted
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt(); // Read each key
            rbTree.insert(key); // Insert the key into the Red-Black Tree
        }
        System.out.println("In-order traversal:");
        rbTree.printInOrder(); // Print the tree in an in-order traversal
        scanner.close(); // Close the scanner
    }
}
