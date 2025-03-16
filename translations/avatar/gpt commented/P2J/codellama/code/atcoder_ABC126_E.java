
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

// Class to represent a graph
class Graph {
    // Number of nodes in the graph
    private int N;
    
    // Adjacency list to represent the graph
    private LinkedList<Integer>[] edge;
    
    // Constructor to create a graph with N nodes
    public Graph(int N) {
        this.N = N;
        edge = new LinkedList[N];
        for (int i = 0; i < N; i++) {
            edge[i] = new LinkedList<>();
        }
    }
    
    // Function to add an edge between two nodes
    public void addEdge(int X, int Y) {
        edge[X].add(Y);
        edge[Y].add(X);
    }
    
    // Function to find the number of connected components in the graph
    public int findConnectedComponents() {
        // Array to track visited nodes
        boolean[] used = new boolean[N];
        
        // Variable to count the number of connected components
        int ans = 0;
        
        // Iterate through each node to find connected components
        for (int i = 0; i < N; i++) {
            if (!used[i]) {  // If the node has not been visited
                ans++;  // Increment the count of connected components
                Queue<Integer> queue = new LinkedList<>();  // Initialize a queue for BFS
                queue.add(i);  // Start BFS from the current node
                
                // Perform BFS to mark all reachable nodes from the current node
                while (!queue.isEmpty()) {
                    int node = queue.remove();  // Dequeue a node
                    used[node] = true;  // Mark the node as visited
                    
                    // Explore all adjacent nodes
                    for (int nextnode : edge[node]) {
                        if (!used[nextnode]) {  // If the adjacent node has not been visited
                            queue.add(nextnode);  // Enqueue the adjacent node
                        }
                    }
                }
            }
        }
        
        // Return the number of connected components found
        return ans;
    }
}

// Main class
public class Main {
    // Function to read input from standard input
    public static String input() {
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }
    
    // Main function
    public static void main(String[] args) {
        // Read the number of nodes (N) and edges (M)
        String[] tokens = input().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);
        
        // Initialize a graph with N nodes
        Graph graph = new Graph(N);
        
        // Read each edge and populate the graph
        for (int i = 0; i < M; i++) {
            tokens = input().split(" ");
            int X = Integer.parseInt(tokens[0]) - 1;
            int Y = Integer.parseInt(tokens[1]) - 1;
            int Z = Integer.parseInt(tokens[2]);
            graph.addEdge(X, Y);
        }
        
        // Find the number of connected components in the graph
        int ans = graph.findConnectedComponents();
        
        // Output the number of connected components found
        System.out.println(ans);
    }
}

// End of code
