import java.util.Scanner;

class Node {
    int l, r, par;  // l: left child, r: right child, par: parent

    Node() {
        this.l = this.r = this.par = -1;  // Initialize children and parent to -1
    }
}

public class TreeTraversal {
    static final int MAX = 25;  // Define the maximum number of nodes in the tree
    static Node[] N = new Node[MAX];  // Array to hold the nodes of the tree

    // Function prototypes for tree operations
    static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node();  // Initialize each node
        }
    }

    static void Preorder(int p) {
        if (p != -1) {  // Check if the node is valid
            System.out.print(" " + p);  // Print the current node
            Preorder(N[p].l);  // Recursively traverse the left subtree
            Preorder(N[p].r);  // Recursively traverse the right subtree
        }
    }

    static void Inorder(int p) {
        if (p != -1) {  // Check if the node is valid
            Inorder(N[p].l);  // Recursively traverse the left subtree
            System.out.print(" " + p);  // Print the current node
            Inorder(N[p].r);  // Recursively traverse the right subtree
        }
    }

    static void Postorder(int p) {
        if (p != -1) {  // Check if the node is valid
            Postorder(N[p].l);  // Recursively traverse the left subtree
            Postorder(N[p].r);  // Recursively traverse the right subtree
            System.out.print(" " + p);  // Print the current node
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, id, l, r;  // Variables for number of nodes, node id, left and right children
        int p = -1;  // Variable to hold the root node id

        // Read the number of nodes in the tree
        n = scanner.nextInt();
        init(n);  // Initialize the tree nodes

        // Read the tree structure from input
        for (int i = 0; i < n; i++) {
            id = scanner.nextInt();
            l = scanner.nextInt();
            r = scanner.nextInt();

            // If left child is not -1, set the left child and parent
            if (l != -1) {
                N[id].l = l;  // Set left child
                N[l].par = id;  // Set parent of left child
            }
            // If right child is not -1, set the right child and parent
            if (r != -1) {
                N[id].r = r;  // Set right child
                N[r].par = id;  // Set parent of right child
            }
        }

        // Find the root of the tree (the node with no parent)
        for (int i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i;  // Store the root node id
                break;  // Exit the loop once the root is found
            }
        }

        // Perform and display the tree traversals
        System.out.println("Preorder");
        Preorder(p);  // Call Preorder traversal starting from the root
        System.out.println();

        System.out.println("Inorder");
        Inorder(p);  // Call Inorder traversal starting from the root
        System.out.println();

        System.out.println("Postorder");
        Postorder(p);  // Call Postorder traversal starting from the root
        System.out.println();

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
