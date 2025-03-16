import java.util.*;
import java.util.HashMap;
public class Main {
    // Represents a node in a binary tree
    static class Node {
        int data; // Data stored in the node
        Node left; // Reference to the left child
        Node right; // Reference to the right child
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    
    // Performs a boundary traversal of the binary tree
    public static List<Integer> boundaryTraversal(Node root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result; // Return an empty list if the root is null
        }
        if (!isLeaf(root)) {
            result.add(root.data); // Add the root data if it's not a leaf
        }
        addLeftBoundary(root, result); // Add the left boundary
        addLeaves(root, result); // Add the leaf nodes
        addRightBoundary(root, result); // Add the right boundary in reverse order
        return result;
    }
    
    // Adds the left boundary of the tree to the result list, excluding leaf nodes
    private static void addLeftBoundary(Node node, List<Integer> result) {
        Node cur = node.left;
        while (cur != null) {
            if (!isLeaf(cur)) {
                result.add(cur.data); // Add the node data if it's not a leaf
            }
            cur = (cur.left != null) ? cur.left : cur.right; // Move to the next node in the left or right subtree
        }
    }
    
    // Adds the leaf nodes of the tree to the result list
    private static void addLeaves(Node node, List<Integer> result) {
        if (node == null) {
            return; // Return if the node is null
        }
        if (isLeaf(node)) {
            result.add(node.data); // Add the node data if it's a leaf
        } else {
            addLeaves(node.left, result); // Recursively add left subtree leaves
            addLeaves(node.right, result); // Recursively add right subtree leaves
        }
    }
    
    // Adds the right boundary of the tree to the result list, excluding leaf nodes, in reverse order
    private static void addRightBoundary(Node node, List<Integer> result) {
        Node cur = node.right;
        Stack<Integer> temp = new Stack<>();
        while (cur != null) {
            if (!isLeaf(cur)) {
                temp.push(cur.data); // Add the node data to a stack if it's not a leaf
            }
            cur = (cur.right != null) ? cur.right : cur.left; // Move to the next node in the right or left subtree
        }
        while (!temp.isEmpty()) {
            result.add(temp.pop()); // Pop nodes from the stack and add to the result list
        }
    }
    
    // Checks if a node is a leaf node
    private static boolean isLeaf(Node node) {
        return node.left == null && node.right == null; // Return true if both left and right children are null
    }
    
    // Builds a binary tree from user input
    public static Node buildTree(Scanner scanner) {
        int n = scanner.nextInt();
        Map<Integer, Node> map = new HashMap<>();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int parent = scanner.nextInt();
            String direction = scanner.next();
            int child = scanner.nextInt();
            Node parentNode = map.getOrDefault(parent, new Node(parent));
            Node childNode = new Node(child);
            if (direction.equals("L")) {
                parentNode.left = childNode; // Set the left child
            } else if (direction.equals("R")) {
                parentNode.right = childNode; // Set the right child
            }
            map.put(parent, parentNode); // Update the map with the parent node
            map.put(child, childNode); // Update the map with the child node
            if (root == null) {
                root = parentNode; // Set the root if it's the first node
            }
        }
        return root;
    }
    
    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node root = buildTree(scanner);
        System.out.println("Boundary traversal:");
        List<Integer> result = boundaryTraversal(root);
        for (int value : result) {
            System.out.print(value + " "); // Print the boundary nodes
        }
        System.out.println();
        scanner.close();
    }
}
