import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    // Define the Node class to represent segments in the segment tree
    static class Node {
        private final int start; // Start index of the range
        private final int end;   // End index of the range
        private int value;       // Value stored at this node
        private int lazy;        // Lazy propagation value
        Node left;               // Pointer to the left child
        Node right;              // Pointer to the right child

        // Constructor for Node
        Node(int start, int end, int value) {
            this.start = start;
            this.end = end;
            this.value = value;
            this.lazy = 0;
            this.left = null;
            this.right = null;
        }

        // Apply an update to the node and its children
        public void applyUpdate(int diff) {
            this.lazy += diff;
            this.value += (this.end - this.start) * diff;
        }

        // Push the lazy value down to children
        public void shift() {
            if (lazy == 0) {
                return;
            }
            if (this.left == null && this.right == null) {
                return;
            }
            this.value += this.lazy;
            if (this.left != null) {
                this.left.applyUpdate(this.lazy);
            }
            if (this.right != null) {
                this.right.applyUpdate(this.lazy);
            }
            this.lazy = 0;
        }

        // Merge two nodes into one
        static Node merge(Node left, Node right) {
            if (left == null) {
                return right;
            }
            if (right == null) {
                return left;
            }
            Node result = new Node(left.start, right.end, left.value + right.value);
            result.left = left;
            result.right = right;
            return result;
        }

        // Get the value stored at this node
        public int getValue() {
            return value;
        }

        // Get the left child of this node
        public Node getLeft() {
            return left;
        }

        // Get the right child of this node
        public Node getRight() {
            return right;
        }
    }

    // Root of the segment tree
    private final Node root;

    // Constructor for Main class
    public Main(int[] array) {
        this.root = buildTree(array, 0, array.length);
    }

    // Build the segment tree from an array
    private Node buildTree(int[] array, int start, int end) {
        if (end - start < 2) {
            return new Node(start, end, array[start]);
        }
        int mid = (start + end) >> 1;
        Node left = buildTree(array, start, mid);
        Node right = buildTree(array, mid, end);
        return Node.merge(left, right);
    }

    // Update the values in the range [left, right) by adding diff
    private void updateRange(int left, int right, int diff, Node curr) {
        if (left <= curr.start && curr.end <= right) {
            curr.applyUpdate(diff);
            return;
        }
        if (left >= curr.end || right <= curr.start) {
            return;
        }
        curr.shift();
        updateRange(left, right, diff, curr.left);
        updateRange(left, right, diff, curr.right);
        Node merge = Node.merge(curr.left, curr.right);
        curr.value = merge.value;
    }

    // Get the sum of values in the range [left, right)
    private Node getRange(int left, int right, Node curr) {
        if (left <= curr.start && curr.end <= right) {
            return curr;
        }
        if (left >= curr.end || right <= curr.start) {
            return null;
        }
        curr.shift();
        return Node.merge(getRange(left, right, curr.left), getRange(left, right, curr.right));
    }

    // Public method to get the sum of values in the range [left, right)
    public int getRange(int left, int right) {
        Node result = getRange(left, right, root);
        return result == null ? 0 : result.getValue();
    }

    // Public method to update the values in the range [left, right) by adding diff
    public void updateRange(int left, int right, int diff) {
        updateRange(left, right, diff, root);
    }

    // Get the root of the segment tree
    public Node getRoot() {
        return root;
    }

    // Main method to read input, create a Main object, and process queries
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read the array elements
        }
        Main tree = new Main(array);
        int q = scanner.nextInt(); // Read the number of queries
        for (int i = 0; i < q; i++) {
            String op = scanner.next(); // Read the operation type
            if (op.equals("update")) {
                int left = scanner.nextInt(); // Read the left index
                int right = scanner.nextInt(); // Read the right index
                int diff = scanner.nextInt(); // Read the difference
                tree.updateRange(left, right, diff); // Update the range
            } else if (op.equals("query")) {
                int left = scanner.nextInt(); // Read the left index
                int right = scanner.nextInt(); // Read the right index
                System.out.println(tree.getRange(left, right)); // Print the sum of the range
            }
        }
        scanner.close(); // Close the scanner
    }
}
