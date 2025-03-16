import java.util.Scanner;

import javax.swing.tree.TreeNode;

/**
 * Simple TreeNode extension that holds references to two child Nodes (left and
 * right).
 *
 * @param <E> The type of the data held in the Node.
 *
 * @author <a href="https://github.com/aitorfi">aitorfi</a>
 */
public class SimpleTreeNode<E> {
    private E data;
    /**
     * Refrence to the child Node on the left.
     */
    private SimpleTreeNode<E> leftNode;
    /**
     * Refrence to the child Node on the right.
     */

    private SimpleTreeNode<E> rightNode;

    /**
     * Refrence to the child Node on the left.
     */
    public SimpleTreeNode(E data) {
        this.data = data;
    }

    public E getData() {
        return data;
    }

    public void setLeftNode(SimpleTreeNode<E> leftNode) {
        this.leftNode = leftNode;
    }

    public void setRightNode(SimpleTreeNode<E> rightNode) {
        this.rightNode = rightNode;
    }

    public SimpleTreeNode<E> getLeftNode() {
        return leftNode;
    }

    public SimpleTreeNode<E> getRightNode() {
        return rightNode;
    }

    /**
     * @return True if the node is a leaf node, otherwise false.
     * @see TreeNode#isLeafNode()
     */
    public boolean isLeafNode() {
        return leftNode == null && rightNode == null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input number of nodes
        int n = scanner.nextInt();

        // Create an array of nodes
        SimpleTreeNode<Integer>[] nodes = new SimpleTreeNode[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new SimpleTreeNode<>(i);
        }

        // Input edges
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt();
            int child = scanner.nextInt();
            String direction = scanner.next();

            if (direction.equals("L")) {
                nodes[parent].setLeftNode(nodes[child]);
            } else if (direction.equals("R")) {
                nodes[parent].setRightNode(nodes[child]);
            }
        }

        // Perform pre-order traversal and print the tree
        preOrderTraversal(nodes[1]);

        scanner.close();
    }

    private static void preOrderTraversal(SimpleTreeNode<Integer> root) {
        if (root == null) {
            return;
        }

        System.out.print(root.getData() + " ");
        preOrderTraversal(root.getLeftNode());
        preOrderTraversal(root.getRightNode());
    }
}
