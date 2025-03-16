
import java.util.*;

public class s772335512{
    // Declare a graph represented as an adjacency list
    static ArrayList<Integer>[] G;
    // Array to track visited nodes during DFS
    static boolean[] used;
    // Array to store the Grundy values for each node
    static int[] grundy;

    // Depth-First Search (DFS) function to compute Grundy values
    static void dfs(int v){
        // Mark the current node as visited
        used[v] = true;
        // Initialize the Grundy value for the current node
        grundy[v] = 0;
        
        // Iterate through all adjacent nodes
        for(int i = 0; i < G[v].size(); i++){
            // If the adjacent node has not been visited
            if(!used[G[v][i]]){
                // Recursively perform DFS on the adjacent node
                dfs(G[v][i]);
                // Update the Grundy value using the Grundy value of the child node
                grundy[v] ^= (grundy[G[v][i]] + 1);
            }
        }
    }

    public static void main(String[] args) {
        // Read the number of nodes in the graph
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        // Read the edges of the graph
        G = new ArrayList[N];
        for(int i = 0; i < N; i++){
            G[i] = new ArrayList<>();
        }
        for(int i = 0; i < N-1; i++){
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            // Add the edge to the adjacency list
            G[x].add(y);
            G[y].add(x);
        }
        
        // Start DFS from the root node (node 0)
        used = new boolean[N];
        grundy = new int[N];
        dfs(0);
        
        // Determine the winner based on the Grundy value of the root node
        if(grundy[0]!= 0){
            System.out.println("Alice"); // Alice wins if Grundy value is non-zero
        }else{
            System.out.println("Bob");   // Bob wins if Grundy value is zero
        }
    }
}
