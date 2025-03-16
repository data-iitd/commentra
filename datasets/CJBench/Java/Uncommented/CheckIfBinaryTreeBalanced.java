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
public class CheckIfBinaryTreeBalanced {
    public static boolean isBalancedRecursive(BinaryTree.Node root) {
        if (root == null) return true;
        boolean[] isBalanced = new boolean[1];
        isBalanced[0] = true;
        isBalancedRecursiveHelper(root, isBalanced);
        return isBalanced[0];
    }
    private static int isBalancedRecursiveHelper(BinaryTree.Node node, boolean[] isBalanced) {
        if (node == null || !isBalanced[0]) return 0;
        int leftHeight = isBalancedRecursiveHelper(node.left, isBalanced);
        int rightHeight = isBalancedRecursiveHelper(node.right, isBalanced);
        if (Math.abs(leftHeight - rightHeight) > 1) isBalanced[0] = false;
        return Math.max(leftHeight, rightHeight) + 1;
    }
    public static boolean isBalancedIterative(BinaryTree.Node root) {
        if (root == null) return true;
        boolean isBalanced = true;
        Stack<BinaryTree.Node> stack = new Stack<>();
        HashMap<BinaryTree.Node, Integer> subtreeHeights = new HashMap<>();
        BinaryTree.Node lastVisited = null;
        BinaryTree.Node node = root;
        while (!stack.isEmpty() || node != null) {
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else {
                node = stack.peek();
                if (node.right == null || node.right == lastVisited) {
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
