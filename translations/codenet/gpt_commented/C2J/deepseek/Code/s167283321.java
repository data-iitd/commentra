public class TreeTraversal {
    static class Node {
        int parent, left, right; // parent, left child, and right child indices
    }

    static Node[] R = new Node[10000];
    static int n; // Number of nodes in the tree

    // Function prototypes for tree traversal
    static void preorder(int);
    static void inorder(int);
    static void postorder(int);

    // Preorder traversal function
    static void preorder(int x) {
        // Base case: if the current node is NIL, return
        if (x == -1)
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
        if (x == -1)
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
        if (x == -1)
            return;
        // Recursively traverse the left subtree
        postorder(R[x].left);
        // Recursively traverse the right subtree
        postorder(R[x].right);
        // Print the current node's value
        System.out.print(" " + x);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int i, a, b, c, root;

        // Read the number of nodes in the tree
        n = scanner.nextInt();
        
        // Initialize all nodes' parents to NIL
        for (i = 0; i < n; i++)
            R[i] = new Node();

        // Read the tree structure from input
        for (i = 0; i < n; i++) {
            // Read the current node and its left and right children
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            R[a].left = b; // Set left child
            R[a].right = c; // Set right child
            // Update the parent of the left child if it is not NIL
            if (b != -1) R[b].parent = a;
            // Update the parent of the right child if it is not NIL
            if (c != -1) R[c].parent = a;
        }

        // Find the root of the tree (the node with no parent)
        for (i = 0; i < n; i++) {
            if (R[i].parent == -1)
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

        scanner.close(); // End of the program
    }
}
