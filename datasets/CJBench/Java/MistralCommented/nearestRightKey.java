
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize Scanner to read input
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes in the tree
        int n = sc.nextInt();

        // Create a HashMap to store nodes in the tree
        Map<Integer, NRKTree> nodeMap = new HashMap<>();

        // Initialize root node to null
        NRKTree root = null;

        // Read each node and create a new node if it doesn't exist in the map
        // Put the node in the map and set its left and right children if they exist
        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();

            // Create a new node if it doesn't exist in the map
            nodeMap.putIfAbsent(value, new NRKTree(value));

            // Get the current node
            NRKTree current = nodeMap.get(value);

            // If root is null, set the current node as the root
            if (root == null) {
                root = current;
            }

            // Set the left child of the current node if it exists
            if (left != -1) {
                nodeMap.putIfAbsent(left, new NRKTree(left));
                current.left = nodeMap.get(left);
            }

            // Set the right child of the current node if it exists
            if (right != -1) {
                nodeMap.putIfAbsent(right, new NRKTree(right));
                current.right = nodeMap.get(right);
            }
        }

        // Read the input value x0
        int inputX0 = sc.nextInt();

        // Call the recursive function to find the nearest right key
        int toPrint = Main(root, inputX0);

        // Print the result
        if (toPrint == 0) {
            System.out.println("No nearest right key found.");
        } else {
            System.out.println("Nearest Right Key: " + toPrint);
        }

        // Close the Scanner
        sc.close();
    }

    // Recursive function to find the nearest right key
    public static int Main(NRKTree root, int x0) {
        // Base case: if root is null, return 0
        if (root == null) {
            return 0;
        }

        // If the current node's data is greater than x0, search in the left subtree
        if (root.data > x0) {
            int temp = Main(root.left, x0);

            // If the left subtree doesn't have the answer, return the current node's data
            if (temp == 0) {
                return root.data;
            }

            // Otherwise, return the answer from the left subtree
            return temp;
        }

        // Otherwise, search in the right subtree
        return Main(root.right, x0);
    }
}

class NRKTree {
    // Initialize left and right children and data
    public NRKTree left;
    public NRKTree right;
    public int data;

    // Constructor to initialize the node with given data
    NRKTree(int x) {
        this.left = null;
        this.right = null;
        this.data = x;
    }
}