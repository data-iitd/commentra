import java.util.*;

// Define a class for a binary tree node
class BT {
    int parent; // Parent node index
    int right; // Index of right child
    int left; // Index of left child
}

public class Main {
    static BT[] bt = new BT[26]; // Initialize an array of size 26 to store binary tree nodes
    static int n; // Number of nodes in the binary tree

    // Recursive function to print tree in preorder traversal
    static void Preorder(int a) {
        // Base case: if current node index is -1, return
        if (a == -1) return;

        // Print the current node value
        System.out.print(" " + a);

        // Recursively call for left and right subtrees
        Preorder(bt[a].left);
        Preorder(bt[a].right);
    }

    // Recursive function to print tree in inorder traversal
    static void Inorder(int a) {
        // Base case: if current node index is -1, return
        if (a == -1) return;

        // Recursively call for left subtree
        Inorder(bt[a].left);

        // Print the current node value
        System.out.print(" " + a);

        // Recursively call for right subtree
        Inorder(bt[a].right);
    }

    // Recursive function to print tree in postorder traversal
    static void Postorder(int a) {
        // Base case: if current node index is -1, return
        if (a == -1) return;

        // Recursively call for left and right subtrees
        Postorder(bt[a].left);
        Postorder(bt[a].right);

        // Print the current node value
        System.out.print(" " + a);
    }

    // Main function to read input and print tree traversals
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, num; // Initialize variables

        // Read number of nodes in the binary tree
        n = scanner.nextInt();

        // Initialize all nodes as root
        for (i = 0; i < n; ++i) {
            bt[i] = new BT();
            bt[i].parent = -1;
        }

        // Read node values and their left and right children
        for (i = 0; i < n; i++) {
            num = scanner.nextInt(); // Read node value

            // Initialize left and right children as -1
            bt[num].left = -1;
            bt[num].right = -1;

            // Read left and right child indices if they exist
            String children = scanner.nextLine();
            String[] parts = children.split(" ");
            if (parts.length > 1) {
                bt[num].left = Integer.parseInt(parts[0]);
                bt[num].right = Integer.parseInt(parts[1]);

                // Set parent of left and right children to current node
                if (bt[num].left != -1 && bt[num].right != -1) {
                    bt[bt[num].left].parent = num;
                    bt[bt[num].right].parent = num;
                }
                // Set parent of left child if it exists
                else if (bt[num].left != -1) bt[bt[num].left].parent = num;
                // Set parent of right child if it exists
                else if (bt[num].right != -1) bt[bt[num].right].parent = num;
            }
        }

        // Find the index of the last node (root) in the tree
        for (i = 0; bt[i].parent != -1; ++i) ;

        // Print tree traversals
        System.out.println("Preorder");
        Preorder(i);
        System.out.println();

        System.out.println("Inorder");
        Inorder(i);
        System.out.println();

        System.out.println("Postorder");
        Postorder(i);
        System.out.println();
    }
}
