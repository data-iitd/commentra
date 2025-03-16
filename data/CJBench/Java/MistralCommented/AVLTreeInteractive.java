
import java.util.Scanner;

public class Main {
    // Declare a private reference to the root node
    private Node root;

    // Define a private nested static class Node
    private static class Node {
        // Declare instance variables for each node property
        private int key;
        private int balance; // Balance factor of this node
        private int height; // Height of this node
        private Node left; // Left child node
        private Node right; // Right child node
        private Node parent; // Parent node

        // Constructor for a new Node with given key and parent
        Node(int k, Node p) {
            key = k;
            parent = p;
        }
    }

    // Public method to insert a new key into the tree
    public boolean insert(int key) {
        if (root == null) { // If the tree is empty, create a new root node
            root = new Node(key, null);
        } else {
            Node n = root; // Initialize a reference to the current node
            Node parent; // Initialize a reference to the parent node

            // Perform a standard tree traversal to find the insertion point
            while (true) {
                if (n.key == key) {
                    // If the key already exists in the tree, return false
                    return false;
                }
                parent = n; // Update the parent reference
                boolean goLeft = n.key > key; // Determine whether to go left or right
                n = goLeft ? n.left : n.right; // Move to the next node accordingly

                if (n == null) { // If we reached an empty node, insert the new node here
                    if (goLeft) {
                        parent.left = new Node(key, parent);
                    } else {
                        parent.right = new Node(key, parent);
                    }
                    rebalance(parent); // Rebalance the tree after insertion
                    break;
                }
            }
        }
        // Return true to indicate a successful insertion
        return true;
    }

    // Public method to delete a key from the tree
    public void delete(int delKey) {
        if (root == null) { // If the tree is empty, do nothing
            return;
        }
        Node node = root; // Initialize a reference to the current node
        Node child = root; // Initialize a reference to the child node

        // Perform a standard tree traversal to find the node to be deleted
        while (child != null) {
            node = child; // Update the current node reference
            child = delKey >= node.key ? node.right : node.left; // Move to the next node accordingly

            if (delKey == node.key) { // If we found the node to be deleted
                deleteNode(node); // Call the deleteNode method to perform the deletion
                return;
            }
        }
    }

    // Private method to perform the actual deletion of a node
    private void deleteNode(Node node) {
        if (node.left == null && node.right == null) { // If the node is a leaf node
            if (node.parent == null) { // If the root node is being deleted
                root = null;
            } else {
                Node parent = node.parent; // Update the parent reference
                if (parent.left == node) { // Determine which child the deleted node was
                    parent.left = null;
                } else {
                    parent.right = null;
                }
                rebalance(parent); // Rebalance the tree after deletion
            }
            return;
        }

        Node child; // Initialize a reference to the child node
        if (node.left != null) { // If the node has a left child
            child = node.left; // Set the child reference to the left child

            // Find the smallest node in the right subtree and copy its key to the node to be deleted
            while (child.right != null) {
                child = child.right;
            }
            node.key = child.key;
        } else { // If the node has a right child
            child = node.right; // Set the child reference to the right child

            // Find the smallest node in the left subtree and copy its key to the node to be deleted
            while (child.left != null) {
                child = child.left;
            }
            node.key = child.key;
        }

        // Recursively delete the child node
        deleteNode(child);
    }

    // Public method to search for a key in the tree
    public boolean search(int key) {
        Node result = searchHelper(this.root, key); // Call the searchHelper method to perform the search
        return result != null; // Return true if the key was found, false otherwise
    }

    // Private method to perform the actual search
    private Node searchHelper(Node root, int key) {
        if (root == null || root.key == key) { // If the tree is empty or the key was found
            return root;
        }
        return key < root.key ? searchHelper(root.left, key) : searchHelper(root.right, key); // Recursively search the left or right subtree
    }

    // Public method to display the contents of the tree
    public void display() {
        displayHelper(this.root); // Call the displayHelper method to perform the display
    }

    // Private method to recursively display the contents of the tree
    private void displayHelper(Node node) {
        if (node != null) { // If the node is not null
            displayHelper(node.left); // Recursively display the left subtree
            System.out.print(node.key + " "); // Print the key of the current node
            displayHelper(node.right); // Recursively display the right subtree
        }
    }

    // Private method to rebalance the tree after an insertion or deletion
    private void rebalance(Node n) {
        setBalance(n); // Calculate the balance factors of all nodes in the tree

        if (n.balance == -2) { // If the balance factor of the current node is -2 (left-heavy)
            if (height(n.left.left) >= height(n.left.right)) { // If the left child is also left-heavy
                n = rotateRight(n); // Perform a right rotation
            } else { // If the left child is right-heavy
                n = rotateLeftThenRight(n); // Perform a left rotation followed by a right rotation
            }
        } else if (n.balance == 2) { // If the balance factor of the current node is 2 (right-heavy)
            if (height(n.right.right) >= height(n.right.left)) { // If the right child is also right-heavy
                n = rotateLeft(n); // Perform a left rotation
            } else { // If the right child is left-heavy
                n = rotateRightThenLeft(n); // Perform a right rotation followed by a left rotation
            }
        }

        if (n.parent != null) { // If the current node has a parent
            rebalance(n.parent); // Recursively rebalance the parent node
        } else { // If the current node is the root
            root = n; // Update the root reference
        }
    }

    // Private method to perform a right rotation
    private Node rotateRight(Node a) {
        Node b = a.left; // Set the right child as the new root
        b.parent = a.parent; // Update the parent reference of the new root
        a.left = b.right; // Set the left child of the old root to the right child of the new root

        if (a.left != null) { // If the old root has a left child
            a.left.parent = a; // Set the parent reference of the left child
        }

        b.right = a; // Set the right child of the new root to the old root
        a.parent = b; // Set the parent reference of the old root to the new root

        setBalance(a, b); // Recalculate the balance factors
        return b; // Return the new root
    }

    // Private method to perform a left rotation
    private Node rotateLeft(Node a) {
        Node b = a.right; // Set the left child as the new root
        b.parent = a.parent; // Update the parent reference of the new root
        a.right = b.left; // Set the right child of the old root to the left child of the new root

        if (a.right != null) { // If the old root has a right child
            a.right.parent = a; // Set the parent reference of the right child
        }

        b.left = a; // Set the left child of the new root to the old root
        a.parent = b; // Set the parent reference of the old root to the new root

        setBalance(a, b); // Recalculate the balance factors
        return b; // Return the new root
    }

    // Private method to perform a left-right rotation (double rotation)
    private Node rotateLeftThenRight(Node n) {
        n.left = rotateLeft(n.left); // Perform a left rotation on the left child
        return rotateRight(n); // Perform a right rotation on the new root
    }

    // Private method to calculate the height of a node
    private int height(Node node) {
        return node == null ? -1 : node.height; // Return the height if it's already calculated, or calculate it and store it
    }

    // Private method to set the balance factors of a node and its children
    private void setBalance(Node... nodes) {
        for (Node n : nodes) { // Iterate through all the nodes
            reheight(n); // Recalculate the height
            n.balance = height(n.right) - height(n.left); // Calculate the balance factor
        }
    }

    // Private method to recalculate the height of a node
    private void reheight(Node node) {
        if (node != null) { // If the node is not null
            node.height = 1 + Math.max(height(node.left), height(node.right)); // Set the height based on the heights of its children
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Main tree = new Main(); // Create a new instanc