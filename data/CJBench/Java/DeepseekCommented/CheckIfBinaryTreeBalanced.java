import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

class BinaryTree {
    static class Node {
        int data;
        Node left, right;

        // Constructor to initialize a node with given data
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    // Root of the binary tree
    Node root;

    // Method to create the binary tree by taking input from the user
    public void createTree() {
        Scanner sc = new Scanner(System.in);
        root = new Node(sc.nextInt()); // Create the root node
        createTreeRecursive(root, sc); // Recursively create the tree
    }

    // Recursive method to create the tree by taking input for each node
    private void createTreeRecursive(Node node, Scanner sc) {
        if (node == null) return; // Base case for recursion
        int leftData = sc.nextInt();
        if (leftData != -1) {
            node.left = new Node(leftData); // Create left child
            createTreeRecursive(node.left, sc); // Recursively create left subtree
        }
        int rightData = sc.nextInt();
        if (rightData != -1) {
            node.right = new Node(rightData); // Create right child
            createTreeRecursive(node.right, sc); // Recursively create right subtree
        }
    }
}

public class Main {
    // Method to check if the binary tree is balanced using recursion
    public static boolean isBalancedRecursive(BinaryTree.Node root) {
        if (root == null) return true; // An empty tree is balanced
        boolean[] isBalanced = new boolean[1]; // Use an array to pass boolean by reference
        isBalanced[0] = true; // Initialize the balance status
        isBalancedRecursiveHelper(root, isBalanced); // Call the helper method
        return isBalanced[0]; // Return the balance status
    }

    // Helper method to recursively check the balance of the tree
    private static int isBalancedRecursiveHelper(BinaryTree.Node node, boolean[] isBalanced) {
        if (node == null || !isBalanced[0]) return 0; // Base case for recursion
        int leftHeight = isBalancedRecursiveHelper(node.left, isBalanced); // Get left subtree height
        int rightHeight = isBalancedRecursiveHelper(node.right, isBalanced); // Get right subtree height
        if (Math.abs(leftHeight - rightHeight) > 1) isBalanced[0] = false; // Check balance condition
        return Math.max(leftHeight, rightHeight) + 1; // Return the height of the current subtree
    }

    // Method to check if the binary tree is balanced using iteration
    public static boolean isBalancedIterative(BinaryTree.Node root) {
        if (root == null) return true; // An empty tree is balanced
        boolean isBalanced = true; // Initialize the balance status
        Stack<BinaryTree.Node> stack = new Stack<>(); // Use a stack to traverse the tree
        HashMap<BinaryTree.Node, Integer> subtreeHeights = new HashMap<>(); // Map to store subtree heights
        BinaryTree.Node lastVisited = null; // Keep track of the last visited node
        BinaryTree.Node node = root; // Start from the root
        while (!stack.isEmpty() || node != null) {
            if (node != null) {
                stack.push(node); // Push the current node onto the stack
                node = node.left; // Move to the left child
            } else {
                node = stack.peek(); // Get the top node from the stack
                if (node.right == null || node.right == lastVisited) {
                    int leftHeight = subtreeHeights.getOrDefault(node.left, 0); // Get left subtree height
                    int rightHeight = subtreeHeights.getOrDefault(node.right, 0); // Get right subtree height
                    if (Math.abs(leftHeight - rightHeight) > 1) isBalanced = false; // Check balance condition
                    subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1); // Update the subtree height
                    lastVisited = node; // Update the last visited node
                    stack.pop(); // Pop the current node from the stack
                    node = null; // Set the current node to null to move to the right subtree
                } else {
                    node = node.right; // Move to the right child
                }
            }
        }
        return isBalanced; // Return the balance status
    }

    // Main method to test the functionality of the binary tree
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.createTree(); // Create the binary tree
        System.out.println("Is tree balanced (recursive): " + isBalancedRecursive(tree.root)); // Check balance recursively
        System.out.println("Is tree balanced (iterative): " + isBalancedIterative(tree.root)); // Check balance iteratively
    }
}
