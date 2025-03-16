import java.util.Scanner;

class Node {
    int l, r, par; // l: left child, r: right child, par: parent

    Node() {
        this.l = -1;
        this.r = -1;
        this.par = -1;
    }
}

public class BinaryTree {
    static final int MAX = 25; // Define the maximum number of nodes
    static Node[] N = new Node[MAX]; // Array of nodes

    // Function declarations
    static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node(); // Initialize each node
        }
    }

    static void Preorder(int p) {
        if (p != -1) {
            System.out.print(" " + p); // Print current node
            Preorder(N[p].l); // Recursively traverse left subtree
            Preorder(N[p].r); // Recursively traverse right subtree
        }
    }

    static void Inorder(int p) {
        if (p != -1) {
            Inorder(N[p].l); // Recursively traverse left subtree
            System.out.print(" " + p); // Print current node
            Inorder(N[p].r); // Recursively traverse right subtree
        }
    }

    static void Postorder(int p) {
        if (p != -1) {
            Postorder(N[p].l); // Recursively traverse left subtree
            Postorder(N[p].r); // Recursively traverse right subtree
            System.out.print(" " + p); // Print current node
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, id, l, r, p = -1;

        n = scanner.nextInt(); // Read the number of nodes
        init(n); // Initialize the nodes

        // Read each node's id, left child, and right child
        for (int i = 0; i < n; i++) {
            id = scanner.nextInt();
            l = scanner.nextInt();
            r = scanner.nextInt();

            if (l != -1) {
                N[id].l = l; // Set left child
                N[l].par = id; // Set parent of left child
            }
            if (r != -1) {
                N[id].r = r; // Set right child
                N[r].par = id; // Set parent of right child
            }
        }

        // Find the root node (the node with no parent)
        for (int i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i; // Store the index of the root node
                break;
            }
        }

        // Print the preorder, inorder, and postorder traversals
        System.out.println("Preorder");
        Preorder(p);
        System.out.println();

        System.out.println("Inorder");
        Inorder(p);
        System.out.println();

        System.out.println("Postorder");
        Postorder(p);
        System.out.println();

        scanner.close();
    }
}

// <END-OF-CODE>
