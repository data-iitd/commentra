import java.util.Scanner;

class Node {
    int l; // left child
    int r; // right child
    int par; // parent

    Node() {
        this.l = -1;
        this.r = -1;
        this.par = -1;
    }
}

public class TreeTraversal {
    static Node[] N;

    // Initialize the tree with n nodes
    static void init(int n) {
        N = new Node[n];
        for (int i = 0; i < n; i++) {
            N[i] = new Node();
        }
    }

    // Preorder traversal
    static void Preorder(int node) {
        if (node == -1) return;
        System.out.print(node + " ");
        Preorder(N[node].l);
        Preorder(N[node].r);
    }

    // Inorder traversal
    static void Inorder(int node) {
        if (node == -1) return;
        Inorder(N[node].l);
        System.out.print(node + " ");
        Inorder(N[node].r);
    }

    // Postorder traversal
    static void Postorder(int node) {
        if (node == -1) return;
        Postorder(N[node].l);
        Postorder(N[node].r);
        System.out.print(node + " ");
    }

    public static void main(String[] args) {
        // Declare and initialize variables
        int n, i, id, l, r;
        int p = -1;

        // Read the number of nodes in the tree
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Initialize the tree
        init(n);

        // Read the input and build the tree
        for (i = 0; i < n; i++) {
            // Read the id, left child, and right child of the current node
            id = scanner.nextInt();
            l = scanner.nextInt();
            r = scanner.nextInt();

            // If the left child is not -1, assign it to the left child of the current node
            if (l != -1) {
                N[id].l = l;
                N[l].par = id;
            }

            // If the right child is not -1, assign it to the right child of the current node
            if (r != -1) {
                N[id].r = r;
                N[r].par = id;
            }
        }

        // Find the root node
        for (i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i;
                break;
            }
        }

        // Print the tree traversals in Preorder, Inorder, and Postorder
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

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.
