
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    private class Node {
        public long pattern = 0; // Stores the pattern for the node
        public int index; // Index of the node in the tree
        public LinkedList<Integer> children = new LinkedList<>(); // List of children nodes
        public int parent = -1; // Index of the parent node, initialized to -1 for root

        // Constructor to initialize the node with a given index
        public Node(int i) {
            this.index = i;
        }

        // Method to set the parent of the node recursively
        public void setParent(int K, int parent, int use, Node[] nodes) {
            this.pattern = K - use; // Set the pattern for the node
            this.parent = parent; // Set the parent index
            int count = 1; // Initialize count of children
            if (parent != -1) {
                count++; // Increment count if the node has a parent
            }
            for (int n : children) { // Iterate through children
                if (n == this.parent) {
                    continue; // Skip the current parent to avoid recursion loop
                }
                nodes[n].setParent(K, index, count, nodes); // Recursively set parent for children
                count++; // Increment count for the next child
            }
        }
    }

    // Method to solve the problem
    public void solve() {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(); // Read number of nodes
        int K = in.nextInt(); // Read parameter K
        Node[] nodes = new Node[N]; // Initialize array of nodes
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node(i); // Initialize each node
        }
        for (int i = 0; i < N - 1; i++) {
            int a = in.nextInt() - 1; // Read edge node a
            int b = in.nextInt() - 1; // Read edge node b
            nodes[a].children.add(b); // Add b as a child of a
            nodes[b].children.add(a); // Add a as a child of b
        }
        in.close(); // Close the scanner
        nodes[0].setParent(K, -1, 0, nodes); // Set parent for the root node
        long patterns = 1; // Initialize patterns variable
        for (int i = 0; i < N; i++) {
            patterns = (patterns * nodes[i].pattern) % 1_000_000_007; // Calculate total patterns
        }
        System.out.println(patterns); // Print the result
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
}

