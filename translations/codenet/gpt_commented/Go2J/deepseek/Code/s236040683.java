import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    // Helper function to print output to the console.
    public static void out(Object... x) {
        for (Object obj : x) {
            System.out.println(obj);
        }
    }

    // Node class representing a graph node with a list of connected nodes.
    static class Node {
        List<Integer> to; // List to hold indices of connected nodes

        Node() {
            to = new ArrayList<>();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes (N) and edges (M) from input
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Create an array of Node objects to represent the graph
        Node[] n = new Node[N];
        for (int i = 0; i < N; i++) {
            n[i] = new Node();
        }

        // Read M edges and populate the graph
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1; // Read the edge endpoints (0-indexed)
            int to = sc.nextInt() - 1; // Read the edge endpoints (0-indexed)
            n[from].to.add(to); // Add the connection from 'from' to 'to'
            n[to].to.add(from); // Add the connection from 'to' to 'from' (undirected graph)
        }

        // Output the degree (number of connections) of each node
        for (int i = 0; i < N; i++) {
            out(n[i].to.size()); // Print the number of connections for node i
        }

        sc.close(); // Close the scanner
    }
}
