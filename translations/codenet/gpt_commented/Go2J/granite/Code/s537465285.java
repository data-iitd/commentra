
import java.io.*;
import java.util.*;

public class s537465285{
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    String[] S = new String[N];
    for (int i = 0; i < N; i++) {
      S[i] = br.readLine();
    }
    
    // Check if the graph is bipartite and process accordingly
    if (!bipartite(S)) {
      System.out.println(-1); // Output -1 if not bipartite
    } else {
      System.out.println(warshallFloyd(S)); // Output the longest shortest path if bipartite
    }
  }
  
  // Function to check if the graph is bipartite
  public static boolean bipartite(String[] S) {
    int N = S.length; // Get the number of nodes
    int[] D = new int[N]; // Distance array to store levels of nodes
    D[0] = 1; // Start with the first node at level 1
    Queue<Integer> q = new LinkedList<>(); // Queue for BFS
    q.add(0); // Add the first node to the queue
    boolean ret = true; // Variable to track if the graph is bipartite
    
    // Perform BFS to check for bipartiteness
    while (!q.isEmpty()) {
      int i = q.poll(); // Current node
      for (int j = 0; j < N; j++) {
        if (S[i].charAt(j) == '0') {
          continue; // Skip if there is no edge
        }
        if (D[j] == 0) {
          // Assign level to the adjacent node
          D[j] = D[i] + 1;
          q.add(j); // Add to queue
          continue;
        }
        // Check if the adjacent node has the same level
        if (D[j] % 2 == D[i] % 2) {
          ret = false; // Not bipartite
          break;
        }
      }
    }
    return ret; // Return the result of bipartiteness check
  }
  
  // Function to perform the Floyd-Warshall algorithm to find the longest shortest path
  public static int warshallFloyd(String[] S) {
    int N = S.length; // Get the number of nodes
    int[][] G = new int[N][N]; // Initialize the graph matrix
    
    // Initialize the graph with distances
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) { continue; } // Skip self-loops
        if (S[i].charAt(j) == '0') {
          G[i][j] = N; // No edge, set to a large value
        } else {
          G[i][j] = 1; // Edge exists, set distance to 1
        }
      }
    }
    
    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (G[i][k] + G[k][j] < G[i][j]) {
            G[i][j] = G[i][k] + G[k][j]; // Update shortest path
          }
        }
      }
    }
    
    // Find the maximum distance in the graph
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (ans < G[i][j]) { ans = G[i][j]; } // Update maximum distance
      }
    }
    return ans + 1; // Return the maximum distance found
  }
}

