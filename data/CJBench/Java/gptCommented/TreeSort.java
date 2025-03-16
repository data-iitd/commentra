import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Node class representing each node in the Binary Search Tree (BST)
    static class Node<T extends Comparable<T>> {
        T data; // Data stored in the node
        Node<T> left, right; // References to left and right child nodes

        // Constructor to create a new node with given data
        Node(T data) {
            this.data = data;
        }
    }

    // Binary Search Tree class
    static class BST<T extends Comparable<T>> {
        Node<T> root; // Root node of the BST

        // Public method to add data to the BST
        void add(T data) {
            root = addRecursive(root, data); // Start the recursive addition
        }

        // Private recursive method to add data to the BST
        private Node<T> addRecursive(Node<T> node, T data) {
            // If the current node is null, create a new node
            if (node == null) {
                return new Node<>(data);
            }
            // Compare data and decide to go left or right
            if (data.compareTo(node.data) < 0) {
                node.left = addRecursive(node.left, data); // Add to left subtree
            } else {
                node.right = addRecursive(node.right, data); // Add to right subtree
            }
            return node; // Return the unchanged node pointer
        }

        // Method to perform in-order traversal of the BST
        List<T> inOrderTraversal() {
            List<T> result = new ArrayList<>(); // List to hold the traversal result
            inOrderTraversal(root, result); // Start the traversal from the root
            return result; // Return the collected result
        }

        // Private recursive method for in-order traversal
        private void inOrderTraversal(Node<T> node, List<T> result) {
            if (node != null) {
                inOrderTraversal(node.left, result); // Traverse left subtree
                result.add(node.data); // Visit the node
                inOrderTraversal(node.right, result); // Traverse right subtree
            }
        }
    }

    // Method to sort an array using BST
    public <T extends Comparable<T>> T[] sort(T[] unsortedArray) {
        BST<T> tree = new BST<>(); // Create a new BST instance
        for (T element : unsortedArray) {
            tree.add(element); // Add each element to the BST
        }
        List<T> sortedList = tree.inOrderTraversal(); // Get sorted elements
        return sortedList.toArray(unsortedArray); // Convert list back to array
    }

    // Method to sort a list using BST
    public <T extends Comparable<T>> List<T> sort(List<T> unsortedList) {
        BST<T> tree = new BST<>(); // Create a new BST instance
        for (T element : unsortedList) {
            tree.add(element); // Add each element to the BST
        }
        return tree.inOrderTraversal(); // Return the sorted elements as a list
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Main treeSort = new Main(); // Create an instance of Main
        int type = scanner.nextInt(); // Read the type of input (1 for array, 2 for list)
        scanner.nextLine(); // Consume the newline character
        int n = scanner.nextInt(); // Read the number of elements
        scanner.nextLine(); // Consume the newline character

        // Check if the input type is for an Integer array
        if (type == 1) {
            Integer[] array = new Integer[n]; // Create an array to hold integers
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt(); // Read integers from input
            }
            array = treeSort.sort(array); // Sort the array using BST
            System.out.println("Sorted Array:"); // Print sorted array
            for (Integer num : array) {
                System.out.print(num + " "); // Print each sorted integer
            }
        } 
        // Check if the input type is for a String array
        else if (type == 2) {
            String[] array = new String[n]; // Create an array to hold strings
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextLine(); // Read strings from input
            }
            array = treeSort.sort(array); // Sort the array using BST
            System.out.println("Sorted Array:"); // Print sorted array
            for (String str : array) {
                System.out.print(str + " "); // Print each sorted string
            }
        } 
        // Handle invalid input type
        else {
            System.out.println("Invalid type entered."); // Print error message
        }
        scanner.close(); // Close the scanner
    }
}
