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

  public static boolean bipartite(String[] S) {
    int N = S.length;
    int[] D = new int[N];
    D[0] = 1;
    int[] Q = new int[N];
    boolean ret = true;
    int pos = 1;
    for (int i = 0; i < N; i++) {
      if (!ret) { break; }
      int q = Q[i];
      for (int j = 0; j < S[q].length(); j++) {
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

  public static int warshallFloyd(String[] S) {
    int N = S.length;
    int[][] G = new int[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) { continue; }
        if (S[i].charAt(j) == '0') {
          G[i][j] = N;
        } else {
          G[i][j] = 1;
        }
      }
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (G[i][k] + G[k][j] < G[i][j]) {
            G[i][j] = G[i][k] + G[k][j];
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (ans < G[i][j]) { ans = G[i][j]; }
      }
    }
    return ans + 1;
  }
}

