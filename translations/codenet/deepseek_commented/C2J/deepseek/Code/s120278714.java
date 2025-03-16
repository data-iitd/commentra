public class TreeTraversal {
    static final int MAX = 25; // Define the maximum number of nodes

    // Define the node structure
    static class Node {
        int l, r, par; // l: left child, r: right child, par: parent

        Node() {
            l = r = par = -1;
        }
    }

    static Node[] N = new Node[MAX]; // Array of nodes

    // Function declarations
    static void init(int n);
    static void Preorder(int p);
    static void Inorder(int p);
    static void Postorder(int p);

    public static void main(String[] args) {
        int n, i, id, l, r;
        int p;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt(); // Read the number of nodes
        init(n); // Initialize the nodes

        // Read each node's id, left child, and right child
        for (i = 0; i < n; i++) {
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
        for (i = 0; i < n; i++) {
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
    }

    // Initialize all nodes
    static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node();
        }
    }

    // Preorder traversal: root, left, right
    static void Preorder(int p) {
        if (p != -1) {
            System.out.print(" " + p); // Print current node
            Preorder(N[p].l); // Recursively traverse left subtree
            Preorder(N[p].r); // Recursively traverse right subtree
        }
    }

    // Inorder traversal: left, root, right
    static void Inorder(int p) {
        if (p != -1) {
            Inorder(N[p].l); // Recursively traverse left subtree
            System.out.print(" " + p); // Print current node
            Inorder(N[p].r); // Recursively traverse right subtree
        }
    }

    // Postorder traversal: left, right, root
    static void Postorder(int p) {
        if (p != -1) {
            Postorder(N[p].l); // Recursively traverse left subtree
            Postorder(N[p].r); // Recursively traverse right subtree
            System.out.print(" " + p); // Print current node
        }
    }
}
