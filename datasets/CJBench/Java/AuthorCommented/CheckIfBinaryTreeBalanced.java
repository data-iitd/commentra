import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;


class BinaryTree {

    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    Node root;

    // Create binary tree from user input
    public void createTree() {
        Scanner sc = new Scanner(System.in);
        root = new Node(sc.nextInt());
        createTreeRecursive(root, sc);
    }

    private void createTreeRecursive(Node node, Scanner sc) {
        if (node == null) return;

        int leftData = sc.nextInt();
        if (leftData != -1) {
            node.left = new Node(leftData);
            createTreeRecursive(node.left, sc);
        }

        int rightData = sc.nextInt();
        if (rightData != -1) {
            node.right = new Node(rightData);
            createTreeRecursive(node.right, sc);
        }
    }
}

/**
 * This class will check if a BinaryTree is balanced. A balanced binary tree is
 * defined as a binary tree where the difference in height between the left and
 * right subtree of each node differs by at most one.
 * <p>
 * This can be done in both an iterative and recursive fashion. Below,
 * `isBalancedRecursive()` is implemented in a recursive fashion, and
 * `isBalancedIterative()` is implemented in an iterative fashion.
 *
 * @author [Ian Cowan](<a href="https://github.com/iccowan">Git-Ian Cowan</a>)
 */
public class CheckIfBinaryTreeBalanced {

    /**
     * Recursive is BT balanced implementation
     *
     * @param root The binary tree to check if balanced
     */
    public static boolean isBalancedRecursive(BinaryTree.Node root) {
        if (root == null) return true;

        // Create an array of length 1 to keep track of our balance
        // Default to true. We use an array, so we have an efficient mutable object
        boolean[] isBalanced = new boolean[1];
        isBalanced[0] = true;
        // Check for balance and return whether we are balanced
        isBalancedRecursiveHelper(root, isBalanced);
        return isBalanced[0];
    }

    /**
     * Private helper method to keep track of the depth and balance during
     * recursion. We effectively perform a modified post-order traversal where
     * we are looking at the heights of both children of each node in the tree
     *
     * @param node       The current node to explore
     * @param depth      The current depth of the node
     * @param isBalanced The array of length 1 keeping track of our balance
     */
    private static int isBalancedRecursiveHelper(BinaryTree.Node node, boolean[] isBalanced) {
        // If the node is null, we should not explore it and the height is 0
        // If the tree is already not balanced, might as well stop because we
        // can't make it balanced now!
        if (node == null || !isBalanced[0]) return 0;

        // Visit the left and right children, incrementing their depths by 1
        int leftHeight = isBalancedRecursiveHelper(node.left, isBalanced);
        int rightHeight = isBalancedRecursiveHelper(node.right, isBalanced);

        // The height of our tree is the maximum of the heights of the left
        // and right subtrees plus one
        if (Math.abs(leftHeight - rightHeight) > 1) isBalanced[0] = false;

        return Math.max(leftHeight, rightHeight) + 1;
    }

    /**
     * Iterative is BT balanced implementation
     */
    public static boolean isBalancedIterative(BinaryTree.Node root) {
        if (root == null) return true;

        // Default that we are balanced and our algo will prove it wrong
        boolean isBalanced = true;
        // Create a stack for our post order traversal
        Stack<BinaryTree.Node> stack = new Stack<>();
        // For post order traversal, we'll have to keep track of where we
        // visited last
        HashMap<BinaryTree.Node, Integer> subtreeHeights = new HashMap<>();
        // Create a HashMap to keep track of the subtree heights for each node
        BinaryTree.Node lastVisited = null;
        // We begin at the root of the tree
        BinaryTree.Node node = root;

        // We loop while:
        // - the node stack is empty and the node we explore is null
        // AND
        // - the tree is still balanced
        while (!stack.isEmpty() || node != null) {
            // If the node is not null, we push it to the stack and continue
            // to the left
            if (node != null) {
                stack.push(node);
                node = node.left;
                // Once we hit a node that is null, we are as deep as we can go
                // to the left
            } else {
                // Find the last node we put on the stack
                node = stack.peek();
                // If the right child of the node has either been visited or
                // is null, we visit this node
                if (node.right == null || node.right == lastVisited) {
                    // We assume the left and right heights are 0
                    int leftHeight = subtreeHeights.getOrDefault(node.left, 0);
                    int rightHeight = subtreeHeights.getOrDefault(node.right, 0);

                    if (Math.abs(leftHeight - rightHeight) > 1) isBalanced = false;

                    subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1);
                    lastVisited = node;
                    stack.pop();
                    node = null;
                } else {
                    node = node.right;
                }
            }
        }
        return isBalanced;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.createTree();

        System.out.println("Is tree balanced (recursive): " + isBalancedRecursive(tree.root));
        System.out.println("Is tree balanced (iterative): " + isBalancedIterative(tree.root));
    }
}
