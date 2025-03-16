
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();

        // Initialize an empty BST (Binary Search Tree)
        Node tree = null;

        // Read and process each command from the input
        for (int i = 0; i < m; i++) {
            String command = sc.next(); // Read the command from the input

            // If the command is "insert", insert the given key into the BST
            if (command.equals("insert")) {
                long key = sc.nextLong(); // Read the key to be inserted
                if (tree == null) { // If the BST is empty
                    tree = new Node(); // Create a new node and set it as the root
                    tree.value = key; // Set the value of the root to the key
                } else {
                    tree.insert(key); // Recursively insert the key into the BST
                }
            } else { // If the command is not "insert", print the BST in inorder and preorder traversals
                if (tree != null) {
                    tree.printInOrder(); // Print the BST in inorder traversal
                    System.out.println(); // Print a newline after inorder traversal
                    tree.printPreOrder(); // Print the BST in preorder traversal
                    System.out.println(); // Print a newline after preorder traversal
                }
            }
        }

        // Close the Scanner object to free up system resources
        sc.close();
    }

    static class Node {
        long value; // The value of the node
        Node left; // The left child of the node
        Node right; // The right child of the node

        // Recursively insert a new key into the BST
        void insert(long newValue) {
            if (newValue < this.value) { // If the new value is less than the current node's value
                if (left == null) { // If the left child is empty
                    left = new Node(); // Create a new node and set it as the left child
                    left.value = newValue; // Set the value of the new node to the new value
                } else {
                    left.insert(newValue); // Recursively insert the new value into the left subtree
                }
            } else {
                if (right == null) { // If the right child is empty
                    right = new Node(); // Create a new node and set it as the right child
                    right.value = newValue; // Set the value of the new node to the new value
                } else {
                    right.insert(newValue); // Recursively insert the new value into the right subtree
                }
            }
        }

        // Print the BST in inorder traversal
        void printInOrder() {
            if (left != null) { // If the left subtree is not empty
                left.printInOrder(); // Recursively print the left subtree in inorder traversal
            }
            System.out.print(" " + value); // Print the current node's value
            if (right != null) { // If the right subtree is not empty
                right.printInOrder(); // Recursively print the right subtree in inorder traversal
            }
        }

        // Print the BST in preorder traversal
        void printPreOrder() {
            System.out.print(" " + value); // Print the current node's value
            if (left != null) { // If the left subtree is not empty
                left.printPreOrder(); // Recursively print the left subtree in preorder traversal
            }
            if (right != null) { // If the right subtree is not empty
                right.printPreOrder(); // Recursively print the right subtree in preorder traversal
            }
        }
    }
}