import java.util.Scanner;

public class Main {
    // Node class representing each node in the binary search tree (BST)
    static class Node {
        int data; // Value of the node
        Node left; // Left child of the node
        Node right; // Right child of the node

        // Constructor to initialize a new node with given data
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private Node root; // Root node of the BST

    // Constructor to initialize the BST
    public Main() {
        root = null; // Initially, the tree is empty
    }

    // Getter method to retrieve the root of the BST
    public Node getRoot() {
        return root;
    }

    // Recursive method to insert a new value into the BST
    private Node insert(Node node, int data) {
        // If the current node is null, create a new node
        if (node == null) {
            node = new Node(data);
        } 
        // If the data is less than the current node's data, insert in the left subtree
        else if (data < node.data) {
            node.left = insert(node.left, data);
        } 
        // If the data is greater than the current node's data, insert in the right subtree
        else if (data > node.data) {
            node.right = insert(node.right, data);
        }
        return node; // Return the (potentially new) node
    }

    // Public method to add a new value to the BST
    public void add(int data) {
        root = insert(root, data); // Start the insertion from the root
    }

    // Recursive method to delete a value from the BST
    private Node delete(Node node, int data) {
        // If the node is null, the data is not found
        if (node == null) {
            System.out.println("No such data present in BST.");
            return null;
        }
        // If the data is less than the current node's data, search in the left subtree
        if (data < node.data) {
            node.left = delete(node.left, data);
        } 
        // If the data is greater than the current node's data, search in the right subtree
        else if (data > node.data) {
            node.right = delete(node.right, data);
        } 
        // Node with the data found
        else {
            // Case 1: Node has no children
            if (node.left == null && node.right == null) { 
                return null; // Remove the node
            } 
            // Case 2: Node has only right child
            else if (node.left == null) { 
                return node.right; // Bypass the node
            } 
            // Case 3: Node has only left child
            else if (node.right == null) { 
                return node.left; // Bypass the node
            } 
            // Case 4: Node has two children
            else { 
                // Find the minimum value in the right subtree
                Node temp = findMin(node.right);
                node.data = temp.data; // Replace with the minimum value
                node.right = delete(node.right, temp.data); // Delete the minimum node
            }
        }
        return node; // Return the (potentially modified) node
    }

    // Public method to remove a value from the BST
    public void remove(int data) {
        root = delete(root, data); // Start the deletion from the root
    }

    // Helper method to find the minimum value node in a subtree
    private Node findMin(Node node) {
        // Traverse to the leftmost node
        while (node.left != null) {
            node = node.left;
        }
        return node; // Return the minimum node
    }

    // Recursive method to search for a value in the BST
    private boolean search(Node node, int data) {
        // If the node is null, the value is not found
        if (node == null) {
            return false;
        }
        // If the data is less than the current node's data, search in the left subtree
        if (data < node.data) {
            return search(node.left, data);
        } 
        // If the data is greater than the current node's data, search in the right subtree
        else if (data > node.data) {
            return search(node.right, data);
        } 
        // Value found
        else {
            return true;
        }
    }

    // Public method to find a value in the BST and print the result
    public boolean find(int data) {
        boolean result = search(root, data); // Search for the value
        // Print whether the value is found or not
        if (result) {
            System.out.println(data + " is present in the BST.");
        } else {
            System.out.println(data + " is not found.");
        }
        return result; // Return the result of the search
    }

    // Method to perform in-order traversal of the BST
    public void inOrderTraversal(Node node) {
        // If the node is not null, traverse the left subtree, print the node, and traverse the right subtree
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.data + " "); // Print the current node's data
            inOrderTraversal(node.right);
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main bst = new Main(); // Create a new instance of the BST
        int n = scanner.nextInt(); // Read the number of operations to perform

        // Loop to perform operations based on user input
        for (int i = 0; i < n; i++) {
            int choice = scanner.nextInt(); // Read the user's choice of operation
            switch (choice) {
                case 1: // Insert operation
                    int insertValue = scanner.nextInt(); // Read the value to insert
                    bst.add(insertValue); // Add the value to the BST
                    break;
                case 2: // Delete operation
                    int deleteValue = scanner.nextInt(); // Read the value to delete
                    bst.remove(deleteValue); // Remove the value from the BST
                    break;
                case 3: // Search operation
                    int searchValue = scanner.nextInt(); // Read the value to search for
                    bst.find(searchValue); // Find the value in the BST
                    break;
                case 4: // In-order traversal operation
                    bst.inOrderTraversal(bst.getRoot()); // Print the values in in-order
                    System.out.println(); // Print a new line after traversal
                    break;
                default: // Invalid choice
                    System.out.println("Invalid choice. Try again."); // Prompt for a valid choice
            }
        }
        scanner.close(); // Close the scanner
    }
}
