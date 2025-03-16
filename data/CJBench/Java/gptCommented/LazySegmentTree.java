import java.util.Scanner;

public class Main {
    // Node class represents a segment of the array with lazy propagation support
    static class Node {
        private final int start; // Start index of the segment
        private final int end;   // End index of the segment
        private int value;       // Value of the segment
        private int lazy;        // Lazy value for deferred updates
        Node left;              // Left child node
        Node right;             // Right child node

        // Constructor to initialize the node with start, end, and initial value
        Node(int start, int end, int value) {
            this.start = start;
            this.end = end;
            this.value = value;
            this.lazy = 0; // Initialize lazy value to 0
            this.left = null; // Left child is initially null
            this.right = null; // Right child is initially null
        }

        // Apply an update to the current node
        public void applyUpdate(int diff) {
            this.lazy += diff; // Update lazy value
            this.value += (this.end - this.start) * diff; // Update the segment value
        }

        // Shift the lazy updates down to the children nodes
        public void shift() {
            if (lazy == 0) {
                return; // No updates to propagate
            }
            if (this.left == null && this.right == null) {
                return; // No children to propagate to
            }
            this.value += this.lazy; // Apply lazy value to the current node's value
            if (this.left != null) {
                this.left.applyUpdate(this.lazy); // Propagate to left child
            }
            if (this.right != null) {
                this.right.applyUpdate(this.lazy); // Propagate to right child
            }
            this.lazy = 0; // Reset lazy value after propagation
        }

        // Merge two nodes into a single node
        static Node merge(Node left, Node right) {
            if (left == null) {
                return right; // If left is null, return right
            }
            if (right == null) {
                return left; // If right is null, return left
            }
            // Create a new node that combines the values of left and right
            Node result = new Node(left.start, right.end, left.value + right.value);
            result.left = left; // Set left child
            result.right = right; // Set right child
            return result; // Return the merged node
        }

        // Get the value of the node
        public int getValue() {
            return value;
        }

        // Get the left child node
        public Node getLeft() {
            return left;
        }

        // Get the right child node
        public Node getRight() {
            return right;
        }
    }

    private final Node root; // Root of the segment tree

    // Constructor to build the segment tree from the given array
    public Main(int[] array) {
        this.root = buildTree(array, 0, array.length); // Build the tree
    }

    // Recursively build the segment tree
    private Node buildTree(int[] array, int start, int end) {
        if (end - start < 2) {
            return new Node(start, end, array[start]); // Leaf node
        }
        int mid = (start + end) >> 1; // Find the midpoint
        Node left = buildTree(array, start, mid); // Build left subtree
        Node right = buildTree(array, mid, end); // Build right subtree
        return Node.merge(left, right); // Merge left and right nodes
    }

    // Update a range of values in the segment tree
    private void updateRange(int left, int right, int diff, Node curr) {
        if (left <= curr.start && curr.end <= right) {
            curr.applyUpdate(diff); // Apply update if current segment is fully within range
            return;
        }
        if (left >= curr.end || right <= curr.start) {
            return; // No overlap
        }
        curr.shift(); // Shift any pending updates
        // Recursively update left and right children
        updateRange(left, right, diff, curr.left);
        updateRange(left, right, diff, curr.right);
        // Merge the updated children back into the current node
        Node merge = Node.merge(curr.left, curr.right);
        curr.value = merge.value; // Update current node's value
    }

    // Retrieve the sum of values in a specified range
    private Node getRange(int left, int right, Node curr) {
        if (left <= curr.start && curr.end <= right) {
            return curr; // Current segment is fully within range
        }
        if (left >= curr.end || right <= curr.start) {
            return null; // No overlap
        }
        curr.shift(); // Shift any pending updates
        // Merge the results from left and right children
        return Node.merge(getRange(left, right, curr.left), getRange(left, right, curr.right));
    }

    // Public method to get the sum of a range
    public int getRange(int left, int right) {
        Node result = getRange(left, right, root); // Get the range from the root
        return result == null ? 0 : result.getValue(); // Return the value or 0 if null
    }

    // Public method to update a range
    public void updateRange(int left, int right, int diff) {
        updateRange(left, right, diff, root); // Update the range starting from the root
    }

    // Get the root node of the segment tree
    public Node getRoot() {
        return root;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        int[] array = new int[n]; // Initialize the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read array elements
        }
        Main tree = new Main(array); // Create the segment tree
        int q = scanner.nextInt(); // Read the number of queries
        for (int i = 0; i < q; i++) {
            String op = scanner.next(); // Read the operation type
            if (op.equals("update")) {
                int left = scanner.nextInt(); // Read left index for update
                int right = scanner.nextInt(); // Read right index for update
                int diff = scanner.nextInt(); // Read the value to add
                tree.updateRange(left, right, diff); // Perform the update
            } else if (op.equals("query")) {
                int left = scanner.nextInt(); // Read left index for query
                int right = scanner.nextInt(); // Read right index for query
                System.out.println(tree.getRange(left, right)); // Output the result of the query
            }
        }
        scanner.close(); // Close the scanner
    }
}
