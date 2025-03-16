
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
  // Initialize reader and writer
  static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

  // Function to read a single line from standard input
  static String NextLine() {
    String line = "";
    try {
      line = reader.readLine();
    } catch (Exception e) {
      e.printStackTrace();
    }
    return line;
  }

  // Function to read an integer from standard input
  static int NextInt() {
    return Integer.parseInt(NextLine());
  }

  // Function to write a value to standard output
  static void Write(Object s) {
    writer.println(s);
  }

  // Function to flush the writer buffer
  static void Output() {
    writer.flush();
  }

  // Function to check if a given graph is bipartite
  static boolean Bipartite(List<String> S) {
    // Initialize number of vertices
    int N = S.size();

    // Initialize degree array
    int[] D = new int[N];
    D[0] = 1;

    // Initialize queue
    int[] Q = new int[N];

    // Initialize result
    boolean ret = true;

    // Initialize position in queue
    int pos = 1;

    // Iterate over each vertex
    for (int i = 0; i < N; i++) {
      if (!ret) { break; }

      // Get current vertex
      int q = Q[i];

      // Iterate over each neighbor of the current vertex
      for (int j = 0; j < N; j++) {
        if (S.get(q).charAt(j) == '0') {
          continue;
        }

        // If neighbor is not visited yet
        if (D[j] == 0) {
          // Mark neighbor as visited
          D[j] = D[q] + 1;

          // Add neighbor to queue
          Q[pos] = j;
          pos++;

          // Continue to next neighbor
          continue;
        }

        // If degrees of current and neighbor are different
        if (D[j] % 2 != D[q] % 2) {
          // Graph is not bipartite
          ret = false;
          break;
        }
      }
    }

    // Return result
    return ret;
  }

  // Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
  static int WarshallFloyd(List<String> S) {
    // Initialize number of vertices
    int N = S.size();

    // Initialize adjacency matrix
    int[][] G = new int[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) { continue; }
        if (S.get(i).charAt(j) == '0') {
          G[i][j] = N;
        } else {
          G[i][j] = 1;
        }
      }
    }

    // Iterate over all vertices k
    for (int k = 0; k < N; k++) {
      // Iterate over all vertices i
      for (int i = 0; i < N; i++) {
        // Iterate over all vertices j
        for (int j = 0; j < N; j++) {
          // Update shortest distance if found
          if (G[i][k] + G[k][j] < G[i][j]) {
            G[i][j] = G[i][k] + G[k][j];
          }
        }
      }
    }

    // Initialize answer as maximum distance
    int ans = 0;

    // Iterate over all vertices i
    for (int i = 0; i < N; i++) {
      // Iterate over all vertices j
      for (int j = 0; j < N; j++) {
        // Update answer if found
        if (ans < G[i][j]) { ans = G[i][j]; }
      }
    }

    // Return answer plus one
    return ans + 1;
  }

  // Main function
  public static void main(String[] args) {
    // Read number of vertices
    int N = NextInt();

    // Initialize graph
    List<String> S = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      S.add(NextLine());
    }

    // Check if graph is bipartite
    if (!Bipartite(S)) {
      // Write -1 if graph is not bipartite
      Write(-1);
    } else {
      // Write shortest distance between all pairs of vertices
      Write(WarshallFloyd(S));
    }

    // Flush writer buffer
    Output();
  }
}

