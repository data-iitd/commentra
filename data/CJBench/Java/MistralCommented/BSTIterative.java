
import java.util.Scanner;

// Initialize an empty BST
public class Main {
    private Node root;

    static class Node {
        int data;
        Node left, right;

        // Initialize a new node with given data
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Initialize an empty BST
    public Main() {
        root = null;
    }

    // Add a new node with given data to the BST
    public void add(int data) {
        Node parent = null; // Keep track of the parent node
        Node temp = this.root; // Initialize a temporary node to traverse the tree

        int direction = -1; // Direction to move: 0 for left, 1 for right

        // Traverse the tree to find the location to insert the new node
        while (temp != null) {
            if (data < temp.data) {
                parent = temp; // Move left
                temp = temp.left;
                direction = 0;
            } else if (data > temp.data) {
                parent = temp; // Move right
                temp = temp.right;
                direction = 1;
            } else { // Data already exists in the tree
                System.out.println(data + " is already present in BST.");
                return;
            }
        }

        // Create a new node with the given data
        Node newNode = new Node(data);

        // Insert the new node at the appropriate location in the tree
        if (parent == null) {
            this.root = newNode; // If the tree is empty, the new node is the root
        } else if (direction == 0) {
            parent.left = newNode; // If the new node is to be inserted as a left child
        } else {
            parent.right = newNode; // If the new node is to be inserted as a right child
        }
    }

    // Remove a node with given data from the BST
    public void remove(int data) {
        Node parent = null; // Keep track of the parent node
        Node temp = this.root; // Initialize a temporary node to traverse the tree

        int direction = -1; // Direction to move: 0 for left, 1 for right

        // Traverse the tree to find the node to be removed
        while (temp != null) {
            if (temp.data == data) {
                break; // Node found
            } else if (data < temp.data) {
                parent = temp; // Move left
                temp = temp.left;
                direction = 0;
            } else {
                parent = temp; // Move right
                temp = temp.right;
                direction = 1;
            }
        }

        // Check if the node was found
        if (temp == null) {
            System.out.println(data + " not found.");
            return;
        }

        // Determine the replacement node
        Node replacement = null;
        if (temp.left == null && temp.right == null) {
            replacement = null; // Leaf node: no replacement needed
        } else if (temp.left == null) {
            replacement = temp.right; // Replace with the right child
        } else if (temp.right == null) {
            replacement = temp.left; // Replace with the left child
        } else {
            Node successorParent = temp; // Traverse to find the successor node
            Node successor = temp.right;

            while (successor.left != null) {
                successorParent = successor;
                successor = successor.left;
            }

            temp.data = successor.data; // Replace the data of the node to be removed with the data of the successor node

            if (successorParent != temp) { // If the successor node is not the right child of the node to be removed
                successorParent.left = successor.right; // Update the left child of the successor's parent
            } else {
                successorParent.right = successor.right; // Update the right child of the node to be removed
            }
        }

        // Update the tree based on the replacement node
        if (parent == null) {
            this.root = replacement; // If the node to be removed was the root
        } else if (direction == 0) {
            parent.left = replacement; // If the node to be removed was a left child
        } else {
            parent.right = replacement; // If the node to be removed was a right child
        }
    }

    // Search for a node with given data in the BST
    public boolean find(int data) {
        Node temp = this.root; // Initialize a temporary node to traverse the tree

        // Traverse the tree to find the node with the given data
        while (temp != null) {
            if (data == temp.data) {
                System.out.println(data + " is present in the BST.");
                return true;
            } else if (data < temp.data) {
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }

        // If the node was not found
        System.out.println(data + " not found.");
        return false;
    }

    // Display the contents of the BST in-order
    public void display() {
        displayHelper(this.root); // Recursively traverse the tree and print the nodes in-order
    }

    // Helper function to display the contents of the BST in-order
    private void displayHelper(Node node) {
        if (node != null) {
            displayHelper(node.left); // Display the left subtree
            System.out.print(node.data + " "); // Display the current node
            displayHelper(node.right); // Display the right subtree
        }
    }

    // Main method to read user input and perform operations on the BST
    public static void main(String[] args) {
        Main bst = new Main(); // Initialize an empty BST

        Scanner scanner = new Scanner(System.in); // Initialize a Scanner to read user input

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read a user command

            if (command.equalsIgnoreCase("exit")) { // Exit the program if the command is "exit"
                break;
            }

            String[] parts = command.split(" "); // Split the command into parts based on whitespace

            try {
                switch (parts[0]) { // Perform the specified operation based on the command
                    case "add":
                        bst.add(Integer.parseInt(parts[1])); // Add a new node with the given data
                        System.out.println("Added: " + parts[1]);
                        break;
                    case "remove":
                        bst.remove(Integer.parseInt(parts[1])); // Remove a node with the given data
                        System.out.println("Removed: " + parts[1]);
                        break;
                    case "find":
                        bst.find(Integer.parseInt(parts[1])); // Search for a node with the given data
                        break;
                    case "display":
                        bst.display(); // Display the contents of the BST
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Print an error message for an unknown command
                        break;
                }
            } catch (Exception e) { // Handle any exceptions that might occur during command execution
                System.out.println("Error: Invalid command or input.");
            }
        }

        scanner.close(); // Close the Scanner when finished
    }
}