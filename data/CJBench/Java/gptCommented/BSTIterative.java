import java.util.Scanner;

public class Main {
    // Root node of the binary search tree
    private Node root;

    // Node class representing each node in the BST
    static class Node {
        int data; // Value of the node
        Node left, right; // Pointers to left and right children

        // Constructor to initialize a new node
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Constructor for the Main class, initializes the root to null
    public Main() {
        root = null;
    }

    // Method to add a new value to the BST
    public void add(int data) {
        Node parent = null; // Parent node of the current node
        Node temp = this.root; // Temporary node for traversal
        int direction = -1; // Direction to indicate where to add the new node

        // Traverse the tree to find the correct position for the new node
        while (temp != null) {
            if (data < temp.data) {
                parent = temp; // Update parent to current node
                temp = temp.left; // Move to the left child
                direction = 0; // Set direction to left
            } else if (data > temp.data) {
                parent = temp; // Update parent to current node
                temp = temp.right; // Move to the right child
                direction = 1; // Set direction to right
            } else {
                // If the data is already present, print a message and return
                System.out.println(data + " is already present in BST.");
                return;
            }
        }

        // Create a new node for the data
        Node newNode = new Node(data);
        // If the tree was empty, set the new node as the root
        if (parent == null) {
            this.root = newNode; 
        } else if (direction == 0) {
            // If the new node is to be added to the left of the parent
            parent.left = newNode; 
        } else {
            // If the new node is to be added to the right of the parent
            parent.right = newNode; 
        }
    }

    // Method to remove a value from the BST
    public void remove(int data) {
        Node parent = null; // Parent node of the current node
        Node temp = this.root; // Temporary node for traversal
        int direction = -1; // Direction to indicate where the node is located

        // Traverse the tree to find the node to be removed
        while (temp != null) {
            if (temp.data == data) {
                break; // Node found
            } else if (data < temp.data) {
                parent = temp; // Update parent to current node
                temp = temp.left; // Move to the left child
                direction = 0; // Set direction to left
            } else {
                parent = temp; // Update parent to current node
                temp = temp.right; // Move to the right child
                direction = 1; // Set direction to right
            }
        }

        // If the node to be removed is found
        if (temp != null) {
            Node replacement = null; // Node to replace the removed node

            // Case 1: Node has no children
            if (temp.left == null && temp.right == null) {
                replacement = null; 
            }
            // Case 2: Node has only right child
            else if (temp.left == null) {
                replacement = temp.right; 
            }
            // Case 3: Node has only left child
            else if (temp.right == null) {
                replacement = temp.left; 
            }
            // Case 4: Node has two children
            else {
                Node successorParent = temp; // Parent of the successor node
                Node successor = temp.right; // Start with the right child

                // Find the leftmost child of the right subtree (successor)
                while (successor.left != null) {
                    successorParent = successor;
                    successor = successor.left;
                }

                // Replace the data of the node to be removed with the successor's data
                temp.data = successor.data; 
                // Adjust the successor's parent's child pointer
                if (successorParent != temp) {
                    successorParent.left = successor.right;
                } else {
                    successorParent.right = successor.right;
                }
                return;
            }

            // Adjust the parent's child pointer to bypass the removed node
            if (parent == null) {
                this.root = replacement; // If the node to remove is root
            } else if (direction == 0) {
                parent.left = replacement; // If the node is a left child
            } else {
                parent.right = replacement; // If the node is a right child
            }
        }
    }

    // Method to find a value in the BST
    public boolean find(int data) {
        Node temp = this.root; // Temporary node for traversal

        // Traverse the tree to find the value
        while (temp != null) {
            if (data == temp.data) {
                System.out.println(data + " is present in the BST.");
                return true; // Value found
            } else if (data < temp.data) {
                temp = temp.left; // Move to the left child
            } else {
                temp = temp.right; // Move to the right child
            }
        }

        // If the value is not found, print a message
        System.out.println(data + " not found.");
        return false; // Value not found
    }

    // Method to display the values in the BST in sorted order
    public void display() {
        displayHelper(this.root); // Call helper method to display values
        System.out.println(); // Print a new line after displaying
    }

    // Helper method to perform in-order traversal of the BST
    private void displayHelper(Node node) {
        if (node != null) {
            displayHelper(node.left); // Traverse left subtree
            System.out.print(node.data + " "); // Print current node's data
            displayHelper(node.right); // Traverse right subtree
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Main bst = new Main(); // Create a new instance of the BST
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input

        // Loop to accept commands from the user
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read user input
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }

            String[] parts = command.split(" "); // Split the command into parts
            try {
                // Process the command based on the first part
                switch (parts[0]) {
                    case "add":
                        bst.add(Integer.parseInt(parts[1])); // Add a new value
                        System.out.println("Added: " + parts[1]);
                        break;
                    case "remove":
                        bst.remove(Integer.parseInt(parts[1])); // Remove a value
                        System.out.println("Removed: " + parts[1]);
                        break;
                    case "find":
                        bst.find(Integer.parseInt(parts[1])); // Find a value
                        break;
                    case "display":
                        bst.display(); // Display the BST
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Handle unknown commands
                        break;
                }
            } catch (Exception e) {
                System.out.println("Error: Invalid command or input."); // Handle invalid input
            }
        }
        scanner.close(); // Close the scanner
    }
}
