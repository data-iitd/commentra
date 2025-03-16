import java.util.Scanner;

// Define a class for a binary tree node
class BT {
    int parent; // Parent node index
    int right;  // Right child index
    int left;   // Left child index

    // Constructor to initialize the node
    public BT() {
        this.parent = -1; // Initialize parent to -1 (indicating no parent)
        this.left = -1;   // Initialize left child to -1 (indicating no child)
        this.right = -1;  // Initialize right child to -1 (indicating no child)
    }
}

public class BinaryTree {
    static BT[] bt = new BT[26]; // Array to hold the binary tree nodes
    static int n; // Number of nodes in the binary tree

    // Function to perform preorder traversal of the binary tree
    static void Preorder(int a) {
        // Base case: if the node index is -1, return
        if (a == -1) return;

        // Print the current node index
        System.out.print(" " + a);
        // Recursively traverse the left subtree
        Preorder(bt[a].left);
        // Recursively traverse the right subtree
        Preorder(bt[a].right);
    }

    // Function to perform inorder traversal of the binary tree
    static void Inorder(int a) {
        // Base case: if the node index is -1, return
        if (a == -1) return;

        // Recursively traverse the left subtree
        Inorder(bt[a].left);
        // Print the current node index
        System.out.print(" " + a);
        // Recursively traverse the right subtree
        Inorder(bt[a].right);
    }

    // Function to perform postorder traversal of the binary tree
    static void Postorder(int a) {
        // Base case: if the node index is -1, return
        if (a == -1) return;

        // Recursively traverse the left subtree
        Postorder(bt[a].left);
        // Recursively traverse the right subtree
        Postorder(bt[a].right);
        // Print the current node index
        System.out.print(" " + a);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes in the binary tree
        n = scanner.nextInt();

        // Initialize the binary tree nodes
        for (int i = 0; i < n; ++i) {
            bt[i] = new BT();
        }

        // Read the tree structure from input
        for (int i = 0; i < n; i++) {
            // Read the current node index
            int num = scanner.nextInt();
            // Read the left and right child indices
            bt[num].left = scanner.nextInt();
            bt[num].right = scanner.nextInt();

            // Update the parent index for the left and right children if they exist
            if (bt[num].left != -1) {
                bt[bt[num].left].parent = num;
            }
            if (bt[num].right != -1) {
                bt[bt[num].right].parent = num;
            }
        }

        // Find the root of the binary tree (the node with no parent)
        int root = 0;
        while (bt[root].parent != -1) {
            root++;
        }

        // Perform and print preorder traversal
        System.out.println("Preorder");
        Preorder(root);
        System.out.println();

        // Perform and print inorder traversal
        System.out.println("Inorder");
        Inorder(root);
        System.out.println();

        // Perform and print postorder traversal
        System.out.println("Postorder");
        Postorder(root);
        System.out.println();

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
