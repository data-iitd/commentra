import java.util.ArrayList; 
import java.util.List; 
import java.util.Scanner; 

public class Main { 
    // Number of nodes in the graph
    static int n; 
    // Adjacency list representation of the graph, where each node points to a list of edges
    static List<ArrayList<Edge>> g; 
    // Array to store the answer for each edge
    static int[] ans; 

    public static void main(String[] args) { 
        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of nodes
        int n = Integer.parseInt(sc.next()); 
        
        // Initialize the adjacency list for the graph
        g = new ArrayList(); 
        for (int i = 0; i < n; i++) { 
            g.add(new ArrayList<Edge>()); 
        } 
        
        // Read edges and populate the adjacency list
        for (int i = 0; i < n - 1; i++) { 
            // Read the two endpoints of the edge, adjusting for 0-based indexing
            int a = Integer.parseInt(sc.next()) - 1; 
            int b = Integer.parseInt(sc.next()) - 1; 
            // Add the edge to both endpoints' adjacency lists
            g.get(a).add(new Edge(i, b)); 
            g.get(b).add(new Edge(i, a)); 
        } 
        
        // Initialize the answer array to store results for each edge
        ans = new int[n - 1]; 
        
        // Perform a depth-first search starting from node 0
        dfs(0, -1, -1); 
        
        // Find the maximum value in the ans array
        int max = 0; 
        for (int temp : ans) { 
            max = Math.max(max, temp); 
        } 
        
        // Output the maximum value found
        System.out.println(max); 
        
        // Output the results for each edge
        for (int c : ans) { 
            System.out.println(c); 
        } 
    } 

    // Depth-first search function to traverse the graph and assign colors to edges
    static void dfs(int to, int color, int parents) { 
        int k = 1; // Start coloring with color 1
        for (Edge e : g.get(to)) { 
            // Skip the edge leading back to the parent node
            if (e.to == parents) continue; 
            // If the current color is the same as the edge color, increment it
            if (k == color) k++; 
            // Assign the color to the edge
            ans[e.id] = k; 
            // Recursively call dfs for the connected node
            dfs(e.to, k, to); 
            k++; // Increment color for the next edge
        } 
    } 
} 

// Class to represent an edge in the graph
class Edge { 
    // Constructor to initialize edge with id and destination
    Edge(int id, int to) { 
        this.id = id; 
        this.to = to; 
    } 
    int id; // Unique identifier for the edge
    int to; // Destination node of the edge
}
