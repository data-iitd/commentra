import java.util.Scanner;

// Definition of the node structure for the treap
class Node {
    int key;            // Key of the node
    int priority;       // Priority of the node
    Node right;         // Pointer to the right child
    Node left;          // Pointer to the left child

    Node(int key, int priority) {
        this.key = key;
        this.priority = priority;
        this.left = null; // Initialize left child to null
        this.right = null; // Initialize right child to null
    }
}

public class Treap {
    private Node root; // Root of the treap

    // Function to find a key in the treap
    private boolean find(Node p, int x) {
        while (p != null) { // Traverse until a leaf is reached
            if (p.key == x) return true; // Key found
            else if (p.key > x) p = p.left; // Move to the left child
            else p = p.right; // Move to the right child
        }
        return false; // Key not found
    }

    // Function for inorder traversal of the treap
    private void inorder(Node a) {
        if (a != null) {
            inorder(a.left); // Traverse left subtree
            System.out.print(" " + a.key); // Print the current node's key
            inorder(a.right); // Traverse right subtree
        }
    }

    // Function for preorder traversal of the treap
    private void preorder(Node p) {
        if (p != null) {
            System.out.print(" " + p.key); // Print the current node's key
            preorder(p.left); // Traverse left subtree
            preorder(p.right); // Traverse right subtree
        }
    }

    // Function to print the treap in both inorder and preorder
    private void print(Node p) {
        inorder(p); // Print inorder
        System.out.println();
        preorder(p); // Print preorder
        System.out.println();
    }

    // Function to perform a right rotation on the treap
    private Node rightRotate(Node p) {
        Node q = p.left; // Store the left child
        p.left = q.right; // Move the right child of left child to the left of p
        q.right = p; // Perform the rotation
        return q; // Return the new root after rotation
    }

    // Function to perform a left rotation on the treap
    private Node leftRotate(Node p) {
        Node q = p.right; // Store the right child
        p.right = q.left; // Move the left child of right child to the right of p
        q.left = p; // Perform the rotation
        return q; // Return the new root after rotation
    }

    // Function to insert a new node into the treap
    public Node insert(Node t, int key, int priority) {
        if (t == null) {
            return new Node(key, priority); // Create a new node if leaf is reached
        }
        if (t.key == key) {
            return t; // Ignore duplicate keys
        }

        if (key < t.key) { // Move to the left child
            t.left = insert(t.left, key, priority); // Update left child pointer
            if (t.priority < t.left.priority) { // Right rotation if left child has higher priority
                t = rightRotate(t);
            }
        } else { // Move to the right child
            t.right = insert(t.right, key, priority); // Update right child pointer
            if (t.priority < t.right.priority) { // Left rotation if right child has higher priority
                t = leftRotate(t);
            }
        }
        return t; // Return the updated root
    }

    // Function to delete a node from the treap
    public Node Delete(Node t, int key) {
        if (t == null) {
            return null; // Return null if the tree is empty
        }

        if (key < t.key) { // Search for the key in the left subtree
            t.left = Delete(t.left, key);
        } else if (key > t.key) { // Search for the key in the right subtree
            t.right = Delete(t.right, key);
        } else {
            return delete(t, key); // Key found, proceed to delete it
        }
        return t; // Return the updated root
    }

    // Helper function to handle the actual deletion of a node
    private Node delete(Node t, int key) {
        if (t.left == null && t.right == null) { // Case: Leaf node
            return null; // Remove the leaf node
        } else if (t.left == null) { // Case: Node with only right child
            return leftRotate(t); // Perform left rotation
        } else if (t.right == null) { // Case: Node with only left child
            return rightRotate(t); // Perform right rotation
        } else { // Case: Node with both children
            if (t.left.priority > t.right.priority) { // Compare priorities
                t = rightRotate(t); // Rotate right if left child has higher priority
            } else {
                t = leftRotate(t); // Rotate left otherwise
            }
        }
        return Delete(t, key); // Continue deletion process
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Treap treap = new Treap();
        int num = scanner.nextInt(); // Read the number of commands

        for (int i = 0; i < num; i++) {
            String command = scanner.next(); // Read the command
            switch (command.charAt(0)) { // Determine the command type
                case 'i': // Insert command
                    int x = scanner.nextInt(); // Read key
                    int y = scanner.nextInt(); // Read priority
                    treap.root = treap.insert(treap.root, x, y); // Insert the new node
                    break;
                case 'd': // Delete command
                    x = scanner.nextInt(); // Read key to delete
                    treap.root = treap.Delete(treap.root, x); // Delete the node
                    break;
                case 'f': // Find command
                    x = scanner.nextInt(); // Read key to find
                    if (treap.find(treap.root, x)) {
                        System.out.println("yes"); // Print "yes" if found
                    } else {
                        System.out.println("no"); // Print "no" if not found
                    }
                    break;
                case 'p': // Print command
                    treap.print(treap.root); // Print the treap
                    break;
            }
        }
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
