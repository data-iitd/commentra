import java.util.Scanner;

public class Main {
    // Root node of the AVL tree
    private Node root;

    // Node class representing each node in the AVL tree
    private static class Node {
        private int key; // Key value of the node
        private int balance; // Balance factor of the node
        private int height; // Height of the node
        private Node left; // Left child of the node
        private Node right; // Right child of the node
        private Node parent; // Parent of the node

        // Constructor to initialize a node with a key and parent
        Node(int k, Node p) {
            key = k;
            parent = p;
        }
    }

    // Method to insert a new key into the AVL tree
    public boolean insert(int key) {
        // If the tree is empty, create the root node
        if (root == null) {
            root = new Node(key, null);
        } else {
            Node n = root;
            Node parent;
            while (true) {
                // Check for duplicate keys
                if (n.key == key) {
                    return false; // Key already exists
                }
                parent = n;
                // Determine whether to go left or right in the tree
                boolean goLeft = n.key > key;
                n = goLeft ? n.left : n.right;
                // If the child node is null, insert the new node
                if (n == null) {
                    if (goLeft) {
                        parent.left = new Node(key, parent);
                    } else {
                        parent.right = new Node(key, parent);
                    }
                    // Rebalance the tree after insertion
                    rebalance(parent);
                    break;
                }
            }
        }
        return true; // Insertion successful
    }

    // Method to delete a key from the AVL tree
    public void delete(int delKey) {
        // If the tree is empty, there's nothing to delete
        if (root == null) {
            return;
        }
        Node node = root;
        Node child = root;
        // Traverse the tree to find the node to delete
        while (child != null) {
            node = child;
            child = delKey >= node.key ? node.right : node.left;
            // If the key is found, delete the node
            if (delKey == node.key) {
                deleteNode(node);
                return;
            }
        }
    }

    // Helper method to delete a specific node from the tree
    private void deleteNode(Node node) {
        // Case 1: Node has no children (leaf node)
        if (node.left == null && node.right == null) {
            // If it's the root node, set root to null
            if (node.parent == null) {
                root = null;
            } else {
                Node parent = node.parent;
                // Remove the node from its parent's child reference
                if (parent.left == node) {
                    parent.left = null;
                } else {
                    parent.right = null;
                }
                // Rebalance the tree after deletion
                rebalance(parent);
            }
            return;
        }

        // Case 2: Node has one child
        Node child;
        if (node.left != null) {
            // Find the maximum node in the left subtree
            child = node.left;
            while (child.right != null) {
                child = child.right;
            }
        } else {
            // Find the minimum node in the right subtree
            child = node.right;
            while (child.left != null) {
                child = child.left;
            }
        }
        // Replace the key of the node to be deleted with the found child's key
        node.key = child.key;
        // Recursively delete the child node
        deleteNode(child);
    }

    // Method to search for a key in the AVL tree
    public boolean search(int key) {
        Node result = searchHelper(this.root, key);
        return result != null; // Return true if found, false otherwise
    }

    // Helper method to perform the actual search
    private Node searchHelper(Node root, int key) {
        // Base case: if root is null or key is found
        if (root == null || root.key == key) {
            return root;
        }
        // Recursively search left or right subtree based on key comparison
        return key < root.key ? searchHelper(root.left, key) : searchHelper(root.right, key);
    }

    // Method to display the keys in the AVL tree in sorted order
    public void display() {
        displayHelper(this.root);
        System.out.println(); // Print a newline after displaying all keys
    }

    // Helper method to perform in-order traversal of the tree
    private void displayHelper(Node node) {
        if (node != null) {
            displayHelper(node.left); // Visit left subtree
            System.out.print(node.key + " "); // Print the key
            displayHelper(node.right); // Visit right subtree
        }
    }

