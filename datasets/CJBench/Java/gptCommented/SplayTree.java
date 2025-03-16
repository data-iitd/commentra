import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a constant for in-order traversal strategy
    public static final TreeTraversal IN_ORDER = new InOrderTraversal();
    private Node root; // Root node of the splay tree

    // Check if the tree is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Insert a new key into the splay tree
    public void insert(final int key) {
        root = insertRec(root, key); // Insert the key recursively
        root = splay(root, key); // Splay the tree to bring the inserted key to the root
    }

    // Search for a key in the splay tree
    public boolean search(int key) {
        root = splay(root, key); // Splay the tree to bring the searched key to the root
        return root != null && root.key == key; // Return true if the key is found
    }

    // Delete a key from the splay tree
    public void delete(final int key) {
        if (isEmpty()) {
            throw new EmptyTreeException("Cannot delete from an empty tree"); // Handle deletion from an empty tree
        }
        root = splay(root, key); // Splay the tree to bring the key to the root
        if (root.key != key) {
            return; // If the key is not found, do nothing
        }
        // If the node to be deleted has no left child
        if (root.left == null) {
            root = root.right; // Replace root with its right child
        } else {
            Node temp = root; // Temporarily store the root
            root = splay(root.left, findMax(root.left).key); // Splay the left subtree and find the max node
            root.right = temp.right; // Attach the right subtree
        }
    }

    // Traverse the tree using the specified traversal strategy
    public List<Integer> traverse(TreeTraversal traversal) {
        List<Integer> result = new ArrayList<>(); // List to hold the traversal result
        traversal.traverse(root, result); // Perform the traversal
        return result; // Return the result list
    }

    // Find the maximum node in a subtree
    private Node findMax(Node root) {
        while (root.right != null) {
            root = root.right; // Traverse to the rightmost node
        }
        return root; // Return the maximum node
    }

    // Perform a right rotation on a subtree
    private Node rotateRight(Node x) {
        Node y = x.left; // Identify the left child
        x.left = y.right; // Move the right child of y to be the left child of x
        y.right = x; // Perform the rotation
        return y; // Return the new root of the subtree
    }

    // Perform a left rotation on a subtree
    private Node rotateLeft(Node x) {
        Node y = x.right; // Identify the right child
        x.right = y.left; // Move the left child of y to be the right child of x
        y.left = x; // Perform the rotation
        return y; // Return the new root of the subtree
    }

    // Splay the tree to bring the specified key to the root
    private Node splay(Node root, final int key) {
        if (root == null || root.key == key) {
            return root; // Return if root is null or key is found
        }
        if (root.key > key) {
            if (root.left == null) {
                return root; // If there's no left child, return root
            }
            if (root.left.key > key) {
                root.left.left = splay(root.left.left, key); // Recursively splay the left-left subtree
                root = rotateRight(root); // Rotate right
            } else if (root.left.key < key) {
                root.left.right = splay(root.left.right, key); // Recursively splay the left-right subtree
                if (root.left.right != null) {
                    root.left = rotateLeft(root.left); // Rotate left
                }
            }
            return (root.left == null) ? root : rotateRight(root); // Final rotation if necessary
        } else {
            if (root.right == null) {
                return root; // If there's no right child, return root
            }
            if (root.right.key > key) {
                root.right.left = splay(root.right.left, key); // Recursively splay the right-left subtree
                if (root.right.left != null) {
                    root.right = rotateRight(root.right); // Rotate right
                }
            } else if (root.right.key < key) {
                root.right.right = splay(root.right.right, key); // Recursively splay the right-right subtree
                root = rotateLeft(root); // Rotate left
            }
            return (root.right == null) ? root : rotateLeft(root); // Final rotation if necessary
        }
    }

    // Recursive method to insert a key into the tree
    private Node insertRec(Node root, final int key) {
        if (root == null) {
            return new Node(key); // Create a new node if the position is empty
        }
        if (key < root.key) {
            root.left = insertRec(root.left, key); // Insert in the left subtree
        } else if (key > root.key) {
            root.right = insertRec(root.right, key); // Insert in the right subtree
        } else {
            throw new DuplicateKeyException("Duplicate key: " + key); // Handle duplicate keys
        }
        return root; // Return the unchanged root
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main splayTree = new Main(); // Create an instance of the splay tree
        int n = scanner.nextInt(); // Read the number of operations
        for (int i = 0; i < n; i++) {
            int choice = scanner.nextInt(); // Read the operation choice
            switch (choice) {
                case 1: // Insert operation
                    int valueToInsert = scanner.nextInt(); // Read the value to insert
                    splayTree.insert(valueToInsert); // Insert the value
                    System.out.println("Inserted " + valueToInsert); // Confirm insertion
                    break;
                case 2: // Delete operation
                    int valueToDelete = scanner.nextInt(); // Read the value to delete
                    try {
                        splayTree.delete(valueToDelete); // Attempt to delete the value
                        System.out.println("Deleted " + valueToDelete); // Confirm deletion
                    } catch (EmptyTreeException e) {
                        System.out.println(e.getMessage()); // Handle exception if tree is empty
                    }
                    break;
                case 3: // Search operation
                    int valueToSearch = scanner.nextInt(); // Read the value to search
                    boolean found = splayTree.search(valueToSearch); // Search for the value
                    System.out.println(found ? "Found " + valueToSearch : "Not found"); // Print result
                    break;
                case 4: // In-order traversal operation
                    System.out.println("In-order traversal:");
                    System.out.println(splayTree.traverse(IN_ORDER)); // Perform in-order traversal and print result
                    break;
                default: // Handle invalid operation
                    System.out.println("Invalid operation.");
            }
        }
        scanner.close(); // Close the scanner
    }

    // Node class representing each node in the splay tree
    private static class Node {
        final int key; // Key value of the node
        Node left; // Left child
        Node right; // Right child

        Node(int key) {
            this.key = key; // Initialize the key
            left = null; // Initialize left child to null
            right = null; // Initialize right child to null
        }
    }

    // Exception class for handling empty tree scenarios
    public static class EmptyTreeException extends RuntimeException {
        public EmptyTreeException(String message) {
            super(message); // Pass the message to the superclass
        }
    }

    // Exception class for handling duplicate key scenarios
    public static class DuplicateKeyException extends RuntimeException {
        public DuplicateKeyException(String message) {
            super(message); // Pass the message to the superclass
        }
    }

    // Interface for tree traversal strategies
    public interface TreeTraversal {
        void traverse(Node root, List<Integer> result); // Method to traverse the tree
    }

    // In-order traversal implementation of the TreeTraversal interface
    private static final class InOrderTraversal implements TreeTraversal {
        public void traverse(Node root, List<Integer> result) {
            if (root != null) {
                traverse(root.left, result); // Traverse left subtree
                result.add(root.key); // Add the root key to the result
                traverse(root.right, result); // Traverse right subtree
            }
        }
    }
}
