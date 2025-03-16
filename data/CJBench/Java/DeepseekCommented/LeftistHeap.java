import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Node class representing each element in the heap
    private static final class Node {
        private final int element; // The value of the node
        private int npl; // Null Path Length (NPL) for heap property
        private Node left; // Left child node
        private Node right; // Right child node

        // Constructor to initialize a node with a given element
        private Node(int element) {
            this.element = element;
            left = null; // Initialize left child as null
            right = null; // Initialize right child as null
            npl = 0; // Initialize NPL to 0
        }
    }

    private Node root; // Root node of the heap

    // Constructor to initialize the heap
    public Main() {
        root = null; // Initially, the heap is empty
    }

    // Method to check if the heap is empty
    public boolean isEmpty() {
        return root == null; // Returns true if root is null
    }

    // Method to clear the heap
    public void clear() {
        root = null; // Set root to null to clear the heap
    }

    // Method to merge two heaps
    public void merge(Main h1) {
        root = merge(root, h1.root); // Merge the current heap with h1
        h1.root = null; // Clear h1 after merging
    }

    // Recursive method to merge two nodes
    public Node merge(Node a, Node b) {
        // Base cases for merging
        if (a == null) return b; // If a is null, return b
        if (b == null) return a; // If b is null, return a

        // Ensure that 'a' is the smaller element
        if (a.element > b.element) {
            Node temp = a; // Swap a and b
            a = b;
            b = temp;
        }

        // Recursively merge the right child of 'a' with 'b'
        a.right = merge(a.right, b);

        // Adjust the left and right children based on NPL
        if (a.left == null) {
            a.left = a.right; // If left is null, make left point to right
            a.right = null; // Set right to null
        } else if (a.left.npl < a.right.npl) {
            Node temp = a.left; // Swap left and right if left's NPL is less
            a.left = a.right;
            a.right = temp;
        }

        // Update the NPL of the current node
        a.npl = a.right == null ? 0 : a.right.npl + 1;
        return a; // Return the merged node
    }

    // Method to insert a new element into the heap
    public void insert(int a) {
        root = merge(new Node(a), root); // Merge the new node with the current heap
    }

    // Method to extract the minimum element from the heap
    public int extractMin() {
        if (isEmpty()) return -1; // Return -1 if the heap is empty
        int min = root.element; // Store the minimum element
        root = merge(root.left, root.right); // Merge left and right children to maintain heap
        return min; // Return the minimum element
    }

    // Method to perform in-order traversal of the heap
    public ArrayList<Integer> inOrder() {
        ArrayList<Integer> lst = new ArrayList<>(); // List to store in-order elements
        inOrderAux(root, lst); // Call auxiliary method for traversal
        return lst; // Return the list of elements
    }

    // Auxiliary method for in-order traversal
    private void inOrderAux(Node n, ArrayList<Integer> lst) {
        if (n == null) return; // Base case: if node is null, return
        inOrderAux(n.left, lst); // Traverse left subtree
        lst.add(n.element); // Add current node's element to the list
        inOrderAux(n.right, lst); // Traverse right subtree
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner for user input
        Main heap = new Main(); // Create a new heap instance

        // Loop to process user commands
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim(); // Read user command
            if (command.isEmpty()) break; // Exit loop if command is empty
            String[] parts = command.split(" "); // Split command into parts
            String operation = parts[0]; // Get the operation type

            try {
                // Switch case to handle different operations
                switch (operation) {
                    case "insert": 
                        int value = Integer.parseInt(parts[1]); // Parse the value to insert
                        heap.insert(value); // Insert the value into the heap
                        System.out.println("Inserted: " + value); // Confirmation message
                        break;
                    case "extractMin": 
                        int min = heap.extractMin(); // Extract the minimum value
                        System.out.println(min == -1 ? "Heap is empty" : "Extracted Min: " + min); // Output result
                        break;
                    case "inOrder": 
                        ArrayList<Integer> inOrderList = heap.inOrder(); // Get in-order traversal
                        System.out.println("In-Order: " + inOrderList); // Output the in-order list
                        break;
                    case "clear": 
                        heap.clear(); // Clear the heap
                        System.out.println("Heap cleared"); // Confirmation message
                        break;
                    case "isEmpty": 
                        System.out.println("Is Empty: " + heap.isEmpty()); // Check if heap is empty
                        break;
                    default:
                        System.out.println("Unknown operation: " + operation); // Handle unknown commands
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Handle exceptions
            }
        }
        scanner.close(); // Close the scanner
    }
}
