
import java.util.Scanner;

/**
 * @author jack870131
 */
public class RedBlackBST {

    // Constants to represent node colors
    private static final int RED = 0;
    private static final int BLACK = 1;

    /**
     * Inner class to represent a Node in the Red-Black Tree.
     */
    private class Node {
        int key;
        int color = BLACK;
        Node left = nil, right = nil, p = nil;

        Node(int key) {
            this.key = key;
        }
    }

    // Sentinel nil node to represent null nodes
    private final Node nil = new Node(-1);
    private Node root = nil;

    /**
     * Print the tree in an in-order traversal.
     * @param node The starting node for the traversal.
     */
    public void printTree(Node node) {
        if (node == nil) return;
        printTree(node.left);
        System.out.print(((node.color == RED) ? "R " : "B ") + node.key + " ");
        printTree(node.right);
    }

    /**
     * Insert a new key into the Red-Black Tree.
     * @param key The key to be inserted.
     */
    public void insert(int key) {
        Node node = new Node(key);
        Node temp = root;
        if (root == nil) {
            root = node;
            node.color = BLACK;
        } else {
            node.color = RED;
            while (true) {
                if (key < temp.key) {
                    if (temp.left == nil) {
                        temp.left = node;
                        node.p = temp;
                        break;
                    }
                    temp = temp.left;
                } else {
                    if (temp.right == nil) {
                        temp.right = node;
                        node.p = temp;
                        break;
                    }
                    temp = temp.right;
                }
            }
            fixTree(node);
        }
    }

    /**
     * Fix the Red-Black Tree after an insertion to maintain its properties.
     * @param node The newly inserted node.
     */
    private void fixTree(Node node) {
        while (node.p.color == RED) {
            if (node.p == node.p.p.left) {
                Node y = node.p.p.right;
                if (y.color == RED) {
                    node.p.color = BLACK;
                    y.color = BLACK;
                    node.p.p.color = RED;
                    node = node.p.p;
                } else {
                    if (node == node.p.right) {
                        node = node.p;
                        rotateLeft(node);
                    }
                    node.p.color = BLACK;
                    node.p.p.color = RED;
                    rotateRight(node.p.p);
                }
            } else {
                Node y = node.p.p.left;
                if (y.color == RED) {
                    node.p.color = BLACK;
                    y.color = BLACK;
                    node.p.p.color = RED;
                    node = node.p.p;
                } else {
                    if (node == node.p.left) {
                        node = node.p;
                        rotateRight(node);
                    }
                    node.p.color = BLACK;
                    node.p.p.color = RED;
                    rotateLeft(node.p.p);
                }
            }
        }
        root.color = BLACK;
    }

    /**
     * Perform a left rotation on the given node.
     * @param node The node to rotate.
     */
    private void rotateLeft(Node node) {
        Node temp = node.right;
        node.right = temp.left;
        if (temp.left != nil) temp.left.p = node;
        temp.p = node.p;
        if (node.p == nil) root = temp;
        else if (node == node.p.left) node.p.left = temp;
        else node.p.right = temp;
        temp.left = node;
        node.p = temp;
    }

    /**
     * Perform a right rotation on the given node.
     * @param node The node to rotate.
     */
    private void rotateRight(Node node) {
        Node temp = node.left;
        node.left = temp.right;
        if (temp.right != nil) temp.right.p = node;
        temp.p = node.p;
        if (node.p == nil) root = temp;
        else if (node == node.p.right) node.p.right = temp;
        else node.p.left = temp;
        temp.right = node;
        node.p = temp;
    }

    /**
     * Print the tree in an in-order traversal.
     */
    public void printInOrder() {
        printTree(root);
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        RedBlackBST rbTree = new RedBlackBST();

        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt();
            rbTree.insert(key);
        }

        System.out.println("In-order traversal:");
        rbTree.printInOrder();

        scanner.close();
    }
}
