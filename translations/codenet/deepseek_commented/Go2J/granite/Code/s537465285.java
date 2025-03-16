
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
    if (!bipartite(S)) {
      System.out.println(-1); // If not bipartite, print -1
    } else {
      System.out.println(warshallFloyd(S)); // Otherwise, compute and print the result
    }
  }

  // Bipartite checks if a graph is bipartite
  public static boolean bipartite(String[] S) {
    int N = S.length;
    int[] D = new int[N]; // Distance array
    D[0] = 1; // Start from the first vertex
    Queue<Integer> Q = new LinkedList<>(); // Queue for BFS
    boolean ret = true; // Return value
    int pos = 1; // Position in the queue
    for (int i = 0; i < N; i++) {
      if (!ret) { break; }
      int q = Q.poll();
      for (int j = 0; j < N; j++) {
        if (S[q].charAt(j) == '0') {
          continue;
        }
        if (D[j] == 0) {
          D[j] = D[q] + 1;
          Q.add(j);
          pos++;
          continue;
        }
        if (D[j] % 2 == D[q] % 2) {
          ret = false;
          break;
        }
      }
    }
    return ret;
  }

  // WarshallFloyd computes the shortest paths between all pairs of vertices
  public static int warshallFloyd(String[] S) {
    int N = S.length;
    int[][] G = new int[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) { continue; }
        if (S[i].charAt(j) == '0') {
          G[i][j] = N; // Set distance to a large number
        } else {
          G[i][j] = 1; // Direct edge weight
        }
      }
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (G[i][k] + G[k][j] < G[i][j]) {
            G[i][j] = G[i][k] + G[k][j]; // Update shortest path
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (ans < G[i][j]) { ans = G[i][j]; } // Find the maximum distance
      }
    }
    return ans + 1; // Return the result
  }
}

// End of code