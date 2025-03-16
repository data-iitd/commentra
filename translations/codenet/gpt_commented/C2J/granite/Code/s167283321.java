
import java.util.Scanner;

public class s167283321{
    static final int NIL = -1;

    // Define a structure to represent a node in the tree
    static class Node {
        int parent, left, right; // parent, left child, and right child indices
    }

    // Array to hold the nodes of the tree
    static Node[] R = new Node[10000];
    static int n; // Number of nodes in the tree

    // Function prototypes for tree traversal
    static void preorder(int);
    static void inorder(int);
    static void postorder(int);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes in the tree
        n = scanner.nextInt();

        // Initialize all nodes' parents to NIL
        for (int i = 0; i < n; i++)
            R[i] = new Node();
            R[i].parent = NIL;

        // Read the tree structure from input
        for (int i = 0; i < n; i++) {
            // Read the current node and its left and right children
            int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt();
            R[a].left = b; // Set left child
            R[a].right = c; // Set right child
            // Update the parent of the left child if it is not NIL
            if (b!= NIL) R[b].parent = a;
            // Update the parent of the right child if it is not NIL
            if (c!= NIL) R[c].parent = a;
        }

        // Find the root of the tree (the node with no parent)
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (R[i].parent == NIL)
                root = i; // Assign root node
        }

        // Perform and print the results of the tree traversals
        System.out.println("Preorder");
        preorder(root); // Call preorder traversal
        System.out.println();

        System.out.println("Inorder");
        inorder(root); // Call inorder traversal
        System.out.println();

        System.out.println("Postorder");
        postorder(root); // Call postorder traversal
        System.out.println();

        scanner.close(); // Close the scanner
    }

    // Preorder traversal function
    static void preorder(int x) {
        // Base case: if the current node is NIL, return
        if (x == NIL)
            return;
        // Print the current node's value
        System.out.print(" " + x);
        // Recursively traverse the left subtree
        preorder(R[x].left);
        // Recursively traverse the right subtree
        preorder(R[x].right);
    }

    // Inorder traversal function
    static void inorder(int x) {
        // Base case: if the current node is NIL, return
        if (x == NIL)
            return;
        // Recursively traverse the left subtree
        inorder(R[x].left);
        // Print the current node's value
        System.out.print(" " + x);
        // Recursively traverse the right subtree
        inorder(R[x].right);
    }

    // Postorder traversal function
    static void postorder(int x) {
        // Base case: if the current node is NIL, return
        if (x == NIL)
            return;
        // Recursively traverse the left subtree
        postorder(R[x].left);
        // Recursively traverse the right subtree
        postorder(R[x].right);
        // Print the current node's value
        System.out.print(" " + x);
    }
}

