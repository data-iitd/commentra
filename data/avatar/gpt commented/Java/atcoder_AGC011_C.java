import java.util.*; 

class Main implements Runnable {
    // Adjacency list representation of the graph
    ArrayList<Integer>[] graph; 
    // Array to track visited nodes
    boolean[] visited; 
    // Array to store colors of nodes for bipartite checking
    int[] color; 
    // Counters for specific conditions
    long one; 
    long bipartite; 
    long count; 
    // Flag to check if the graph is not bipartite
    boolean mujun; 

    // Depth-First Search (DFS) method to explore the graph
    int dfs(int a, int c) {
        // If the node has already been visited
        if (visited[a]) {
            // Check for color conflict indicating the graph is not bipartite
            if (color[a] >= 0 && color[a] != c) mujun = true; 
            return 0; 
        }
        // Mark the node as visited and assign it a color
        visited[a] = true; 
        color[a] = c; 
        int total = 1; // Count the current node

        // Recursively visit all adjacent nodes with alternate color
        for (int b : graph[a]) {
            total += dfs(b, 1 - c); 
        }
        return total; // Return the total count of nodes in this component
    }

    // Main execution method for the program
    public void run() {
        Scanner scan = new Scanner(System.in); 
        // Read number of nodes and edges
        int n = scan.nextInt(); 
        int m = scan.nextInt(); 

        // Initialize the graph
        this.graph = new ArrayList[n]; 
        for (int i = 0; i < n; ++i) 
            this.graph[i] = new ArrayList<Integer>(); 

        // Read edges and populate the graph
        for (int i = 0; i < m; ++i) {
            int u = scan.nextInt() - 1; // Read first node of the edge
            int v = scan.nextInt() - 1; // Read second node of the edge
            this.graph[u].add(v); // Add edge to the graph
            this.graph[v].add(u); // Add edge in both directions
        }

        // Initialize visited and color arrays
        visited = new boolean[n]; 
        color = new int[n]; 
        Arrays.fill(color, -1); // Set all colors to -1 (uncolored)

        // Initialize counters
        one = 0; 
        bipartite = 0; 
        count = 0; 

        // Iterate through all nodes to find connected components
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue; // Skip already visited nodes
            count++; // Increment component count
            mujun = false; // Reset bipartite flag
            int kind = dfs(i, 0); // Perform DFS starting from node i

            // Update counters based on the results of DFS
            if (kind == 1) one++; 
            else if (!mujun) bipartite++; 
        }

        // Calculate the total based on the counts of components
        long total = one * (2 * n - one); 
        total += (count - one) * (count - one); 
        total += bipartite * bipartite; 

        // Output the final result
        System.out.println(total); 
    }

    // Main method to start the program
    public static void main(String[] args) {
        new Thread(null, new Main(), "", 128 * 1024 * 1024).start(); 
    }
}
