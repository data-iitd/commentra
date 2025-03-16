import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

class BinaryTree {
    // Node class representing each node in the binary tree
    static class Node {
        int data; // Value of the node
        Node left, right; // Pointers to left and right children

        // Constructor to initialize a node with data
        Node(int data) {
            this.data = data;
            left = right = null; // Initialize children as null
        }
    }

    Node root; // Root of the binary tree

    // Method to create a binary tree from user input
    public void createTree() {
        Scanner sc = new Scanner(System.in);
        root = new Node(sc.nextInt()); // Create root node
        createTreeRecursive(root, sc); // Recursively create the tree
    }

    // Recursive helper method to create the tree
    private void createTreeRecursive(Node node, Scanner sc) {
        if (node == null) return; // Base case: if node is null, return

        // Read left child data and create left subtree
        int leftData = sc.nextInt();
        if (leftData != -1) { // -1 indicates no child
            node.left = new Node(leftData);
            createTreeRecursive(node.left, sc); // Recursive call for left child
        }

        // Read right child data and create right subtree
        int rightData = sc.nextInt();
        if (rightData != -1) { // -1 indicates no child
            node.right = new Node(rightData);
            createTreeRecursive(node.right, sc); // Recursive call for right child
        }
    }
}

public class Main {
    // Method to check if the binary tree is balanced using recursion
    public static boolean isBalancedRecursive(BinaryTree.Node root) {
        if (root == null) return true; // An empty tree is balanced
        boolean[] isBalanced = new boolean[1]; // Array to hold balanced status
        isBalanced[0] = true; // Initialize as balanced
        isBalancedRecursiveHelper(root, isBalanced); // Start recursive check
        return isBalanced[0]; // Return the balanced status
    }

    // Helper method to calculate height and check balance recursively
    private static int isBalancedRecursiveHelper(BinaryTree.Node node, boolean[] isBalanced) {
        if (node == null || !isBalanced[0]) return 0; // Base case

        // Recursively get heights of left and right subtrees
        int leftHeight = isBalancedRecursiveHelper(node.left, isBalanced);
        int rightHeight = isBalancedRecursiveHelper(node.right, isBalanced);

        // Check if current node is balanced
        if (Math.abs(leftHeight - rightHeight) > 1) isBalanced[0] = false;

        // Return height of the current node
        return Math.max(leftHeight, rightHeight) + 1;
    }

    // Method to check if the binary tree is balanced using iteration
    public static boolean isBalancedIterative(BinaryTree.Node root) {
        if (root == null) return true; // An empty tree is balanced

        boolean isBalanced = true; // Initialize as balanced
        Stack<BinaryTree.Node> stack = new Stack<>(); // Stack for traversal
        HashMap<BinaryTree.Node, Integer> subtreeHeights = new HashMap<>(); // Map to store heights
        BinaryTree.Node lastVisited = null; // Track the last visited node
        BinaryTree.Node node = root; // Start from the root

        // Iterative traversal using stack
        while (!stack.isEmpty() || node != null) {
            if (node != null) {
                stack.push(node); // Push current node to stack
                node = node.left; // Move to left child
            } else {
                node = stack.peek(); // Peek the top node in the stack
                // Check if we can process the current node
                if (node.right == null || node.right == lastVisited) {
                    // Get heights of left and right subtrees
                    int leftHeight = subtreeHeights.getOrDefault(node.left, 0);
                    int rightHeight = subtreeHeights.getOrDefault(node.right, 0);
                    // Check if current node is balanced
                    if (Math.abs(leftHeight - rightHeight) > 1) isBalanced = false;

                    // Store the height of the current node
                    subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1);
                    lastVisited = node; // Update last visited node
                    stack.pop(); // Remove current node from stack
                    node = null; // Set node to null to process next node
                } else {
                    node = node.right; // Move to right child
                }
            }
        }
        return isBalanced; // Return the balanced status
    }

    // Main method to execute the program
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(); // Create a new binary tree
        tree.createTree(); // Create the tree from user input
        // Check and print if the tree is balanced using recursive method
        System.out.println("Is tree balanced (recursive): " + isBalancedRecursive(tree.root));
        // Check and print if the tree is balanced using iterative method
        System.out.println("Is tree balanced (iterative): " + isBalancedIterative(tree.root));
    }
}
