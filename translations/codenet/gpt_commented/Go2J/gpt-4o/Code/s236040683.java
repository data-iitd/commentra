import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Node represents a graph node with a list of connected nodes.
class Node {
    List<Integer> to; // List to hold indices of connected nodes

    public Node() {
        to = new ArrayList<>(); // Initialize the list
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner to read input

        // Read the number of nodes (N) and edges (M) from input
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        // Create an array of Node structures to represent the graph
        Node[] nodes = new Node[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node(); // Initialize each node
        }

        // Read M edges and populate the graph
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1; // Read the edge endpoint (0-indexed)
            int to = sc.nextInt() - 1; // Read the edge endpoint (0-indexed)
            nodes[from].to.add(to); // Add the connection from 'from' to 'to'
            nodes[to].to.add(from); // Add the connection from 'to' to 'from' (undirected graph)
        }

        // Output the degree (number of connections) of each node
        for (int i = 0; i < N; i++) {
            System.out.println(nodes[i].to.size()); // Print the number of connections for node i
        }

        sc.close(); // Close the scanner
    }
}

// <END-OF-CODE>
