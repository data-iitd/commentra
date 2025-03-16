import java.util.Scanner;

// Define the structure for a node in the binary search tree
class Node {
    Node right; // Pointer to the right child
    Node left;  // Pointer to the left child
    Node parent; // Pointer to the parent node
    int key;    // Key value of the node

    // Constructor to initialize a new node
    Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.parent = null;
    }
}

public class BinarySearchTree {
    private Node root; // Root of the binary search tree

    // Function to find the minimum node in a subtree
    private Node treeMinimum(Node x) {
        while (x.left != null) // Traverse to the leftmost node
            x = x.left;
        return x; // Return the minimum node
    }

    // Function to find the maximum node in a subtree
    private Node treeMaximum(Node x) {
        while (x.right != null) // Traverse to the rightmost node
            x = x.right;
        return x; // Return the maximum node
    }

    // Function to search for a node with a specific key in the tree
    private Node treeSearch(Node u, int k) {
        if (u == null || k == u.key) // Base case: found the node or reached a leaf
            return u;

        // Recursively search in the left or right subtree based on the key
        if (k < u.key)
            return treeSearch(u.left, k);
        else
            return treeSearch(u.right, k);
    }

    // Function to find the successor of a given node in the binary search tree
    private Node treeSuccessor(Node x) {
        Node y;
        if (x.right != null) // If right child exists, successor is the minimum in the right subtree
            return treeMinimum(x.right);

        y = x.parent; // Start with the parent of the current node
        // Traverse up the tree until we find a node that is a left child
        while (y != null && x == y.right) {
            x = y;
            y = y.parent;
        }
        return y; // Return the successor node
    }

    // Function to delete a node from the binary search tree
    private void treeDelete(Node z) {
        Node y; // Node to be deleted
        Node x; // Child of y

        // Determine the node to delete (y) based on the number of children
        if (z.left == null || z.right == null)
            y = z; // If z has one or no children, y is z
        else
            y = treeSuccessor(z); // If z has two children, find its successor

        // Determine the child of y
        if (y.left != null)
            x = y.left;
        else
            x = y.right;

        // Update the parent of x if it exists
        if (x != null)
            x.parent = y.parent;

        // Update the parent's child pointer to x
        if (y.parent == null)
            root = x; // If y is root, update root
        else if (y == y.parent.left)
            y.parent.left = x; // If y is a left child, update left pointer
        else
            y.parent.right = x; // If y is a right child, update right pointer

        // Copy the key from y to z if they are different
        if (y != z)
            z.key = y.key;
    }

    // Function to insert a new key into the binary search tree
    public void insert(int k) {
        Node y = null; // Parent node
        Node x = root; // Current node
        Node z = new Node(k); // New node to be inserted

        // Find the appropriate position for the new node
        while (x != null) {
            y = x; // Keep track of the parent
            if (z.key < x.key) {
                x = x.left; // Move to the left child
            } else {
                x = x.right; // Move to the right child
            }
        }
        z.parent = y; // Set the parent of the new node
        if (y == null)
            root = z; // If tree was empty, new node is root
        else if (z.key < y.key)
            y.left = z; // Insert as left child
        else
            y.right = z; // Insert as right child
    }

    // Function for inorder traversal of the tree
    public void inorder(Node u) {
        if (u == null) return; // Base case: if the node is null, return
        inorder(u.left); // Traverse left subtree
        System.out.print(" " + u.key); // Print the key of the current node
        inorder(u.right); // Traverse right subtree
    }

    // Function for preorder traversal of the tree
    public void preorder(Node u) {
        if (u == null) return; // Base case: if the node is null, return
        System.out.print(" " + u.key); // Print the key of the current node
        preorder(u.left); // Traverse left subtree
        preorder(u.right); // Traverse right subtree
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree bst = new BinarySearchTree();
        int n = scanner.nextInt(); // Read the number of commands

        // Loop to process each command
        for (int i = 0; i < n; i++) {
            String com = scanner.next(); // Read the command
            if (com.charAt(0) == 'f') { // If command is 'find'
                int x = scanner.nextInt(); // Read the key to find
                Node t = bst.treeSearch(bst.root, x); // Search for the key
                if (t != null)
                    System.out.println("yes"); // Key found
                else
                    System.out.println("no"); // Key not found
            } else if (com.charAt(0) == 'i') { // If command is 'insert'
                int x = scanner.nextInt(); // Read the key to insert
                bst.insert(x); // Insert the key into the tree
            } else if (com.charAt(0) == 'p') { // If command is 'print'
                bst.inorder(bst.root); // Print the tree in inorder
                System.out.println();
                bst.preorder(bst.root); // Print the tree in preorder
                System.out.println();
            } else if (com.charAt(0) == 'd') { // If command is 'delete'
                int x = scanner.nextInt(); // Read the key to delete
                bst.treeDelete(bst.treeSearch(bst.root, x)); // Delete the node with the key
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
