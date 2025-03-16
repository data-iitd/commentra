import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[][] G = new int[N][N];
    int[][] U = new int[22][N];
    int[] R = new int[N];
    long[] L = new long[N];
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        G[i][j] = sc.nextInt();
      }
    }
    for (int i=0; i<22; i++) {
      for (int j=0; j<N; j++) {
        U[i][j] = -1;
      }
    }
    dfs(0, -1, 0, 0);
    for (int i=0; i<21; i++) {
      for (int j=0; j<N; j++) {
        if (U[i][j] == -1) U[i+1][j] = -1;
        U[i+1][j] = U[i][U[i][j]];
      }
    }
    int Q = sc.nextInt();
    int K = sc.nextInt();
    K--;
    for (int i=0; i<Q; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      x--;
      y--;
      System.out.println(dist(x, K) + dist(K, y));
    }
  }

  static void dfs(int x, int p, int r, long l) {
    U[0][x] = p;
    R[x] = r;
    L[x] = l;
    for (int i=0; i<N; i++) {
      if (G[x][i] == 0) continue;
      int t = i;
      if (t == p) continue;
      dfs(t, x, r+1, l+G[x][i]);
    }
  }

  static int lca(int a, int b) {
    if (R[a] > R[b]) swap(a, b);
    for (int k=0; k<22; k++) {
      if ((R[a] - R[b]) >> k & 1) b = U[k][b];
    }
    if (a == b) return a;
    for (int k=21; k>=0; k--) {
      if (U[k][a]!= U[k][b]) {
        a = U[k][a];
        b = U[k][b];
      }
    }
    return U[0][a];
  }

  static long dist(int x, int y) {
    int g = lca(x, y);
    return L[x] + L[y] - 2*L[g];
  }
}

