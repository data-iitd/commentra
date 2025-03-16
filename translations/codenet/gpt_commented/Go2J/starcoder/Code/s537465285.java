import java.io.*;
import java.util.*;

public class Main {
  // Initialize buffered reader and writer for input and output
  private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
  private static final BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

  // Function to read the next line from standard input
  private static String nextLine() throws IOException {
    return reader.readLine();
  }

  // Function to read the next integer from standard input
  private static int nextInt() throws IOException {
    return Integer.parseInt(nextLine());
  }

  // Function to write output to standard output
  private static void write(Object object) throws IOException {
    writer.write(object.toString());
    writer.write("\n");
  }

  // Function to flush the buffered writer to output
  private static void output() throws IOException {
    writer.flush();
  }

  // Function to check if the graph is bipartite
  private static boolean bipartite(String[] S) {
    int N = S.length; // Get the number of nodes
    int[] D = new int[N]; // Distance array to store levels of nodes
    D[0] = 1; // Start with the first node at level 1
    Queue<Integer> Q = new LinkedList<Integer>(); // Queue for BFS
    boolean ret = true; // Variable to track if the graph is bipartite
    int pos = 1; // Position in the queue

    // Perform BFS to check for bipartiteness
    for (int i = 0; i < N; i++) {
      if (!ret) { break; } // Exit if already determined not bipartite
      int q = Q.poll(); // Current node
      for (int j = 0; j < N; j++) {
        if (S[q].charAt(j) == '0') {
          continue; // Skip if there is no edge
        }
        if (D[j] == 0) {
          // Assign level to the adjacent node
          D[j] = D[q] + 1;
          Q.offer(j); // Add to queue
          pos++;
          continue;
        }
        // Check if the adjacent node has the same level
        if (D[j] % 2 == D[q] % 2) {
          ret = false; // Not bipartite
          break;
        }
      }
    }
    return ret; // Return the result of bipartiteness check
  }

  // Function to perform the Floyd-Warshall algorithm to find the longest shortest path
  private static int warshallFloyd(String[] S) {
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

  // Main function to execute the program
  public static void main(String[] args) throws IOException {
    int N = nextInt(); // Read the number of nodes
    String[] S = new String[N]; // Initialize the adjacency matrix
    for (int i = 0; i < N; i++) {
      S[i] = nextLine(); // Read each line of the adjacency matrix
    }
    
    // Check if the graph is bipartite and process accordingly
    if (!bipartite(S)) {
      write(-1); // Output -1 if not bipartite
    } else {
      write(warshallFloyd(S)); // Output the longest shortest path if bipartite
    }
    
    output(); // Flush the output
  }
}

