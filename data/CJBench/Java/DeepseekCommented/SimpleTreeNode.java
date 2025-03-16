import java.util.Scanner;
import javax.swing.tree.TreeNode; // This import is not used in the code

public class Main<E> { // Generic class definition
    private E data; // Data stored in the node
    private Main<E> leftNode; // Reference to the left child node
    private Main<E> rightNode; // Reference to the right child node

    // Constructor to initialize the node with data
    public Main(E data) {
        this.data = data;
    }

    // Getter for the data stored in the node
    public E getData() {
        return data;
    }

    // Setter for the left child node
    public void setLeftNode(Main<E> leftNode) {
        this.leftNode = leftNode;
    }

    // Setter for the right child node
    public void setRightNode(Main<E> rightNode) {
        this.rightNode = rightNode;
    }

    // Getter for the left child node
    public Main<E> getLeftNode() {
        return leftNode;
    }

    // Getter for the right child node
    public Main<E> getRightNode() {
        return rightNode;
    }

    // Method to check if the node is a leaf node (i.e., has no children)
    public boolean isLeafNode() {
        return leftNode == null && rightNode == null;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of nodes
        Main<Integer>[] nodes = new Main[n + 1]; // Create an array of Main nodes
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Main<>(i); // Initialize each node with its index
        }
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt(); // Read the parent node index
            int child = scanner.nextInt(); // Read the child node index
            String direction = scanner.next(); // Read the direction (L or R)
            if (direction.equals("L")) {
                nodes[parent].setLeftNode(nodes[child]); // Set the left child
            } else if (direction.equals("R")) {
                nodes[parent].setRightNode(nodes[child]); // Set the right child
            }
        }
        preOrderTraversal(nodes[1]); // Start pre-order traversal from the root node
        scanner.close(); // Close the scanner
    }

    // Private static method to perform pre-order traversal and print the data
    private static void preOrderTraversal(Main<Integer> root) {
        if (root == null) {
            return; // Base case: if the node is null, return
        }
        System.out.print(root.getData() + " "); // Print the data of the current node
        preOrderTraversal(root.getLeftNode()); // Recursively traverse the left subtree
        preOrderTraversal(root.getRightNode()); // Recursively traverse the right subtree
    }
}
