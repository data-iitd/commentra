
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a static inner class Node for Binary Search Tree
    static class Node<T extends Comparable<T>> {
        T data;
        Node<T> left, right;

        // Constructor for Node
        Node(T data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Define a static inner class BST for Binary Search Tree
    static class BST<T extends Comparable<T>> {
        Node<T> root;

        // Method to add an element to the BST
        void add(T data) {
            root = addRecursive(root, data);
        }

        // Recursive method to add an element to the BST
        private Node<T> addRecursive(Node<T> node, T data) {
            if (node == null) {
                return new Node<>(data);
            }

            // If the data to be added is smaller than the current node,
            // then it should be added to the left subtree
            if (data.compareTo(node.data) < 0) {
                node.left = addRecursive(node.left, data);
            } else {
                // Otherwise, it should be added to the right subtree
                node.right = addRecursive(node.right, data);
            }
            return node;
        }

        // Method to perform in-order traversal of the BST and return a List
        List<T> inOrderTraversal() {
            List<T> result = new ArrayList<>();
            inOrderTraversal(root, result);
            return result;
        }

        // Recursive method to perform in-order traversal of the BST
        private void inOrderTraversal(Node<T> node, List<T> result) {
            if (node != null) {
                // Perform in-order traversal of the left subtree
                inOrderTraversal(node.left, result);

                // Add the current node's data to the result List
                result.add(node.data);

                // Perform in-order traversal of the right subtree
                inOrderTraversal(node.right, result);
            }
        }
    }

    // Method to sort an Integer array using the BST
    @SuppressWarnings("unchecked")
    <T extends Comparable<T>> T[] sort(T[] unsortedArray) {
        BST<T> tree = new BST<>();

        // Add all elements of the array to the BST
        for (T element : unsortedArray) {
            tree.add(element);
        }

        // Perform in-order traversal of the BST to get the sorted elements
        List<T> sortedList = tree.inOrderTraversal();

        // Return the sorted array
        return sortedList.toArray((T[]) new Comparable[unsortedArray.length]);
    }

    // Method to sort a List using the BST
    @SuppressWarnings("unchecked")
    <T extends Comparable<T>> List<T> sort(List<T> unsortedList) {
        BST<T> tree = new BST<>();

        // Add all elements of the List to the BST
        for (T element : unsortedList) {
            tree.add(element);
        }

        // Perform in-order traversal of the BST to get the sorted elements
        return tree.inOrderTraversal();
    }

    // Main method to read user input and call the sorting methods
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main treeSort = new Main();

        // Read the type of input (Array or List)
        int type = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Read the size of the input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Based on the type of input, create an appropriate data structure
        if (type == 1) {
            Integer[] array = new Integer[n];

            // Read the elements of the array and store them in the Main class's array
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
            }

            // Call the sorting method for the array
            array = treeSort.sort(array);

            // Print the sorted array
            System.out.println("Sorted Array:");
            for (Integer num : array) {
                System.out.print(num + " ");
            }
        } else if (type == 2) {
            String[] array = new String[n];

            // Read the elements of the array and store them in the Main class's array
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextLine();
            }

            // Call the sorting method for the array
            array = treeSort.sort(array);

            // Print the sorted array
            System.out.println("Sorted Array:");
            for (String str : array) {
                System.out.print(str + " ");
            }
        } else {
            // If an invalid type is entered, print an error message
            System.out.println("Invalid type entered.");
        }

        // Close the Scanner
        scanner.close();
    }
}