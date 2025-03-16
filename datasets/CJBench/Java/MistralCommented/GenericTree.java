
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    // Declare a private static final class Node with its properties
    private static final class Node {
        int data;
        ArrayList<Node> child = new ArrayList<>();
    }
    
    // Initialize root node
    private final Node root;

    // Constructor that takes a Scanner object as an argument
    public Main(Scanner scanner) {
        root = createTree(null, 0, scanner);
    }

    // Method to create a tree recursively
    private Node createTree(Node parent, int childIndex, Scanner scanner) {
        // If parent is null, it means we are creating the root node
        if (parent == null) {
            System.out.println("Enter root's data:");
        } else {
            System.out.println("Enter data for child " + (childIndex + 1) + " of " + parent.data + ":");
        }

        Node node = new Node();
        node.data = scanner.nextInt();

        // Ask user for number of children for the current node
        System.out.println("Enter the number of children for " + node.data + ":");
        int numChildren = scanner.nextInt();

        // Create children for the current node
        for (int i = 0; i < numChildren; i++) {
            Node child = createTree(node, i, scanner);
            node.child.add(child);
        }

        return node;
    }

    // Method to display the tree in a pre-order traversal manner
    public void display() {
        displayTree(root);
    }

    // Recursive method to display the tree
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

    // Method to find the size of the tree
    public int size() {
        return sizeHelper(root);
    }

    // Recursive helper method to find the size of the tree
    private int sizeHelper(Node node) {
        int size = 0;
        for (Node child : node.child) {
            size += sizeHelper(child);
        }
        return size + 1;
    }

    // Method to find the maximum value in the tree
    public int max() {
        return maxHelper(root);
    }

    // Recursive helper method to find the maximum value in the tree
    private int maxHelper(Node node) {
        int max = node.data;
        for (Node child : node.child) {
            max = Math.max(max, maxHelper(child));
        }
        return max;
    }

    // Method to find the height of the tree
    public int height() {
        return heightHelper(root) - 1;
    }

    // Recursive helper method to find the height of the tree
    private int heightHelper(Node node) {
        int height = 0;
        for (Node child : node.child) {
            height = Math.max(height, heightHelper(child));
        }
        return height + 1;
    }

    // Method to check if a value exists in the tree
    public boolean find(int value) {
        return findHelper(root, value);
    }

    // Recursive helper method to check if a value exists in the tree
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

    // Method to perform level order traversal of the tree
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

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main tree = new Main(scanner);

        // Display tree, size, max, height, and perform search and level order traversal
        System.out.println("\nTree Display:");
        tree.display();
        System.out.println("\nSize of the tree: " + tree.size());
        System.out.println("Maximum value in the tree: " + tree.max());
        System.out.println("Height of the tree: " + tree.height());
        System.out.println("\nEnter a value to search:");
        int searchValue = scanner.nextInt();
        System.out.println("Is value present: " + tree.find(searchValue));
        System.out.println("\nLevel Order Traversal:");
        tree.levelOrder();
    }
}