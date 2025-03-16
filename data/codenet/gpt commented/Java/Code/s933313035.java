import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the number of commands to process
        int m = sc.nextInt();

        // Initialize the root of the binary search tree
        Node tree = null;

        // Process each command
        for (int i = 0; i < m; i++) {
            // Read the command (either "insert" or "print")
            String command = sc.next();

            // If the command is "insert", read the key and insert it into the tree
            if (command.equals("insert")) {
                long key = sc.nextLong();
                // If the tree is empty, create the root node
                if (tree == null) {
                    tree = new Node();
                    tree.value = key;
                } else {
                    // Insert the new key into the existing tree
                    tree.insert(key);
                }
            } else {
                // If the command is not "insert", print the tree if it exists
                if (tree != null) {
                    // Print the tree in in-order traversal
                    tree.printInOrder();
                    System.out.println();
                    // Print the tree in pre-order traversal
                    tree.printPreOrder();
                    System.out.println();
                }
            }
        }
    }

    // Node class representing each node in the binary search tree
    static class Node {
        long value; // Value of the node
        Node left;  // Left child node
        Node right; // Right child node

        // Method to insert a new value into the tree
        void insert(long newValue) {
            // If the new value is less than the current node's value, go left
            if (newValue < this.value) {
                // If there is no left child, create a new node
                if (left == null) {
                    left = new Node();
                    left.value = newValue;
                } else {
                    // Otherwise, recursively insert into the left subtree
                    left.insert(newValue);
                }
            } else {
                // If the new value is greater than or equal to the current node's value, go right
                if (right == null) {
                    // If there is no right child, create a new node
                    right = new Node();
                    right.value = newValue;
                } else {
                    // Otherwise, recursively insert into the right subtree
                    right.insert(newValue);
                }
            }
        }

        // Method to print the tree in in-order traversal
        void printInOrder() {
            // Recursively print the left subtree
            if (left != null) {
                left.printInOrder();
            }
            // Print the current node's value
            System.out.print(" " + value);
            // Recursively print the right subtree
            if (right != null) {
                right.printInOrder();
            }
        }

        // Method to print the tree in pre-order traversal
        void printPreOrder() {
            // Print the current node's value
            System.out.print(" " + value);
            // Recursively print the left subtree
            if (left != null) {
                left.printPreOrder();
            }
            // Recursively print the right subtree
            if (right != null) {
                right.printPreOrder();
            }
        }
    }
}
