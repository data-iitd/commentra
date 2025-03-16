
import java.util.Scanner;

public class s701716787{
    public static void main(String[] args) {
        Node root = null; // Root of the binary search tree
        Scanner scanner = new Scanner(System.in);

        // Read the number of commands from user input
        int numCommands = scanner.nextInt();

        // Execute commands based on user input
        for (int i = 0; i < numCommands; i++) {
            // Read the command (insert or print)
            String command = scanner.next();

            // Execute the command based on its type
            if (command.equals("insert")) {
                // If the command is "insert", read the key value to insert
                int insertKey = scanner.nextInt();
                insert(root, insertKey); // Insert the key into the tree
            } else if (command.equals("print")) {
                print(root); // Print the current state of the tree
            }
        }
    }

    // Function to insert a key into the binary search tree
    public static void insert(Node root, int key) {
        Node parent = null; // Pointer to track the parent node
        Node index = root; // Pointer for traversal
        Node insertNode = new Node(key); // New node to be inserted

        // Traverse the tree to find the correct insertion point
        while (index!= null) {
            parent = index; // Update parent node
            if (insertNode.key < index.key) {
                index = index.left; // Go left
            } else {
                index = index.right; // Go right
            }
        }
        insertNode.parent = parent; // Set parent for the new node

        // Insert the new node in the tree
        if (parent == null) {
            root = insertNode; // Tree was empty, new node becomes root
        } else if (insertNode.key < parent.key) {
            parent.left = insertNode; // Insert as left child
        } else {
            parent.right = insertNode; // Insert as right child
        }
    }

    // Function to print the binary search tree
    public static void print(Node root) {
        printInOrder(root); // Print in-order
        System.out.println();
        printPreOrder(root); // Print pre-order
        System.out.println();
    }

    // Function to print the tree in pre-order
    public static void printPreOrder(Node node) {
        if (node == null) {
            return; // Base case: if the node is null, return
        }

        System.out.print(" " + node.key); // Print the key of the current node
        printPreOrder(node.left); // Recursively print left subtree
        printPreOrder(node.right); // Recursively print right subtree
    }

    // Function to print the tree in in-order
    public static void printInOrder(Node node) {
        if (node == null) {
            return; // Base case: if the node is null, return
        }

        printInOrder(node.left); // Recursively print left subtree
        System.out.print(" " + node.key); // Print the key of the current node
        printInOrder(node.right); // Recursively print right subtree
    }

    // Node class to represent a node in the binary search tree
    static class Node {
        Node parent; // Pointer to the parent node
        Node left; // Pointer to the left child node
        Node right; // Pointer to the right child node
        int key; // Key value of the node

        public Node(int key) {
            this.key = key;
        }
    }
}

