
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);
        
        // Read the number of nodes in the graph
        int n = sc.nextInt();
        
        // Initialize a 2D array to represent the graph with dimensions (n+1) x (n+1)
        int[][] g = new int[n+1][n+1];
        
        // Read the graph's edges and populate the graph matrix
        for (int i = 0; i < n; i++) {
            int u = sc.nextInt();
            int k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                int v = sc.nextInt();
                g[u][v] = 1;
            }
        }
        
        // Initialize an array to store the shortest distance from the starting node to each node
        int[] d = new int[n+1];
        // Set all distances to -1 initially, indicating unvisited nodes
        for (int i = 0; i <= n; i++) {
            d[i] = -1;
        }
        
        // Initialize a queue for BFS
        Queue<Integer> que = new LinkedList<Integer>();
        // Add the starting node (node 1) to the queue and set its distance to 0
        que.add(1);
        d[1] = 0;
        
        // Perform BFS to find the shortest distances from the starting node
        while (!que.isEmpty()) {
            int top = que.poll();
            for (int j = 1; j <= n; j++) {
                if (g[top][j] == 1 && d[j] == -1) {
                    que.add(j);
                    d[j] = d[top] + 1;
                }
            }
        }
        
        // Output the shortest distance from the starting node to each node
        for (int i = 1; i <= n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }
}