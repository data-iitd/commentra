import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
public class GenericTree {
    private static final class Node {
        int data;
        ArrayList<Node> child = new ArrayList<>();
    }
    private final Node root;
    public GenericTree(Scanner scn) {
        root = createTree(null, 0, scn);
    }
    private Node createTree(Node parent, int childIndex, Scanner scanner) {
        if (parent == null) {
            System.out.println("Enter root's data:");
        } else {
            System.out.println("Enter data for child " + (childIndex + 1) + " of " + parent.data + ":");
        }
        Node node = new Node();
        node.data = scanner.nextInt();
        System.out.println("Enter the number of children for " + node.data + ":");
        int numChildren = scanner.nextInt();
        for (int i = 0; i < numChildren; i++) {
            Node child = createTree(node, i, scanner);
            node.child.add(child);
        }
        return node;
    }
    public void display() {
        displayTree(root);
    }
    private void displayTree(Node node) {
        System.out.print(node.data + " => ");
        for (Node child : node.child) {
            System.out.print(child.data + " ");
        }
        System.out.println(".");
        for (Node child : node.child) {
            displayTree(child);
        }
    }
    public int size() {
        return sizeHelper(root);
    }
    private int sizeHelper(Node node) {
        int size = 0;
        for (Node child : node.child) {
            size += sizeHelper(child);
        }
        return size + 1;
    }
    public int max() {
        return maxHelper(root);
    }
    private int maxHelper(Node node) {
        int max = node.data;
        for (Node child : node.child) {
            max = Math.max(max, maxHelper(child));
        }
        return max;
    }
    public int height() {
        return heightHelper(root) - 1;
    }
    private int heightHelper(Node node) {
        int height = 0;
        for (Node child : node.child) {
            height = Math.max(height, heightHelper(child));
        }
        return height + 1;
    }
    public boolean find(int value) {
        return findHelper(root, value);
    }
    private boolean findHelper(Node node, int value) {
        if (node.data == value) {
            return true;
        }
        for (Node child : node.child) {
            if (findHelper(child, value)) {
                return true;
            }
        }
        return false;
    }
    public void levelOrder() {
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.print(current.data + " ");
            queue.addAll(current.child);
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        GenericTree tree = new GenericTree(scn);
        System.out.println("\nTree Display:");
        tree.display();
        System.out.println("\nSize of the tree: " + tree.size());
        System.out.println("Maximum value in the tree: " + tree.max());
        System.out.println("Height of the tree: " + tree.height());
        System.out.println("\nEnter a value to search:");
        int searchValue = scn.nextInt();
        System.out.println("Is value present: " + tree.find(searchValue));
        System.out.println("\nLevel Order Traversal:");
        tree.levelOrder();
    }
}
