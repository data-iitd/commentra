import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of nodes in the graph
        int n = sc.nextInt();
        
        // Initialize an adjacency matrix to represent the graph
        int[][] g = new int[n+1][n+1];
        
        // Read the edges of the graph
        for (int i = 0; i < n; i++) {
            // Read the current node and the number of edges from it
            int u = sc.nextInt();
            int k = sc.nextInt();
            // Read each edge and update the adjacency matrix
            for (int j = 0; j < k; j++) {
                int v = sc.nextInt();
                g[u][v] = 1; // Mark the edge from u to v
            }
        }
        
        // Initialize the distance array to track distances from the starting node
        int[] d = new int[n+1];
        // Set all distances to -1 (indicating unvisited)
        for (int i = 0; i <= n; i++) {
            d[i] = -1;
        }
        
        // Create a queue for BFS and add the starting node (node 1)
        Queue<Integer> que = new LinkedList<Integer>();
        que.add(1);
        d[1] = 0; // Distance to the starting node is 0
        
        // Perform BFS to calculate distances from the starting node
        while (!que.isEmpty()) {
            int top = que.poll(); // Get the front node from the queue
            // Explore all adjacent nodes
            for (int j = 1; j <= n; j++) {
                // If there is an edge and the node has not been visited
                if (g[top][j] == 1 && d[j] == -1) {
                    que.add(j); // Add the node to the queue
                    d[j] = d[top] + 1; // Update the distance
                }
            }
        }
        
        // Output the distances from the starting node to all other nodes
        for (int i = 1; i <= n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }
}
