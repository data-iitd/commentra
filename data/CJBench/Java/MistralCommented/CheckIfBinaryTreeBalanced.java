
import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

class BinaryTree {
    static class Node {
        int data;
        Node left, right;
        
        // Constructor for a new Node with given data
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }
    
    Node root;
    
    // Method to create a Binary Tree from user input
    public void createTree() {
        Scanner sc = new Scanner(System.in);
        root = new Node(sc.nextInt()); // Create root node with user input
        createTreeRecursive(root, sc); // Recursively create left and right subtrees
    }
    
    // Recursive method to create left and right subtrees for a given node
    private void createTreeRecursive(Node node, Scanner sc) {
        if (node == null) return; // Base case: if node is null, return
        
        int leftData = sc.nextInt(); // Read left child data from user input
        
        // If left child exists, create a new Node and recursively create its left and right subtrees
        if (leftData != -1) {
            node.left = new Node(leftData);
            createTreeRecursive(node.left, sc);
        }
        
        int rightData = sc.nextInt(); // Read right child data from user input
        
        // If right child exists, create a new Node and recursively create its left and right subtrees
        if (rightData != -1) {
            node.right = new Node(rightData);
            createTreeRecursive(node.right, sc);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(); // Create a new instance of BinaryTree class
        
        // Call the createTree method to build the tree from user input
        tree.createTree();
        
        // Call two methods to check if the tree is balanced: recursively and iteratively
        System.out.println("Is tree balanced (recursive): " + isBalancedRecursive(tree.root));
        System.out.println("Is tree balanced (iterative): " + isBalancedIterative(tree.root));
    }
    
    // Recursive method to check if a given BinaryTree node is balanced
    public static boolean isBalancedRecursive(BinaryTree.Node root) {
        boolean isBalanced = true; // Initialize a flag to indicate if the tree is balanced
        
        // Recursive helper method to compute the heights of left and right subtrees and check balance
        private static boolean isBalancedRecursiveHelper(BinaryTree.Node node, boolean[] isBalanced) {
            if (node == null) return true; // Base case: if node is null, return true
            
            boolean[] localIsBalanced = new boolean[1]; // Create a local copy of the isBalanced flag
            localIsBalanced[0] = true;
            
            // Recursively check the balance of left and right subtrees and update the local flag accordingly
            int leftHeight = isBalancedRecursiveHelper(node.left, localIsBalanced);
            int rightHeight = isBalancedRecursiveHelper(node.right, localIsBalanced);
            
            // If the difference between left and right heights is more than 1, the tree is unbalanced
            if (Math.abs(leftHeight - rightHeight) > 1) {
                isBalanced = false; // Update the global flag
                localIsBalanced[0] = false; // Update the local flag as well
            }
            
            // Return the larger height between left and right subtrees
            return Math.max(leftHeight, rightHeight) + 1;
        }
        
        // Call the recursive helper method to check the balance of the root node and store the result in isBalanced flag
        isBalancedRecursiveHelper(root, isBalanced);
        
        // Return the final result
        return isBalanced;
    }
    
    // Iterative method to check if a given BinaryTree node is balanced
    public static boolean isBalancedIterative(BinaryTree.Node root) {
        boolean isBalanced = true; // Initialize a flag to indicate if the tree is balanced
        
        // Use a Stack to store nodes and a HashMap to store heights of subtrees
        Stack<BinaryTree.Node> stack = new Stack<>();
        HashMap<BinaryTree.Node, Integer> subtreeHeights = new HashMap<>();
        
        // Initialize two pointers: current node and previous node
        BinaryTree.Node node = root, lastVisited = null;
        
        // Use a while loop to traverse the tree and check balance at each node
        while (!stack.isEmpty() || node != null) {
            if (node != null) {
                // Push the current node into the stack and update the previous node
                stack.push(node);
                node = node.left;
                
                // If the left child is null or the same as the previous node, check balance and update the flag and heights in HashMap
                if (node == null || node == lastVisited) {
                    int leftHeight = subtreeHeights.getOrDefault(node.left, 0);
                    int rightHeight = subtreeHeights.getOrDefault(node.right, 0);
                    
                    if (Math.abs(leftHeight - rightHeight) > 1) {
                        isBalanced = false;
                    }
                    
                    subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1);
                    lastVisited = node;
                    
                    node = null;
                } else {
                    // Move to the right child
                    node = node.right;
                }
            }
        }
        
        // Return the final result
        return isBalanced;
    }
}

