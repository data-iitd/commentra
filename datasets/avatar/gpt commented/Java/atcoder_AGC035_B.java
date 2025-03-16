import java.util.*; 

public class Main { 
    @SuppressWarnings("unchecked") 
    public static void main(String[] args) { 
        // Initialize scanner to read input
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of nodes and edges from input
        int numNode = sc.nextInt(); 
        int numEdge = sc.nextInt(); 
        
        // Create an adjacency list to represent the graph
        connect = new ArrayList[numNode]; 
        for (int i = 0; i < numNode; i++) { 
            connect[i] = new ArrayList<>(); // Initialize each list in the adjacency list
        } 
        
        // Read edges and populate the adjacency list
        for (int i = 0; i < numEdge; i++) { 
            int a = sc.nextInt() - 1; // Read first node of the edge (0-indexed)
            int b = sc.nextInt() - 1; // Read second node of the edge (0-indexed)
            connect[a].add(b); // Add edge in both directions (undirected graph)
            connect[b].add(a); 
        } 
        
        // Check if the number of edges is odd; if so, output -1 and exit
        if (numEdge % 2 != 0) { 
            System.out.println(-1); 
            return; 
        } 
        
        // Initialize arrays for tracking visited nodes and odd/even connections
        visited = new int[numNode]; 
        odd = new boolean[numNode]; 
        print = new StringBuilder(); // StringBuilder to accumulate output
        
        // Perform depth-first search starting from node 0
        dfs(0, -1); 
        
        // Output the result
        System.out.println(print); 
    } 
    
    // Declare global variables for the graph representation and state tracking
    static ArrayList<Integer> connect[]; 
    static int visited[]; 
    static boolean odd[]; 
    static StringBuilder print; 
    
    // Depth-first search method to explore the graph
    static void dfs(int crt, int parent) { 
        visited[crt] = 1; // Mark the current node as visited
        ArrayList<Integer> crtConnect = connect[crt]; // Get the current node's connections
        
        // Iterate through each child node connected to the current node
        for (int child : crtConnect) { 
            // Skip the parent node and already visited nodes
            if (child == parent || visited[child] == 1) { 
                continue; 
            } else if (visited[child] == 2) { 
                // If the child has been fully processed, append the edge to output
                print.append((crt + 1) + " " + (child + 1) + "\n"); 
                odd[crt] = !odd[crt]; // Toggle the odd/even state
            } else { 
                // Recursively call DFS on the child node
                dfs(child, crt); 
                
                // Check the odd/even state of the child node after DFS
                if (odd[child]) { 
                    print.append((child + 1) + " " + (crt + 1) + "\n"); 
                    odd[child] = !odd[child]; // Toggle the state
                } else { 
                    print.append((crt + 1) + " " + (child + 1) + "\n"); 
                    odd[crt] = !odd[crt]; // Toggle the state
                } 
            } 
        } 
        visited[crt] = 2; // Mark the current node as fully processed
    } 
}
