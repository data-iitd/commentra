import java.util.LinkedList; 
import java.util.Scanner; 

public class Main { 
    // Inner class to represent a node in the tree
    private class Node { 
        public long pattern = 0; // Variable to store the pattern value
        public int index; // Index of the node
        public LinkedList<Integer> children = new LinkedList<Integer>(); // List of child nodes
        public int parent = -1; // Parent index, -1 indicates no parent

        // Constructor to initialize the node with its index
        public Node(int i) { 
            this.index = i; 
        } 

        // Method to set the parent of the node and calculate the pattern
        public void setParent(int K, int parent, int use, Node[] nodes) { 
            this.pattern = K - use; // Calculate the pattern based on K and used count
            this.parent = parent; // Set the parent index
            int count = 1; // Initialize count of used nodes

            // If the node has a parent, increment the count
            if (parent != -1) { 
                count++; 
            } 
            
            // Recursively set the parent for each child node
            for (int n : children) { 
                if (n == this.parent) { // Skip the parent node
                    continue; 
                } 
                nodes[n].setParent(K, index, count, nodes); // Recursive call for child
                count++; // Increment count for each child processed
            } 
        } 
    } 

    // Main logic to solve the problem
    public void solve() { 
        Scanner in = new Scanner(System.in); // Create a scanner for input
        int N = in.nextInt(); // Read the number of nodes
        int K = in.nextInt(); // Read the value of K
        Node[] nodes = new Node[N]; // Array to hold all nodes

        // Initialize nodes
        for (int i = 0; i < N; i++) { 
            nodes[i] = new Node(i); // Create a new node for each index
        } 

        // Read edges and build the tree structure
        for (int i = 0; i < N - 1; i++) { 
            int a = in.nextInt() - 1; // Read first node of the edge
            int b = in.nextInt() - 1; // Read second node of the edge
            nodes[a].children.add(b); // Add b as a child of a
            nodes[b].children.add(a); // Add a as a child of b (undirected tree)
        } 
        in.close(); // Close the scanner

        // Set the parent for the root node (node 0)
        nodes[0].setParent(K, -1, 0, nodes); 

        long patterns = 1; // Variable to store the product of patterns

        // Calculate the product of all node patterns
        for (int i = 0; i < N; i++) { 
            patterns = (patterns * nodes[i].pattern) % 1_000_000_007; // Update patterns with modulo
        } 

        // Output the final result
        System.out.println(patterns); 
    } 

    // Main method to execute the program
    public static void main(String[] args) { 
        Main main = new Main(); // Create an instance of Main
        main.solve(); // Call the solve method to execute the logic
    } 
}
