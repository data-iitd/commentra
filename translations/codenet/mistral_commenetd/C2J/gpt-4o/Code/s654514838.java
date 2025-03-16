import java.util.Scanner;

// Define a class for a node in the AVL tree
class Node {
    int key;      // The key value of the node
    int priority; // The priority value of the node
    Node right, left; // Pointers to the right and left children

    // Constructor to create a new node
    Node(int key, int priority) {
        this.key = key;
        this.priority = priority;
        this.left = null;
        this.right = null;
    }
}

public class AVLTree {
    // Function to check if a key is present in the AVL tree
    static boolean find(Node p, int x) {
        // While the current node is not null
        while (p != null) {
            // If the key is found, return true
            if (p.key == x) return true;
            // If the key is smaller than the current node's key, move to the left
            else if (p.key > x) p = p.left;
            // Otherwise, move to the right
            else p = p.right;
        }
        // If the key is not found, return false
        return false;
    }

    // Function to perform an inorder traversal of the AVL tree and print the keys
    static void inorder(Node a) {
        if (a != null) {
            inorder(a.left);
            System.out.print(" " + a.key);
            inorder(a.right);
        }
    }

    // Function to perform a preorder traversal of the AVL tree and print the keys
    static void preorder(Node p) {
        if (p != null) {
            System.out.print(" " + p.key);
            preorder(p.left);
            preorder(p.right);
        }
    }

    // Function to print the AVL tree
    static void print(Node p) {
        inorder(p);
        preorder(p);
    }

    // Function to perform a right rotation on an AVL tree
    static Node rightRotate(Node p) {
        Node q = p.left;
        p.left = q.right;
        q.right = p;
        return q;
    }

    // Function to perform a left rotation on an AVL tree
    static Node leftRotate(Node p) {
        Node q = p.right;
        p.right = q.left;
        q.left = p;
        return q;
    }

    // Function to insert a new node into the AVL tree
    static Node insert(Node t, int key, int priority) {
        // If the tree is empty, create a new node and return it
        if (t == null) return new Node(key, priority);
        // Recursively search for the location to insert the new node
        if (key < t.key) t.left = insert(t.left, key, priority);
        else t.right = insert(t.right, key, priority);

        // If the new node becomes the root, check if it needs to be rotated
        if (t.priority < (t.left != null ? t.left.priority : Integer.MIN_VALUE) || 
            t.priority < (t.right != null ? t.right.priority : Integer.MIN_VALUE)) {
            // Perform a right rotation if the left child has a higher priority
            if (t.left != null && (t.left.priority > (t.right != null ? t.right.priority : Integer.MIN_VALUE)))
                t = rightRotate(t);
            // Perform a left rotation if the right child has a higher priority
            else
                t = leftRotate(t);
        }
        // Return the updated tree
        return t;
    }

    // Function to delete a node from the AVL tree
    static Node delete(Node t, int key) {
        // If the tree is empty, do nothing
        if (t == null) return null;
        // Recursively search for the node to delete
        if (key < t.key) t.left = delete(t.left, key);
        else if (key > t.key) t.right = delete(t.right, key);
        // If the node to be deleted was found, delete it and update the tree
        else {
            Node q = t;
            if (t.left == null) return t.right;
            else if (t.right == null) return t.left;
            t = (t.left.priority > t.right.priority) ? rightRotate(t) : leftRotate(t);
        }
        // If the deleted node was a rotated node, check if the tree needs to be rotated
        if (t.priority < (t.left != null ? t.left.priority : Integer.MIN_VALUE) || 
            t.priority < (t.right != null ? t.right.priority : Integer.MIN_VALUE)) {
            // Perform a right rotation if the left child has a higher priority
            if (t.left != null && (t.left.priority > (t.right != null ? t.right.priority : Integer.MIN_VALUE)))
                t = rightRotate(t);
            // Perform a left rotation if the right child has a higher priority
            else
                t = leftRotate(t);
        }
        // Return the updated tree
        return t;
    }

    // Main function to read commands and perform the corresponding operations on the AVL tree
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node root = null;
        // Read the number of commands
        int num = scanner.nextInt();
        // Process each command
        for (int i = 0; i < num; i++) {
            String command = scanner.next();
            // Based on the command, perform the corresponding operation on the AVL tree
            switch (command.charAt(0)) {
                case 'i': // Insert a new node
                    int x = scanner.nextInt();
                    int y = scanner.nextInt();
                    root = insert(root, x, y);
                    break;
                case 'd': // Delete a node
                    x = scanner.nextInt();
                    root = delete(root, x);
                    break;
                case 'f': // Find a node
                    x = scanner.nextInt();
                    System.out.println(find(root, x) ? "yes" : "no");
                    break;
                case 'p': // Print the AVL tree
                    print(root);
                    break;
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
