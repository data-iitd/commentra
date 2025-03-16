import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
public class Main {
    // Define the Node class which represents a node in the tree
    private static final class Node {
        int data; // Data stored in the node
        ArrayList<Node> child = new ArrayList<>(); // List of child nodes
    }

    // Root node of the tree
    private final Node root;

    // Constructor to build the tree using user input
    public Main(Scanner scn) {
        root = createTree(null, 0, scn); // Create the tree starting with a null parent
    }

    // Recursive method to create the tree
    private Node createTree(Node parent, int childIndex, Scanner scanner) {
        if (parent == null) {
            System.out.println("Enter root's data:"); // Prompt for root's data
        } else {
            System.out.println("Enter data for child " + (childIndex + 1) + " of " + parent.data + ":"); // Prompt for child's data
        }
        Node node = new Node();
        node.data = scanner.nextInt(); // Read the data for the node
        System.out.println("Enter the number of children for " + node.data + ":"); // Prompt for number of children
        int numChildren = scanner.nextInt();
        for (int i = 0; i < numChildren; i++) {
            Node child = createTree(node, i, scanner); // Recursively create each child
            node.child.add(child); // Add the child to the list of children
        }
        return node;
    }

    // Method to display the tree structure
    public void display() {
        displayTree(root); // Start displaying from the root
    }

    // Recursive method to display the tree structure
    private void displayTree(Node node) {
        System.out.print(node.data + " => "); // Print the current node's data
        for (Node child : node.child) {
            System.out.print(child.data + " "); // Print each child's data
        }
        System.out.println("."); // End of the current node's children
        for (Node child : node.child) {
            displayTree(child); // Recursively display each child's subtree
        }
    }

    // Method to calculate the size of the tree
    public int size() {
        return sizeHelper(root); // Start size calculation from the root
    }

    // Recursive method to calculate the size of the tree
    private int sizeHelper(Node node) {
        int size = 0;
        for (Node child : node.child) {
            size += sizeHelper(child); // Sum the size of all children and their subtrees
        }
        return size + 1; // Add the current node
    }

    // Method to find the maximum value in the tree
    public int max() {
        return maxHelper(root); // Start max calculation from the root
    }

    // Recursive method to find the maximum value in the tree
    private int maxHelper(Node node) {
        int max = node.data; // Initialize max with the current node's data
        for (Node child : node.child) {
            max = Math.max(max, maxHelper(child)); // Compare with each child's max and update max
        }
        return max;
    }

    // Method to calculate the height of the tree
    public int height() {
        return heightHelper(root) - 1; // Start height calculation from the root and subtract 1 for zero-based indexing
    }

    // Recursive method to calculate the height of the tree
    private int heightHelper(Node node) {
        int height = 0;
        for (Node child : node.child) {
            height = Math.max(height, heightHelper(child)); // Find the max height among all children
        }
        return height + 1; // Add the current level
    }

    // Method to check if a value exists in the tree
    public boolean find(int value) {
        return findHelper(root, value); // Start search from the root
    }

    // Recursive method to search for a value in the tree
    private boolean findHelper(Node node, int value) {
        if (node.data == value) {
            return true; // If the current node's data matches the value, return true
        }
        for (Node child : node.child) {
            if (findHelper(child, value)) {
                return true; // If the value is found in any child, return true
            }
        }
        return false; // If the value is not found, return false
    }

    // Method to perform level order traversal of the tree
    public void levelOrder() {
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root); // Add the root to the queue
        while (!queue.isEmpty()) {
            Node current = queue.poll(); // Remove the current node from the queue
            System.out.print(current.data + " "); // Print the current node's data
            queue.addAll(current.child); // Add all children to the queue
        }
        System.out.println(); // End of the level order traversal
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Main tree = new Main(scn);
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
