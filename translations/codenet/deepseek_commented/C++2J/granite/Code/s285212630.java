
// Import necessary libraries for input/output, data manipulation, and other functionalities
import java.io.*;
import java.util.*;

// Define constants and data structures
public class s285212630{
  static final int MAX_L = 22;
  static final int MOD = 1000000007;
  static final long INF = 1145141919;
  static int N;
  static ArrayList<P>[] G;
  static int[][] U;
  static int[] R;
  static long[] L;

  // Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
  static void dfs(int x, int p, int r, long l) {
    U[0][x] = p;
    R[x] = r;
    L[x] = l;
    for (P pp : G[x]) {
      int t = pp._1;
      if (t == p) continue;
      dfs(t, x, r+1, l+pp._2);
    }
  }

  // Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
  static int lca(int a, int b) {
    if (R[a] > R[b]) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    for (int k=0; k<MAX_L; k++) {
      if ((R[a] - R[b]) >> k & 1) b = U[k][b];
    }
    if (a == b) return a;
    for (int k=MAX_L-1; k>=0; k--) {
      if (U[k][a]!= U[k][b]) {
        a = U[k][a];
        b = U[k][b];
      }
    }
    return U[0][a];
  }

  // Distance calculation function to find the distance between two nodes
  static long dist(int x, int y) {
    int g = lca(x, y);
    return L[x] + L[y] - 2L*L[g];
  }

  // s285212630 function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] line = br.readLine().split(" ");
    N = Integer.parseInt(line[0]);
    G = new ArrayList[N];
    for (int i=0; i<N; i++) G[i] = new ArrayList<>();
    for (int i=0; i<N-1; i++) {
      line = br.readLine().split(" ");
      int a = Integer.parseInt(line[0])-1;
      int b = Integer.parseInt(line[1])-1;
      int c = Integer.parseInt(line[2]);
      G[a].add(new P(b, c));
      G[b].add(new P(a, c));
    }
    U = new int[MAX_L][N];
    for (int i=0; i<MAX_L; i++) Arrays.fill(U[i], -1);
    R = new int[N];
    L = new long[N];
    dfs(0, -1, 0, 0);
    for (int i=0; i<MAX_L-1; i++) {
      for (int v=0; v<N; v++) {
        if (U[i][v] == -1) U[i+1][v] = -1;
        U[i+1][v] = U[i][U[i][v]];
      }
    }
    line = br.readLine().split(" ");
    int Q = Integer.parseInt(line[0]);
    int K = Integer.parseInt(line[1])-1;
    for (int i=0; i<Q; i++) {
      line = br.readLine().split(" ");
      int x = Integer.parseInt(line[0])-1;
      int y = Integer.parseInt(line[1])-1;
      System.out.println(dist(x, K) + dist(K, y));
    }
    System.out.println("