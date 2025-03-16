import java.util.Scanner;

public class ShortestPath {
    static final int N = 100000;  // Define a constant for the maximum number of nodes
    static final int INF = 1000000;  // Define a constant for representing infinity

    // Class to represent a directed edge with a cost
    static class Edge {
        int go;    // Destination node
        int back;  // Source node
        int cost;  // Cost of the edge

        Edge(int back, int go, int cost) {
            this.back = back;
            this.go = go;
            this.cost = cost;
        }
    }

    static int n;  // Number of nodes
    static int[] d = new int[N];  // Array to store the shortest distances
    static Edge[] edges = new Edge[500000];  // Array to store edges

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0;  // Counter for edges

        n = scanner.nextInt();  // Read the number of nodes

        // Read edges for each node
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt();  // Current node
            int k = scanner.nextInt();  // Number of edges
            for (int j = 0; j < k; j++) {
                int go = scanner.nextInt();  // Destination node
                int cost = scanner.nextInt();  // Cost of the edge
                edges[count++] = new Edge(u, go, cost);  // Create and store the edge
            }
        }

        // Call the root function to compute shortest paths
        root(count);

        // Print the shortest distances from the source node to each node
        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);  // Output the node index and its distance
        }

        scanner.close();  // Close the scanner
    }

    // Function to compute shortest paths using the Bellman-Ford algorithm
    static void root(int b) {
        boolean flag;  // Flag to indicate changes

        // Initialize distances to all nodes as infinity
        for (int i = 0; i < n; i++) {
            d[i] = INF;
        }
        d[0] = 0;  // Set the distance to the source node (node 0) as 0

        // Repeat the process until no changes occur
        do {
            flag = false;  // Reset flag for this iteration
            // Relax all edges
            for (int i = 0; i < b; i++) {
                // Check if the current edge can provide a shorter path
                if (edges[i].cost + d[edges[i].back] < d[edges[i].go]) {
                    d[edges[i].go] = edges[i].cost + d[edges[i].back];  // Update the shortest distance
                    flag = true;  // Set flag to indicate a change occurred
                }
            }
        } while (flag);
    }
}
// <END-OF-CODE>
