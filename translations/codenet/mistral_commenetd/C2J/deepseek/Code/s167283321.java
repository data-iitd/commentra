public class Main {
    static final int NIL = -1;

    // Define a class for a node in the binary tree
    static class Node {
        int parent, left, right;

        Node(int parent, int left, int right) {
            this.parent = parent;
            this.left = left;
            this.right = right;
        }
    }

    // Initialize an array of nodes R with size 10000
    static Node[] R = new Node[10000];

    // Set the number of nodes n
    static int n;

    // Recursive function to perform preorder traversal
    static void preorder(int x) {
        // Base case: if x is NIL, return
        if (x == NIL)
            return;

        // Print the current node x
        System.out.print(" " + x);

        // Recursively traverse the left subtree
        preorder(R[x].left);

        // Recursively traverse the right subtree
        preorder(R[x].right);
    }

    // Recursive function to perform inorder traversal
    static void inorder(int x) {
        // Base case: if x is NIL, return
        if (x == NIL)
            return;

        // Recursively traverse the left subtree
        inorder(R[x].left);

        // Print the current node x
        System.out.print(" " + x);

        // Recursively traverse the right subtree
        inorder(R[x].right);
    }

    // Recursive function to perform postorder traversal
    static void postorder(int x) {
        // Base case: if x is NIL, return
        if (x == NIL)
            return;

        // Recursively traverse the left subtree
        postorder(R[x].left);

        // Recursively traverse the right subtree
        postorder(R[x].right);

        // Print the current node x
        System.out.print(" " + x);
    }

    // Main function to read input and call traversal functions
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int i, a, b, c, root;

        // Read the number of nodes n
        n = scanner.nextInt();

        // Initialize all nodes as NIL
        for (i = 0; i < n; i++)
            R[i] = new Node(NIL, NIL, NIL);

        // Read the edges and build the tree
        for (i = 0; i < n; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            R[a] = new Node(NIL, b, c);
            if (b != NIL)
                R[b].parent = a; // Set the parent of left child
            if (c != NIL)
                R[c].parent = a; // Set the parent of right child
        }

        // Find the root node by searching for the node with no parent
        for (i = 0; i < n; i++) {
            if (R[i].parent == NIL) {
                root = i;
                break;
            }
        }

        // Perform preorder traversal and print the result
        System.out.print("Preorder\n");
        preorder(root);
        System.out.println();

        // Perform inorder traversal and print the result
        System.out.print("Inorder\n");
        inorder(root);
        System.out.println();

        // Perform postorder traversal and print the result
        System.out.print("Postorder\n");
        postorder(root);
        System.out.println();

        // Return 0 to indicate successful execution
    }
}
