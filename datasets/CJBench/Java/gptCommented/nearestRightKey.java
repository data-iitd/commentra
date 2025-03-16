import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of nodes in the tree
        int n = sc.nextInt();
        
        // Create a map to hold the nodes of the tree
        Map<Integer, NRKTree> nodeMap = new HashMap<>();
        NRKTree root = null; // Initialize the root of the tree
        
        // Loop to read each node's value and its children
        for (int i = 0; i < n; i++) {
            int value = sc.nextInt(); // Read the value of the current node
            int left = sc.nextInt();  // Read the left child value
            int right = sc.nextInt(); // Read the right child value
            
            // If the node does not exist in the map, create and add it
            nodeMap.putIfAbsent(value, new NRKTree(value));
            NRKTree current = nodeMap.get(value); // Get the current node
            
            // Set the root if it is not already set
            if (root == null) {
                root = current; 
            }
            
            // If the left child value is valid, add it to the current node
            if (left != -1) {
                nodeMap.putIfAbsent(left, new NRKTree(left));
                current.left = nodeMap.get(left);
            }
            
            // If the right child value is valid, add it to the current node
            if (right != -1) {
                nodeMap.putIfAbsent(right, new NRKTree(right));
                current.right = nodeMap.get(right);
            }
        }
        
        // Read the value for which we need to find the nearest right key
        int inputX0 = sc.nextInt();
        
        // Call the method to find the nearest right key and store the result
        int toPrint = Main(root, inputX0);
        
        // Print the result based on whether a nearest right key was found
        if (toPrint == 0) {
            System.out.println("No nearest right key found.");
        } else {
            System.out.println("Nearest Right Key: " + toPrint);
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
    
    // Method to find the nearest right key greater than x0 in the tree
    public static int Main(NRKTree root, int x0) {
        // Base case: if the current node is null, return 0
        if (root == null) {
            return 0;
        } else {
            // If the current node's data is greater than x0
            if (root.data > x0) {
                // Recursively search in the left subtree
                int temp = Main(root.left, x0);
                // If no key was found in the left subtree, return the current node's data
                if (temp == 0) {
                    return root.data;
                }
                return temp; // Otherwise, return the found key
            } else {
                // If the current node's data is not greater, search in the right subtree
                return Main(root.right, x0);
            }
        }
    }
}

// Class representing a node in the NRK tree
class NRKTree {
    public NRKTree left; // Left child of the node
    public NRKTree right; // Right child of the node
    public int data; // Value of the node
    
    // Constructor to initialize the node with a value
    NRKTree(int x) {
        this.left = null; // Initialize left child as null
        this.right = null; // Initialize right child as null
        this.data = x; // Set the node's value
    }
}
