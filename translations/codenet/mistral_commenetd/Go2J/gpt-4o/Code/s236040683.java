// Import necessary packages
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Main class
public class Main {
    // Custom method for printing output
    static void out(Object... x) {
        for (Object obj : x) {
            System.out.print(obj + " ");
        }
        System.out.println();
    }

    // Node class representing a node in the graph
    static class Node {
        List<Integer> to = new ArrayList<>();

        // Method to add an edge to the node
        void addEdge(int neighbor) {
            to.add(neighbor);
        }
    }

    // Main method
    public static void main(String[] args) {
        // Create a scanner for reading input
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes N and edges M from the input
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Create an array of nodes
        Node[] nodes = new Node[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node();
        }

        // Process each edge by adding it to the corresponding nodes
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;

            // Add the edge to the from and to nodes
            nodes[from].addEdge(to);
            nodes[to].addEdge(from);
        }

        // Print the number of neighbors for each node
        for (int i = 0; i < N; i++) {
            out(nodes[i].to.size());
        }

        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
