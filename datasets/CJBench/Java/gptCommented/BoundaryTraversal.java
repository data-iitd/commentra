import java.util.*;
import java.util.HashMap;

public class Main {
    // Definition of the Node class representing each node in the binary tree
    static class Node {
        int data; // Value of the node
        Node left; // Left child of the node
        Node right; // Right child of the node
        
        // Constructor to initialize a node with data
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Method to perform boundary traversal of the binary tree
    public static List<Integer> boundaryTraversal(Node root) {
        List<Integer> result = new ArrayList<>(); // List to store the boundary traversal result
        
        // If the tree is empty, return an empty result
        if (root == null) {
            return result;
        }
        
        // Add the root node if it is not a leaf
        if (!isLeaf(root)) {
            result.add(root.data);
        }
        
        // Add the left boundary nodes (excluding leaf nodes)
        addLeftBoundary(root, result);
        
        // Add all leaf nodes
        addLeaves(root, result);
        
        // Add the right boundary nodes (excluding leaf nodes)
        addRightBoundary(root, result);
        
        return result; // Return the final result of boundary traversal
    }

    // Helper method to add left boundary nodes to the result list
    private static void addLeftBoundary(Node node, List<Integer> result) {
        Node cur = node.left; // Start from the left child
        while (cur != null) {
            // Add the node data if it is not a leaf
            if (!isLeaf(cur)) {
                result.add(cur.data);
            }
            // Move to the next boundary node (prefer left child, then right child)
            cur = (cur.left != null) ? cur.left : cur.right;
        }
    }

    // Helper method to add leaf nodes to the result list
    private static void addLeaves(Node node, List<Integer> result) {
        // Base case: if the node is null, return
        if (node == null) {
            return;
        }
        
        // If the node is a leaf, add its data to the result
        if (isLeaf(node)) {
            result.add(node.data);
        } else {
            // Recursively add leaves from the left and right subtrees
            addLeaves(node.left, result);
            addLeaves(node.right, result);
        }
    }

    // Helper method to add right boundary nodes to the result list
    private static void addRightBoundary(Node node, List<Integer> result) {
        Node cur = node.right; // Start from the right child
        Stack<Integer> temp = new Stack<>(); // Temporary stack to reverse the order
        
        while (cur != null) {
            // Add the node data if it is not a leaf
            if (!isLeaf(cur)) {
                temp.push(cur.data);
            }
            // Move to the next boundary node (prefer right child, then left child)
            cur = (cur.right != null) ? cur.right : cur.left;
        }
        
        // Pop from the stack to add the right boundary in reverse order
        while (!temp.isEmpty()) {
            result.add(temp.pop());
        }
    }

    // Helper method to check if a node is a leaf node
    private static boolean isLeaf(Node node) {
        return node.left == null && node.right == null; // A node is a leaf if it has no children
    }

    // Method to build the binary tree from user input
    public static Node buildTree(Scanner scanner) {
        int n = scanner.nextInt(); // Read the number of edges
        Map<Integer, Node> map = new HashMap<>(); // Map to store nodes by their values
        Node root = null; // Initialize root node
        
        // Loop to read edges and construct the tree
        for (int i = 0; i < n; i++) {
            int parent = scanner.nextInt(); // Read parent node value
            String direction = scanner.next(); // Read direction (L or R)
            int child = scanner.nextInt(); // Read child node value
            
            // Get or create the parent node
            Node parentNode = map.getOrDefault(parent, new Node(parent));
            Node childNode = new Node(child); // Create the child node
            
            // Link the child to the parent based on the direction
            if (direction.equals("L")) {
                parentNode.left = childNode; // Set left child
            } else if (direction.equals("R")) {
                parentNode.right = childNode; // Set right child
            }
            
            // Update the map with the parent and child nodes
            map.put(parent, parentNode);
            map.put(child, childNode);
            
            // Set the root node if it is not already set
            if (root == null) {
                root = parentNode;
            }
        }
        return root; // Return the constructed tree's root
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        Node root = buildTree(scanner); // Build the tree from input
        System.out.println("Boundary traversal:"); // Print message for boundary traversal
        List<Integer> result = boundaryTraversal(root); // Perform boundary traversal
        
        // Print the result of boundary traversal
        for (int value : result) {
            System.out.print(value + " ");
        }
        System.out.println(); // Print a new line
        scanner.close(); // Close the scanner
    }
}
