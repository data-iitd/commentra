import java.util.Scanner;
import javax.swing.tree.TreeNode;
public class SimpleTreeNode<E> {
    private E data;
    private SimpleTreeNode<E> leftNode;
    private SimpleTreeNode<E> rightNode;
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
    public boolean isLeafNode() {
        return leftNode == null && rightNode == null;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        SimpleTreeNode<Integer>[] nodes = new SimpleTreeNode[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new SimpleTreeNode<>(i);
        }
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
