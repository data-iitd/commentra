import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    // Node class representing each node in the tree
    private static final class Node {
        int data; // Data stored in the node
        ArrayList<Node> child = new ArrayList<>(); // List to hold child nodes
    }

    private final Node root; // Root node of the tree

    // Constructor to initialize the tree by creating it from user input
    public Main(Scanner scn) {
        root = createTree(null, 0, scn); // Start creating the tree with no parent
    }

    // Recursive method to create the tree structure
    private Node createTree(Node parent, int childIndex, Scanner scanner) {
        // Prompt for root data or child data based on the parent node
        if (parent == null) {
            System.out.println("Enter root's data:");
        } else {
            System.out.println("Enter data for child " + (childIndex + 1) + " of " + parent.data + ":");
        }
        
        // Create a new node and set its data
        Node node = new Node();
        node.data = scanner.nextInt();
        
        // Prompt for the number of children for the current node
        System.out.println("Enter the number of children for " + node.data + ":");
        int numChildren = scanner.nextInt();
        
        // Recursively create child nodes
        for (int i = 0; i < numChildren; i++) {
            Node child = createTree(node, i, scanner); // Create child node
            node.child.add(child); // Add child to the current node
        }
        
        return node; // Return the created node
    }

    // Method to display the tree structure
    public void display() {
        displayTree(root); // Start displaying from the root
    }

    // Recursive method to display each node and its children
    private void displayTree(Node node) {
        System.out.print(node.data + " => "); // Print current node's data
        for (Node child : node.child) {
            System.out.print(child.data + " "); // Print each child's data
        }
        System.out.println("."); // End of current node's children
        
        // Recursively display each child node
        for (Node child : node.child) {
            displayTree(child);
        }
    }

    // Method to calculate the size of the tree
    public int size() {
        return sizeHelper(root); // Start size calculation from the root
    }

    // Recursive helper method to calculate the size of the tree
    private int sizeHelper(Node node) {
        int size = 0; // Initialize size count
        for (Node child : node.child) {
            size += sizeHelper(child); // Add size of each child
        }
        return size + 1; // Return total size including the current node
    }

    // Method to find the maximum value in the tree
    public int max() {
        return maxHelper(root); // Start max calculation from the root
    }

    // Recursive helper method to find the maximum value in the tree
    private int maxHelper(Node node) {
        int max = node.data; // Initialize max with current node's data
        for (Node child : node.child) {
            max = Math.max(max, maxHelper(child)); // Compare with child's max
        }
        return max; // Return the maximum value found
    }

    // Method to calculate the height of the tree
    public int height() {
        return heightHelper(root) - 1; // Height is one less than the depth
    }

    // Recursive helper method to calculate the height of the tree
    private int heightHelper(Node node) {
        int height = 0; // Initialize height count
        for (Node child : node.child) {
            height = Math.max(height, heightHelper(child)); // Get max height from children
        }
        return height + 1; // Return height including the current node
    }

    // Method to find a specific value in the tree
    public boolean find(int value) {
        return findHelper(root, value); // Start search from the root
    }

    // Recursive helper method to search for a value in the tree
    private boolean findHelper(Node node, int value) {
        if (node.data == value) {
            return true; // Value found
        }
        // Recursively search in each child
        for (Node child : node.child) {
            if (findHelper(child, value)) {
                return true; // Value found in child
            }
        }
        return false; // Value not found
    }

    // Method for level order traversal of the tree
    public void levelOrder() {
        LinkedList<Node> queue = new LinkedList<>(); // Queue for level order traversal
        queue.add(root); // Start with the root node
        while (!queue.isEmpty()) {
            Node current = queue.poll(); // Get the current node
            System.out.print(current.data + " "); // Print current node's data
            queue.addAll(current.child); // Add all children to the queue
        }
        System.out.println(); // New line after traversal
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in); // Scanner for user input
        Main tree = new Main(scn); // Create a new tree from user input
        System.out.println("\nTree Display:");
        tree.display(); // Display the created tree
        System.out.println("\nSize of the tree: " + tree.size()); // Print size of the tree
        System.out.println("Maximum value in the tree: " + tree.max()); // Print max value in the tree
        System.out.println("Height of the tree: " + tree.height()); // Print height of the tree
        System.out.println("\nEnter a value to search:");
        int searchValue = scn.nextInt(); // Get value to search from user
        System.out.println("Is value present: " + tree.find(searchValue)); // Check if value is present
        System.out.println("\nLevel Order Traversal:");
        tree.levelOrder(); // Print level order traversal of the tree
    }
}
