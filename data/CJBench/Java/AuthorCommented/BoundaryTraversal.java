
import java.util.*;
import java.util.HashMap;
/**
 * BoundaryTraversal
 * <p>
 * Start with the Root:
 * Add the root node to the boundary list.
 * Traverse the Left Boundary (Excluding Leaf Nodes):
 * Move down the left side of the tree, adding each non-leaf node to the boundary list.
 * If a node has a left child, go left; otherwise, go right.
 * Visit All Leaf Nodes:
 * Traverse the tree and add all leaf nodes to the boundary list, from left to right.
 * Traverse the Right Boundary (Excluding Leaf Nodes) in Reverse Order:
 * Move up the right side of the tree, adding each non-leaf node to a temporary list.
 * If a node has a right child, go right; otherwise, go left.
 * Reverse the temporary list and add it to the boundary list.
 * Combine and Output:
 * The final boundary list contains the root, left boundary, leaf nodes, and reversed right boundary in that order.
 */
public class BoundaryTraversal {

    // Represents a Binary Tree Node
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

    // Main function for boundary traversal
    public static List<Integer> boundaryTraversal(Node root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        // Add root node if it's not a leaf node
        if (!isLeaf(root)) {
            result.add(root.data);
        }

        // Add left boundary
        addLeftBoundary(root, result);

        // Add leaf nodes
        addLeaves(root, result);

        // Add right boundary
        addRightBoundary(root, result);

        return result;
    }

    // Adds the left boundary, including nodes that have no left child but have a right child
    private static void addLeftBoundary(Node node, List<Integer> result) {
        Node cur = node.left;
        while (cur != null) {
            if (!isLeaf(cur)) {
                result.add(cur.data);
            }
            cur = (cur.left != null) ? cur.left : cur.right;
        }
    }

    // Adds leaf nodes (nodes without children)
    private static void addLeaves(Node node, List<Integer> result) {
        if (node == null) {
            return;
        }
        if (isLeaf(node)) {
            result.add(node.data);
        } else {
            addLeaves(node.left, result);
            addLeaves(node.right, result);
        }
    }

    // Adds the right boundary, excluding leaf nodes
    private static void addRightBoundary(Node node, List<Integer> result) {
        Node cur = node.right;
        Stack<Integer> temp = new Stack<>();
        while (cur != null) {
            if (!isLeaf(cur)) {
                temp.push(cur.data);
            }
            cur = (cur.right != null) ? cur.right : cur.left;
        }
        while (!temp.isEmpty()) {
            result.add(temp.pop());
        }
    }

    // Checks if a node is a leaf node
    private static boolean isLeaf(Node node) {
        return node.left == null && node.right == null;
    }

    // Function to build a binary tree from input
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
                parentNode.left = childNode;
            } else if (direction.equals("R")) {
                parentNode.right = childNode;
            }

            map.put(parent, parentNode);
            map.put(child, childNode);

            if (root == null) {
                root = parentNode;
            }
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Build the tree based on user input
        Node root = buildTree(scanner);

        // Perform boundary traversal
        System.out.println("Boundary traversal:");
        List<Integer> result = boundaryTraversal(root);
        for (int value : result) {
            System.out.print(value + " ");
        }
        System.out.println();

        scanner.close();
    }
}
