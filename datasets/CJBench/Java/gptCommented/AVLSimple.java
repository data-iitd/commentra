import java.util.Scanner;

public class Main {
    // Node class representing each node in the AVL tree
    private class Node {
        int data; // Value of the node
        int height; // Height of the node for balancing
        Node left; // Left child of the node
        Node right; // Right child of the node

        // Constructor to initialize a new node
        Node(int data) {
            this.data = data;
            this.height = 1; // New node is initially added at height 1
        }
    }

    private Node root; // Root node of the AVL tree

    // Public method to insert a new value into the AVL tree
    public void insert(int data) {
        this.root = insert(this.root, data); // Start the recursive insertion
    }

    // Private method to insert a new value into the tree rooted at 'node'
    private Node insert(Node node, int item) {
        // If the current node is null, create a new node
        if (node == null) {
            return new Node(item);
        }

        // Recursively insert the item in the left or right subtree
        if (node.data > item) {
            node.left = insert(node.left, item);
        } else if (node.data < item) {
            node.right = insert(node.right, item);
        }

        // Update the height of the current node
        node.height = Math.max(height(node.left), height(node.right)) + 1;

        // Get the balance factor of the current node
        int bf = bf(node);

        // Perform rotations to maintain AVL tree balance
        if (bf > 1 && item < node.left.data) {
            return rightRotate(node); // Left Left Case
        }
        if (bf < -1 && item > node.right.data) {
            return leftRotate(node); // Right Right Case
        }
        if (bf < -1 && item < node.right.data) {
            node.right = rightRotate(node.right); // Right Left Case
            return leftRotate(node);
        }
        if (bf > 1 && item > node.left.data) {
            node.left = leftRotate(node.left); // Left Right Case
            return rightRotate(node);
        }

        return node; // Return the (potentially) new root of the subtree
    }

    // Public method to display the AVL tree
    public void display() {
        this.display(this.root); // Start displaying from the root
        System.out.println("Tree Height: " + this.root.height); // Print the height of the tree
    }

    // Private method to display the tree in a structured format
    private void display(Node node) {
        if (node == null) return; // Base case: if the node is null, return

        String str = "";
        // Prepare the string representation of the current node
        if (node.left != null) {
            str += node.left.data + " => ";
        } else {
            str += "END => ";
        }
        str += node.data;
        if (node.right != null) {
            str += " <= " + node.right.data;
        } else {
            str += " <= END";
        }
        System.out.println(str); // Print the current node

        // Recursively display the left and right subtrees
        if (node.left != null) {
            display(node.left);
        }
        if (node.right != null) {
            display(node.right);
        }
    }

    // Method to get the height of a node
    private int height(Node node) {
        if (node == null) {
            return 0; // Height of null node is 0
        }
        return node.height; // Return the height of the node
    }

    // Method to calculate the balance factor of a node
    private int bf(Node node) {
        if (node == null) {
            return 0; // Balance factor of null node is 0
        }
        return height(node.left) - height(node.right); // Balance factor calculation
    }

    // Method to perform a right rotation on a subtree rooted with 'c'
    private Node rightRotate(Node c) {
        Node b = c.left; // Set b as the left child of c
        Node t3 = b.right; // Store the right child of b
        b.right = c; // Perform rotation
        c.left = t3; // Update the left child of c

        // Update heights of the nodes after rotation
        c.height = Math.max(height(c.left), height(c.right)) + 1;
        b.height = Math.max(height(b.left), height(b.right)) + 1;
        return b; // Return the new root of the subtree
    }

    // Method to perform a left rotation on a subtree rooted with 'c'
    private Node leftRotate(Node c) {
        Node b = c.right; // Set b as the right child of c
        Node t3 = b.left; // Store the left child of b
        b.left = c; // Perform rotation
        c.right = t3; // Update the right child of c

        // Update heights of the nodes after rotation
        c.height = Math.max(height(c.left), height(c.right)) + 1;
        b.height = Math.max(height(b.left), height(b.right)) + 1;
        return b; // Return the new root of the subtree
    }

    // Main method to run the program
    public static void main(String[] args) {
        Main tree = new Main(); // Create an instance of the AVL tree
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input

        // Loop to accept commands until "exit" is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read user input
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if "exit" command is given
            }
            String[] parts = command.split(" "); // Split the command into parts
            try {
                // Process the command based on the first part
                switch (parts[0]) {
                    case "insert":
                        if (parts.length < 2) {
                            System.out.println("Error: Missing value for insert"); // Error for missing value
                        } else {
                            int value = Integer.parseInt(parts[1]); // Parse the value to insert
                            tree.insert(value); // Insert the value into the tree
                            System.out.println("Inserted: " + value); // Confirmation message
                        }
                        break;
                    case "display":
                        tree.display(); // Display the tree structure
                        break;
                    default:
                        System.out.println("Unknown command: " + parts[0]); // Error for unknown command
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions and print error message
            }
        }
        scanner.close(); // Close the scanner
    }
}
