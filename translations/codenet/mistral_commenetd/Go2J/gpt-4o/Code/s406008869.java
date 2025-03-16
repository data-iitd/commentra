// Import necessary packages
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Define the main class
public class Main {
    // Define a list of lists to store the edges of the graph
    static List<List<Integer>> e;
    
    // Define variables to store the number of nodes and edges
    static int n, m;

    // Function to print the edges of the graph
    static void printEdge(List<List<Integer>> e) {
        // Iterate through each node in the graph
        for (int i = 1; i <= n; i++) {
            // Print the node number and its connected nodes
            System.out.print(i + ": ");
            for (int v : e.get(i)) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    // Function to perform Depth First Search traversal
    static int dfs(int v, boolean[] visited) {
        // Check if all nodes are visited, if yes then it's a strongly connected component
        boolean comp = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                comp = false;
                break;
            }
        }

        // If all nodes are visited, return 1 for this strongly connected component
        if (comp) {
            return 1;
        }

        // Initialize a counter to store the size of the strongly connected component
        int count = 0;
        // Iterate through the neighbors of the current node 'v'
        for (int ne : e.get(v)) {
            // If the neighbor is already visited, skip it
            if (visited[ne]) {
                continue;
            }
            // Mark the neighbor as visited
            visited[ne] = true;
            // Recursively call 'dfs' on the neighbor and add its size to the counter
            int rst = dfs(ne, visited);
            count += rst;
            // Mark the neighbor as unvisited
            visited[ne] = false;
        }
        // Return the size of the strongly connected component
        return count;
    }

    // Main function to read input and call the printEdge and dfs functions
    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes and edges from the standard input
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Initialize a list of lists to store the edges of the graph
        e = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            e.add(new ArrayList<>());
        }

        // Read the edges of the graph from the standard input and add them to the e list
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            // Add the edge to the e list for both nodes
            e.get(a).add(b);
            e.get(b).add(a);
        }

        // Call the printEdge function to print the edges of the graph
        // printEdge(e);

        // Initialize a boolean array to keep track of visited nodes
        boolean[] visited = new boolean[n + 1];
        // Mark the first node as visited
        visited[1] = true;
        // Call the dfs function on the first node and print the size of the strongly connected component
        int count = dfs(1, visited);
        System.out.println(count);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
