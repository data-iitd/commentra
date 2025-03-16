// Include necessary headers for input/output, data manipulation, and other functionalities
import java.io.*;
import java.util.*;

// Define constants and data structures
class P {
  int _1, _2;
  P(int _1, int _2) {
    this._1 = _1;
    this._2 = _2;
  }
}

// Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
void dfs(int x, int p, int r, long long l) {
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
int lca(int a, int b) {
  if (R[a] > R[b]) swap(a, b);
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
long long dist(int x, int y) {
  int g = lca(x, y);
  return L[x] + L[y] - 2LL*L[g];
}

// Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  int N = sc.nextInt();
  G = new ArrayList[N];
  for (int i=0; i<N; i++) G[i] = new ArrayList<P>();
  rep(i, N-1) {
    int a = sc.nextInt()-1;
    int b = sc.nextInt()-1;
    int c = sc.nextInt();
    G[a].add(new P(b, c));
    G[b].add(new P(a, c));
  }
  rep(i, MAX_L) rep(j, N) U[i][j] = -1;
  dfs(0, -1, 0, 0);
  for (int i=0; i<MAX_L-1; i++) {
    for (int v=0; v<N; v++) {
      if (U[i][v] == -1) U[i+1][v] = -1;
      U[i+1][v] = U[i][U[i][v]];
    }
  }
  int Q = sc.nextInt();
  int K = sc.nextInt()-1;
  rep(i, Q) {
    int x = sc.nextInt()-1;
    int y = sc.nextInt()-1;
    System.out.println(dist(x, K) + dist(K, y));
  }
}

