import java.util.Scanner;

class BT {
    int parent;  // To store the parent node index
    int right;   // To store the index of the right child
    int left;    // To store the index of the left child

    BT() {
        this.parent = -1; // Initialize parent to -1
        this.right = -1;  // Initialize right child to -1
        this.left = -1;   // Initialize left child to -1
    }
}

public class BinaryTree {
    static BT[] bt = new BT[26]; // Array to hold the nodes of the binary tree
    static int n;                 // Number of nodes in the binary tree

    // Function to perform preorder traversal of the binary tree
    static void Preorder(int a) {
        if (a == -1) return; // Base case: if the node is -1, return

        System.out.print(" " + a); // Print the current node
        Preorder(bt[a].left);       // Recursively call Preorder on the left child
        Preorder(bt[a].right);      // Recursively call Preorder on the right child
    }

    // Function to perform inorder traversal of the binary tree
    static void Inorder(int a) {
        if (a == -1) return; // Base case: if the node is -1, return

        Inorder(bt[a].left);  // Recursively call Inorder on the left child
        System.out.print(" " + a); // Print the current node
        Inorder(bt[a].right); // Recursively call Inorder on the right child
    }

    // Function to perform postorder traversal of the binary tree
    static void Postorder(int a) {
        if (a == -1) return; // Base case: if the node is -1, return

        Postorder(bt[a].left); // Recursively call Postorder on the left child
        Postorder(bt[a].right); // Recursively call Postorder on the right child
        System.out.print(" " + a); // Print the current node
    }

    // Main function to read the number of nodes, initialize the tree, and print traversals
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the number of nodes

        // Initialize the binary tree nodes
        for (int i = 0; i < n; ++i) {
            bt[i] = new BT();
        }

        // Read the left and right children for each node
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            bt[num].left = scanner.nextInt();
            bt[num].right = scanner.nextInt();

            // Update the parent pointers of the left and right children
            if (bt[num].left != -1) {
                bt[bt[num].left].parent = num;
            }
            if (bt[num].right != -1) {
                bt[bt[num].right].parent = num;
            }
        }

        // Find the root node (the node with no parent)
        int root = 0;
        while (bt[root].parent != -1) {
            root++;
        }

        // Print the preorder, inorder, and postorder traversals of the binary tree
        System.out.println("Preorder");
        Preorder(root);
        System.out.println();

        System.out.println("Inorder");
        Inorder(root);
        System.out.println();

        System.out.println("Postorder");
        Postorder(root);
        System.out.println();

        scanner.close();
    }
}

// <END-OF-CODE>
