import java.util.HashMap; // Importing HashMap for managing nodes
import java.util.Map; // Importing Map for generic map operations
import java.util.Scanner; // Importing Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object for input
        int n = sc.nextInt(); // Reading the number of nodes
        Map<Integer, NRKTree> nodeMap = new HashMap<>(); // Creating a HashMap to store nodes by their values
        NRKTree root = null; // Initializing the root of the tree

        // Reading each node's value, left child, and right child, and constructing the tree
        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();
            nodeMap.putIfAbsent(value, new NRKTree(value)); // Adding the node to the map if it doesn't exist
            NRKTree current = nodeMap.get(value); // Getting the current node
            if (root == null) {
                root = current; // Setting the root if it's the first node
            }
            if (left != -1) {
                nodeMap.putIfAbsent(left, new NRKTree(left)); // Adding left child if it exists
                current.left = nodeMap.get(left); // Linking the left child
            }
            if (right != -1) {
                nodeMap.putIfAbsent(right, new NRKTree(right)); // Adding right child if it exists
                current.right = nodeMap.get(right); // Linking the right child
            }
        }

        int inputX0 = sc.nextInt(); // Reading the value to find the nearest right key for
        int toPrint = Main(root, inputX0); // Calling the Main method to find the nearest right key
        if (toPrint == 0) {
            System.out.println("No nearest right key found."); // Printing if no key is found
        } else {
            System.out.println("Nearest Right Key: " + toPrint); // Printing the nearest right key
        }
        sc.close(); // Closing the Scanner
    }

    // Recursive method to find the nearest right key greater than x0
    public static int Main(NRKTree root, int x0) {
        if (root == null) {
            return 0; // Returning 0 if the tree is empty
        } else {
            if (root.data > x0) {
                int temp = Main(root.left, x0); // Recursively searching in the left subtree
                if (temp == 0) {
                    return root.data; // Returning the current node's data if no greater key is found in the left subtree
                }
                return temp; // Returning the found key from the left subtree
            } else {
                return Main(root.right, x0); // Recursively searching in the right subtree
            }
        }
    }
}

class NRKTree {
    public NRKTree left; // Reference to the left child
    public NRKTree right; // Reference to the right child
    public int data; // Data stored in the node

    NRKTree(int x) {
        this.left = null; // Initializing left child as null
        this.right = null; // Initializing right child as null
        this.data = x; // Setting the data value
    }
}
