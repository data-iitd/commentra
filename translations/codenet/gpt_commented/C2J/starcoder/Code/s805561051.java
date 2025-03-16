
import java.util.*;

public class BinaryTree {
    // Define a structure for a binary tree node
    static class BT {
        int parent; // Parent node index
        int right;  // Right child index
        int left;   // Left child index
    }

    // Array to hold the binary tree nodes
    static BT bt[] = new BT[26];
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
        int i, j, num, depth = 0;

        // Read the number of nodes in the binary tree
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Initialize the parent of each node to -1 (indicating no parent)
        for (i = 0; i < n; ++i) bt[i] = new BT();
        for (i = 0; i < n; i++) {
            // Read the current node index
            num = sc.nextInt();
            // Read the left and right child indices
            bt[num].left = sc.nextInt();
            bt[num].right = sc.nextInt();

            // Update the parent index for the left and right children if they exist
            if (bt[num].left!= -1 && bt[num].right!= -1) {
                bt[bt[num].left].parent = num;
                bt[bt[num].right].parent = num;
            } else if (bt[num].left!= -1) {
                bt[bt[num].left].parent = num;
            } else if (bt[num].right!= -1) {
                bt[bt[num].right].parent = num;
            }
        }

        // Find the root of the binary tree (the node with no parent)
        for (i = 0; bt[i].parent!= -1; ++i);

        // Perform and print preorder traversal
        System.out.println("Preorder");
        Preorder(i);
        System.out.println();

        // Perform and print inorder traversal
        System.out.println("Inorder");
        Inorder(i);
        System.out.println();

        // Perform and print postorder traversal
        System.out.println("Postorder");
        Postorder(i);
        System.out.println();
    }
}

