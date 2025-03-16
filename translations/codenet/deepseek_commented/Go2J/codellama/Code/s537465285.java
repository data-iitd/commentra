
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {
  // Reader for input
  static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

  // NextLine reads a line of input
  static String NextLine() throws IOException {
    String line = reader.readLine();
    return line;
  }

  // NextInt reads an integer from input
  static int NextInt() throws IOException {
    String line = reader.readLine();
    return Integer.parseInt(line);
  }

  // Bipartite checks if a graph is bipartite
  static boolean Bipartite(String[] S) {
    int N = S.length;
    int[] D = new int[N]; // Distance array
    D[0] = 1; // Start from the first vertex
    int[] Q = new int[N]; // Queue for BFS
    boolean ret = true; // Return value
    int pos = 1; // Position in the queue
    for (int i = 0; i < N; i++) {
      if (!ret) { break; }
      int q = Q[i];
      for (int j = 0; j < N; j++) {
        if (S[q].charAt(j) == '0') {
          continue;
        }
        if (D[j] == 0) {
          D[j] = D[q] + 1;
          Q[pos] = j;
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
  static int WarshallFloyd(String[] S) {
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

  // Main function to execute the program
  public static void main(String[] args) throws IOException {
    int N = NextInt();
    String[] S = new String[N];
    for (int i = 0; i < N; i++) {
      S[i] = NextLine();
    }
    if (!Bipartite(S)) {
      System.out.println(-1); // If not bipartite, write -1
    } else {
      System.out.println(WarshallFloyd(S)); // Otherwise, compute and write the result
    }
  }
}

