import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt(); // Read the number of commands

        Node tree = null; // Initialize the root of the binary search tree

        // Process each command
        for (int i = 0; i < m; i++) {
            String command = sc.next(); // Read the command

            if (command.equals("insert")) {
                long key = sc.nextLong(); // Read the key to be inserted
                if (tree == null) {
                    tree = new Node(); // Create a new root node if tree is null
                    tree.value = key;
                } else {
                    tree.insert(key); // Insert the key into the tree
                }
            } else {
                if (tree != null) {
                    tree.printInOrder(); // Print the tree in in-order traversal
                    System.out.println(); // Print a newline
                    tree.printPreOrder(); // Print the tree in pre-order traversal
                    System.out.println(); // Print a newline
                }
            }
        }
    }

    static class Node {
        long value;
        Node left;
        Node right;

        void insert(long newValue) {
            if (newValue < this.value) {
                if (left == null) {
                    left = new Node(); // Create a new left child if it doesn't exist
                    left.value = newValue;
                } else {
                    left.insert(newValue); // Recursively insert into the left subtree
                }
            } else {
                if (right == null) {
                    right = new Node(); // Create a new right child if it doesn't exist
                    right.value = newValue;
                } else {
                    right.insert(newValue); // Recursively insert into the right subtree
                }
            }
        }

        void printInOrder() {
            if (left != null) {
                left.printInOrder(); // Recursively print the left subtree
            }
            System.out.print(" " + value); // Print the current node's value
            if (right != null) {
                right.printInOrder(); // Recursively print the right subtree
            }
        }

        void printPreOrder() {
            System.out.print(" " + value); // Print the current node's value
            if (left != null) {
                left.printPreOrder(); // Recursively print the left subtree
            }
            if (right != null) {
                right.printPreOrder(); // Recursively print the right subtree
            }
        }
    }
}
