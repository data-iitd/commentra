import java.util.*;
import java.io.*;

// Define long long as int for convenience
// Define long long as int for convenience
#define int long long

// Macros for loop and container operations
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back

// Constants for maximum levels, infinity, and modulo
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22

// Global variables
int N; // Number of nodes in the tree
ArrayList<P> G[100000]; // Adjacency list representation of the tree
int U[MAX_L][100000], R[100000]; // U for storing ancestors, R for depth
long long L[100000]; // L for storing the distance from the root

// Depth-first search to initialize ancestor and depth information
void dfs(int x, int p, int r, long long l) {
  U[0][x] = p; // Set the parent of the current node
  R[x] = r; // Set the depth of the current node
  L[x] = l; // Set the distance from the root to the current node
  for (P pp : G[x]) { // Iterate through all adjacent nodes
    int t = pp._1; // Get the adjacent node
    if (t == p) continue; // Skip the parent node to avoid cycles
    dfs(t, x, r+1, l+pp._2); // Recursive DFS call for the child node
  }
}

// Function to find the lowest common ancestor (LCA) of two nodes
int lca(int a, int b) {
  if (R[a] > R[b]) swap(a, b); // Ensure a is the deeper node
  for (int k=0; k<MAX_L; k++) { // Adjust b to the same depth as a
    if ((R[a] - R[b]) >> k & 1) b = U[k][b];
  }
  if (a == b) return a; // If both nodes are the same, return a
  for (int k=MAX_L-1; k>=0; k--) { // Find the LCA using binary lifting
    if (U[k][a]!= U[k][b]) {
      a = U[k][a];
      b = U[k][b];
    }
  }
  return U[0][a]; // Return the parent of a, which is the LCA
}

// Function to calculate the distance between two nodes
long long dist(int x, int y) {
  int g = lca(x, y); // Find the LCA of x and y
  return L[x] + L[y] - 2LL*L[g]; // Calculate the distance using LCA
}

public class Main {
  public static void main(String[] args) {
    // Optimize input/output
    Scanner sc = new Scanner(System.in);
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    int N; // Number of nodes in the tree
    ArrayList<P> G[100000]; // Adjacency list representation of the tree
    int U[MAX_L][100000], R[100000]; // U for storing ancestors, R for depth
    long long L[100000]; // L for storing the distance from the root
    
    // Read the number of nodes
    N = sc.nextInt();
    
    // Read the edges of the tree
    rep(i, N-1) {
      int a, b, c;
      a = sc.nextInt();
      b = sc.nextInt();
      c = sc.nextInt();
      a--; b--; // Convert to 0-based indexing
      G[a].add(new P(b, c)); // Add edge to the adjacency list
      G[b].add(new P(a, c)); // Add the reverse edge
    }
    
    // Initialize the ancestor table with -1
    rep(i, MAX_L) rep(j, N) U[i][j] = -1;
    
    // Perform DFS from the root to fill ancestor and depth information
    dfs(0, -1, 0, 0);
    
    // Precompute ancestors for binary lifting
    for (int i=0; i<MAX_L-1; i++) {
      for (int v=0; v<N; v++) {
        if (U[i][v] == -1) U[i+1][v] = -1; // If no ancestor, set to -1
        U[i+1][v] = U[i][U[i][v]]; // Set the 2^(i+1) ancestor
      }
    }
    
    int Q, K; // Number of queries and a specific node K
    Q = sc.nextInt();
    K = sc.nextInt();
    K--; // Convert K to 0-based indexing
    
    // Process each query
    rep(i, Q) {
      int x, y; // Nodes for which distance is to be calculated
      x = sc.nextInt();
      y = sc.nextInt();
      x--; y--; // Convert to 0-based indexing
      // Output the total distance from x to K and K to y
      bw.write(dist(x, K) + dist(K, y) + "\n");
    }
    
    bw.close();
    sc.close();
  }
}

