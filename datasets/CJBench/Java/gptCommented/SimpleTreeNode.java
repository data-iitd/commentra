import java.util.Scanner;

public class Main<E> {
    // Node data
    private E data;
    // References to left and right child nodes
    private Main<E> leftNode;
    private Main<E> rightNode;

    // Constructor to initialize the node with data
    public Main(E data) {
        this.data = data;
    }

    // Getter method for node data
    public E getData() {
        return data;
    }

    // Setter method for the left child node
    public void setLeftNode(Main<E> leftNode) {
        this.leftNode = leftNode;
    }

    // Setter method for the right child node
    public void setRightNode(Main<E> rightNode) {
        this.rightNode = rightNode;
    }

    // Getter method for the left child node
    public Main<E> getLeftNode() {
        return leftNode;
    }

    // Getter method for the right child node
    public Main<E> getRightNode() {
        return rightNode;
    }

    // Method to check if the current node is a leaf node
    public boolean isLeafNode() {
        return leftNode == null && rightNode == null;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes
        int n = scanner.nextInt();
        // Create an array to hold the nodes
        Main<Integer>[] nodes = new Main[n + 1];
        
        // Initialize the nodes with their respective data
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Main<>(i);
        }
        
        // Read parent-child relationships and set the left or right child accordingly
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt();
            int child = scanner.nextInt();
            String direction = scanner.next();
            if (direction.equals("L")) {
                // Set the left child node
                nodes[parent].setLeftNode(nodes[child]);
            } else if (direction.equals("R")) {
                // Set the right child node
                nodes[parent].setRightNode(nodes[child]);
            }
        }
        
        // Perform a pre-order traversal starting from the root node
        preOrderTraversal(nodes[1]);
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Method to perform pre-order traversal of the binary tree
    private static void preOrderTraversal(Main<Integer> root) {
        // Base case: if the current node is null, return
        if (root == null) {
            return;
        }
        // Print the data of the current node
        System.out.print(root.getData() + " ");
        // Recursively traverse the left subtree
        preOrderTraversal(root.getLeftNode());
        // Recursively traverse the right subtree
        preOrderTraversal(root.getRightNode());
    }
}
