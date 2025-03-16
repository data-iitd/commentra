import java.util.Scanner;
public class Main {
    private Node root; // Root of the Binary Search Tree
    static class Node { // Inner class representing a node in the BST
        int data; // Data stored in the node
        Node left, right; // Pointers to the left and right children
        Node(int data) { // Constructor to initialize the node
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    public Main() { // Constructor to initialize the BST
        root = null; // Sets the root to null
    }
    public void add(int data) { // Method to add a new node with the given data to the BST
        Node parent = null; // Parent node to keep track of the current node's parent
        Node temp = this.root; // Temporary node to traverse the tree
        int direction = -1; // Direction indicator (0 for left, 1 for right)
        while (temp != null) { // Traverse the tree to find the correct position
            if (data < temp.data) {
                parent = temp;
                temp = temp.left;
                direction = 0;
            } else if (data > temp.data) {
                parent = temp;
                temp = temp.right;
                direction = 1;
            } else {
                System.out.println(data + " is already present in BST."); // Data already exists
                return;
            }
        }
        Node newNode = new Node(data); // Create a new node with the given data
        if (parent == null) {
            this.root = newNode; // If the tree is empty, set the root to the new node
        } else if (direction == 0) {
            parent.left = newNode; // Set the left child of the parent to the new node
        } else {
            parent.right = newNode; // Set the right child of the parent to the new node
        }
    }
    public void remove(int data) { // Method to remove a node with the given data from the BST
        Node parent = null; // Parent node to keep track of the current node's parent
        Node temp = this.root; // Temporary node to traverse the tree
        int direction = -1; // Direction indicator (0 for left, 1 for right)
        while (temp != null) { // Traverse the tree to find the node to remove
            if (temp.data == data) {
                break;
            } else if (data < temp.data) {
                parent = temp;
                temp = temp.left;
                direction = 0;
            } else {
                parent = temp;
                temp = temp.right;
                direction = 1;
            }
        }
        if (temp != null) { // If the node is found
            Node replacement = null; // Node to replace the removed node
            if (temp.left == null && temp.right == null) {
                replacement = null; // No children, set replacement to null
            } else if (temp.left == null) {
                replacement = temp.right; // Only right child, set replacement to right child
            } else if (temp.right == null) {
                replacement = temp.left; // Only left child, set replacement to left child
            } else {
                Node successorParent = temp; // Find the in-order successor
                Node successor = temp.right;
                while (successor.left != null) {
                    successorParent = successor;
                    successor = successor.left;
                }
                temp.data = successor.data; // Replace the data with the successor's data
                if (successorParent != temp) {
                    successorParent.left = successor.right; // Set the left child of successor's parent to successor's right child
                } else {
                    successorParent.right = successor.right; // Set the right child of successor's parent to successor's right child
                }
                return;
            }
            if (parent == null) {
                this.root = replacement; // If the node to remove is the root, set the root to the replacement
            } else if (direction == 0) {
                parent.left = replacement; // Set the left child of the parent to the replacement
            } else {
                parent.right = replacement; // Set the right child of the parent to the replacement
            }
        }
    }
    public boolean find(int data) { // Method to check if a node with the given data is present in the BST
        Node temp = this.root; // Temporary node to traverse the tree
        while (temp != null) { // Traverse the tree to find the node
            if (data == temp.data) {
                System.out.println(data + " is present in the BST."); // Data found
                return true;
            } else if (data < temp.data) {
                temp = temp.left; // Move to the left child
            } else {
                temp = temp.right; // Move to the right child
            }
        }
        System.out.println(data + " not found."); // Data not found
        return false;
    }
    public void display() { // Method to display the elements of the BST in an in-order traversal
        displayHelper(this.root); // Call the helper method with the root node
        System.out.println();
    }
    private void displayHelper(Node node) { // Helper method for the display method
        if (node != null) { // Recursively traverse the tree in-order
            displayHelper(node.left);
            System.out.print(node.data + " ");
            displayHelper(node.right);
        }
    }
    public static void main(String[] args) { // Main method to provide a command-line interface for the BST
        Main bst = new Main(); // Create a new instance of the BST
        Scanner scanner = new Scanner(System.in); // Create a scanner to read user input
        while (scanner.hasNextLine()) { // Continuously read commands from the user
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            String[] parts = command.split(" "); // Split the command into parts
            try {
                switch (parts[0]) { // Perform the appropriate operation based on the command
                    case "add":
                        bst.add(Integer.parseInt(parts[1])); // Add the given data to the BST
                        System.out.println("Added: " + parts[1]);
                        break;
                    case "remove":
                        bst.remove(Integer.parseInt(parts[1])); // Remove the given data from the BST
                        System.out.println("Removed: " + parts[1]);
                        break;
                    case "find":
                        bst.find(Integer.parseInt(parts[1])); // Find the given data in the BST
                        break;
                    case "display":
                        bst.display(); // Display the elements of the BST
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Unknown command
                        break;
                }
            } catch (Exception e) {
                System.out.println("Error: Invalid command or input."); // Invalid command or input
            }
        }
        scanner.close(); // Close the scanner
    }
}