    // Method to rebalance the AVL tree after insertion or deletion
    private void rebalance(Node n) {
        setBalance(n); // Update balance factors
        // Perform rotations based on balance factor
        if (n.balance == -2) {
            if (height(n.left.left) >= height(n.left.right)) {
                n = rotateRight(n); // Right rotation
            } else {
                n = rotateLeftThenRight(n); // Left-Right rotation
            }
        } else if (n.balance == 2) {
            if (height(n.right.right) >= height(n.right.left)) {
                n = rotateLeft(n); // Left rotation
            } else {
                n = rotateRightThenLeft(n); // Right-Left rotation
            }
        }
        // Rebalance the parent node if it exists
        if (n.parent != null) {
            rebalance(n.parent);
        } else {
            root = n; // Update root if necessary
        }
    }

    // Method to perform a left rotation on a given node
    private Node rotateLeft(Node a) {
        Node b = a.right; // Right child becomes the new root
        b.parent = a.parent; // Update parent reference
        a.right = b.left; // Move left child of b to be the right child of a
        if (a.right != null) {
            a.right.parent = a; // Update parent reference of the new right child
        }
        b.left = a; // Set a as the left child of b
        a.parent = b; // Update parent reference of a
        setBalance(a, b); // Update balance factors
        return b; // Return the new root
    }

    // Method to perform a right rotation on a given node
    private Node rotateRight(Node a) {
        Node b = a.left; // Left child becomes the new root
        b.parent = a.parent; // Update parent reference
        a.left = b.right; // Move right child of b to be the left child of a
        if (a.left != null) {
            a.left.parent = a; // Update parent reference of the new left child
        }
        b.right = a; // Set a as the right child of b
        a.parent = b; // Update parent reference of a
        setBalance(a, b); // Update balance factors
        return b; // Return the new root
    }

    // Method to perform a left rotation followed by a right rotation
    private Node rotateLeftThenRight(Node n) {
        n.left = rotateLeft(n.left); // Perform left rotation on left child
        return rotateRight(n); // Perform right rotation on n
    }

    // Method to perform a right rotation followed by a left rotation
    private Node rotateRightThenLeft(Node n) {
        n.right = rotateRight(n.right); // Perform right rotation on right child
        return rotateLeft(n); // Perform left rotation on n
    }

    // Method to get the height of a node
    private int height(Node n) {
        return n == null ? -1 : n.height; // Return -1 for null, otherwise return height
    }

    // Method to set the balance factors for given nodes
    private void setBalance(Node... nodes) {
        for (Node n : nodes) {
            reheight(n); // Update height
            n.balance = height(n.right) - height(n.left); // Calculate balance factor
        }
    }

    // Method to update the height of a node
    private void reheight(Node node) {
        if (node != null) {
            node.height = 1 + Math.max(height(node.left), height(node.right)); // Update height based on children
        }
    }

    // Main method to run the AVL tree operations
    public static void main(String[] args) {
        Main tree = new Main(); // Create an instance of the AVL tree
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        // Loop to continuously accept commands until "exit" is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read user command
            if (command.equalsIgnoreCase("exit")) {
                break; // Exit the loop if the command is "exit"
            }
            String[] parts = command.split(" "); // Split command into parts
            try {
                // Process commands for insert, delete, search, and display
                switch (parts[0]) {
                    case "insert":
                        int valueToInsert = Integer.parseInt(parts[1]); // Parse the value to insert
                        tree.insert(valueToInsert); // Insert the value into the tree
                        System.out.println("Inserted: " + valueToInsert);
                        break;
                    case "delete":
                        int valueToDelete = Integer.parseInt(parts[1]); // Parse the value to delete
                        tree.delete(valueToDelete); // Delete the value from the tree
                        System.out.println("Deleted: " + valueToDelete);
                        break;
                    case "search":
                        int valueToSearch = Integer.parseInt(parts[1]); // Parse the value to search
                        System.out.println(tree.search(valueToSearch) ? "Found" : "Not Found"); // Search and print result
                        break;
                    case "display":
                        tree.display(); // Display the tree
                        break;
                    default:
                        System.out.println("Unknown command"); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Invalid command or input"); // Handle invalid input
            }
        }
        scanner.close(); // Close the scanner
    }
}
