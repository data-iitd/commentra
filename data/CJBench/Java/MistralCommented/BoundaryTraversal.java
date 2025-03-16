
import java.util.*;
import java.util.HashMap;

public class Main {
    // Define a static inner class Node to represent a tree node
    static class Node {
        int data;
        Node left;
        Node right;
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Define a method to perform boundary traversal of a binary tree
    public static List<Integer> boundaryTraversal(Node root) {
        // Initialize an empty list to store the result
        List<Integer> result = new ArrayList<>();

        // Base case: if the root is null, return an empty list
        if (root == null) {
            return result;
        }

        // If the root is not a leaf node, add its data to the result
        if (!isLeaf(root)) {
            result.add(root.data);
        }

        // Recursively add left boundary nodes to the result
        addLeftBoundary(root, result);

        // Recursively add leaf nodes to the result
        addLeaves(root, result);

        // Recursively add right boundary nodes to the result
        addRightBoundary(root, result);

        // Return the result
        return result;
    }

    // A private helper method to check if a node is a leaf node
    private static boolean isLeaf(Node node) {
        return node.left == null && node.right == null;
    }

    // A private helper method to traverse and add left boundary nodes to the result
    private static void addLeftBoundary(Node node, List<Integer> result) {
        Node cur = node.left;
        // Initialize an empty stack to store nodes for right boundary traversal
        Stack<Integer> temp = new Stack<>();

        // Traverse the left subtree and add non-leaf nodes to the result
        while (cur != null) {
            if (!isLeaf(cur)) {
                result.add(cur.data);
            }
            // Traverse the left subtree further
            cur = (cur.left != null) ? cur.left : cur.right;
        }
    }

    // A private helper method to traverse and add leaf nodes to the result
    private static void addLeaves(Node node, List<Integer> result) {
        // Base case: if the node is null, return
        if (node == null) {
            return;
        }

        // If the node is a leaf node, add its data to the result
        if (isLeaf(node)) {
            result.add(node.data);
        } else {
            // Recursively traverse the left and right subtrees to add their leaf nodes to the result
            addLeaves(node.left, result);
            addLeaves(node.right, result);
        }
    }

    // A private helper method to traverse and add right boundary nodes to the result
    private static void addRightBoundary(Node node, List<Integer> result) {
        Node cur = node.right;
        // Traverse the right subtree using a stack to handle nodes without left children
        while (cur != null) {
            if (!isLeaf(cur)) {
                // Push non-leaf nodes to the stack for later processing
                temp.push(cur.data);
            }
            // Traverse the right subtree further
            cur = (cur.right != null) ? cur.right : cur.left;
        }

        // Pop and add all non-leaf nodes from the stack to the result
        while (!temp.isEmpty()) {
            result.add(temp.pop());
        }
    }

    // Define a method to build a binary tree from input
    public static Node buildTree(Scanner scanner) {
        int n = scanner.nextInt(); // Read the number of nodes in the tree

        // Initialize an empty HashMap to store nodes for faster lookup
        Map<Integer, Node> map = new HashMap<>();

        Node root = null; // Initialize the root to null

        // Read and build each node in the tree
        for (int i = 0; i < n; i++) {
            int parent = scanner.nextInt(); // Read the parent node's data
            String direction = scanner.next(); // Read the direction ("L" or "R")
            int child = scanner.nextInt(); // Read the child node's data

            // Create a new node for the child
            Node childNode = new Node(child);

            // If the parent node is null, set it as the root
            if (root == null) {
                root = parent;
            }

            // Look up the parent node in the map and set the child as its left or right child
            Node parentNode = map.getOrDefault(parent, new Node(parent));
            if (direction.equals("L")) {
                parentNode.left = childNode;
            } else if (direction.equals("R")) {
                parentNode.right = childNode;
            }

            // Add both nodes to the map for faster lookup
            map.put(parent, parentNode);
            map.put(child, childNode);
        }

        // Return the root node
        return root;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner to read input

        Node root = buildTree(scanner); // Build the binary tree from input

        List<Integer> result = boundaryTraversal(root); // Perform boundary traversal and store the result in a list

        System.out.println("Boundary traversal:"); // Print the title of the output
        for (int value : result) { // Iterate through the list and print each value
            System.out.print(value + " ");
        }
        System.out.println(); // Print a newline character after the output

        scanner.close(); // Close the Scanner to free up resources
    }
}