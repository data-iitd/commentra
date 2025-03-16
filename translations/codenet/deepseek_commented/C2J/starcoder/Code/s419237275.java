import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n, A[][] = new int[N][N];  // n: number of nodes, A: adjacency matrix
    int color[] = new int[N], d[] = new int[N], f[] = new int[N];  // color: color of each node, d: discovery time, f: finish time
    int TT;  // Time counter

    // Read the number of nodes
    Scanner in = new Scanner(System.in);
    n = in.nextInt();

    // Initialize the adjacency matrix to zero
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        A[i][j] = 0;
      }
    }

    // Read the edges for each node and update the adjacency matrix
    for (int i = 0; i < n; i++) {
      int u, k;
      u = in.nextInt();
      k = in.nextInt();
      u--;  // Adjust for 0-based indexing
      for (int j = 0; j < k; j++) {
        int v;
        v = in.nextInt();
        v--;  // Adjust for 0-based indexing
        A[u][v] = 1;
      }
    }

    // Perform DFS and print the results
    aaaaa();

    return 0;
  }

  // Depth-First Search (DFS) function
  public static void aaaaa() {
    int u, i;  // u: current node, i: loop variable

    // Initialize all nodes to "SHIRO" (unvisited)
    for (i = 0; i < n; i++) {
      color[i] = SHIRO;
    }

    // Set the time counter to zero
    TT = 0;

    // Iterate over all nodes and perform DFS if the node is "SHIRO"
    for (u = 0; u < n; u++) {
      if (color[u] == SHIRO) {
        bbbbb(u);
      }
    }

    // Print the discovery and finish times for each node
    for (i = 0; i < n; i++) {
      System.out.printf("%d %d %d\n", i + 1, d[i], f[i]);
    }
  }

  // Recursive DFS function
  public static void bbbbb(int k) {
    int v;  // v: adjacent node

    // Set the current node's color to "HAI" (currently in the recursion stack)
    color[k] = HAI;
    // Increment the time counter and record the discovery time
    TT++;
    d[k] = TT;

    // Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
    for (v = 0; v < n; v++) {
      if (A[k][v] == 0) continue;  // Skip if no edge between k and v
      if (color[v] == SHIRO) {
        bbbbb(v);
      }
    }

    // Set the current node's color to "KURO" (fully processed)
    color[k] = KURO;
    // Record the finish time
    f[k] = ++TT;
  }
}

