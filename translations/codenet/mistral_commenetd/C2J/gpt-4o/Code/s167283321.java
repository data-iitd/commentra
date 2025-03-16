import java.util.Scanner;

class Node {
    int parent, left, right;

    Node() {
        this.parent = -1;
        this.left = -1;
        this.right = -1;
    }
}

public class BinaryTree {
    static Node[] R = new Node[10000];
    static int n;

    // Recursive function to perform preorder traversal
    static void preorder(int x) {
        // Base case: if x is NIL, return
        if (x == -1)
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
        if (x == -1)
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
        if (x == -1)
            return;

        // Recursively traverse the left subtree
        postorder(R[x].left);

        // Recursively traverse the right subtree
        postorder(R[x].right);

        // Print the current node x
        System.out.print(" " + x);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int root = -1;

        // Read the number of nodes n
        n = scanner.nextInt();

        // Initialize all nodes
        for (int i = 0; i < n; i++) {
            R[i] = new Node();
        }

        // Read the edges and build the tree
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            R[a].left = b;
            R[a].right = c;
            if (b != -1)
                R[b].parent = a; // Set the parent of left child
            if (c != -1)
                R[c].parent = a; // Set the parent of right child
        }

        // Find the root node by searching for the node with no parent
        for (int i = 0; i < n; i++) {
            if (R[i].parent == -1) {
                root = i;
                break;
            }
        }

        // Perform preorder traversal and print the result
        System.out.println("Preorder");
        preorder(root);
        System.out.println();

        // Perform inorder traversal and print the result
        System.out.println("Inorder");
        inorder(root);
        System.out.println();

        // Perform postorder traversal and print the result
        System.out.println("Postorder");
        postorder(root);
        System.out.println();

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
