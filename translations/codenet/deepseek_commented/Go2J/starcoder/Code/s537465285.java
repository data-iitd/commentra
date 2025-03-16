import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    try {
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
      int N = Integer.parseInt(reader.readLine());
      String[] S = new String[N];
      for (int i = 0; i < N; i++) {
        S[i] = reader.readLine();
      }
      if (!bipartite(S)) {
        writer.write("-1");
      } else {
        writer.write(Integer.toString(warshallFloyd(S)));
      }
      writer.flush();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  // Checks if a graph is bipartite
  public static boolean bipartite(String[] S) {
    int N = S.length;
    int[] D = new int[N]; // Distance array
    D[0] = 1; // Start from the first vertex
    Queue<Integer> Q = new LinkedList<Integer>();
    Q.add(0);
    boolean ret = true; // Return value
    while (!Q.isEmpty()) {
      int q = Q.poll();
      for (int j = 0; j < N; j++) {
        if (!ret) { break; }
        if (D[j] == 0 && S[q].charAt(j) == '0') {
          D[j] = D[q] + 1;
          Q.add(j);
          continue;
        }
        if (D[j]!= 0 && D[j] % 2 == D[q] % 2 && S[q].charAt(j) == '0') {
          ret = false;
          break;
        }
      }
    }
    return ret;
  }

  // Computes the shortest paths between all pairs of vertices
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

