import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * A generic tree is a tree which can have as many children as it can be It
 * might be possible that every node present is directly connected to root node.
 *
 * <p>
 * In this code Every function has two copies: one function is helper function
 * which can be called from main and from that function a private function is
 * called which will do the actual work. I have done this, while calling from
 * main one have to give minimum parameters.
 */
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

    /**
     * Function to display the generic tree
     */
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

    /**
     * One call store the size directly but if you are asked compute size this
     * function to calculate size goes as follows
     *
     * @return size
     */
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

    /**
     * Function to compute maximum value in the generic tree
     *
     * @return maximum value
     */
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

    /**
     * Function to compute HEIGHT of the generic tree
     *
     * @return height
     */
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

    /**
     * Function to find whether a number is present in the generic tree or not
     *
     * @param info number
     * @return present or not
     */
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

    /**
     * Function to print generic tree in level-order
     */
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
