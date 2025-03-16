
import java.io.*;
import java.util.*;

class s537465285 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    String[] S = new String[N];
    for (int i = 0; i < N; i++) {
      S[i] = br.readLine();
    }
    boolean bipartite = true;
    int[] D = new int[N];
    D[0] = 1;
    Queue<Integer> Q = new LinkedList<>();
    Q.add(0);
    while (!Q.isEmpty()) {
      int q = Q.poll();
      for (int j = 0; j < N; j++) {
        if (S[q].charAt(j) == '0') {
          continue;
        }
        if (D[j] == 0) {
          D[j] = D[q] + 1;
          Q.add(j);
          continue;
        }
        if (D[j] % 2 == D[q] % 2) {
          bipartite = false;
          break;
        }
      }
      if (!bipartite) {
        break;
      }
    }
    int ans = 0;
    if (bipartite) {
      int[][] G = new int[N][N];
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (i == j) {
            continue;
          }
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
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          ans = Math.max(ans, G[i][j]);
        }
      }
      ans++;
    }
    System.out.println(bipartite? ans : -1);
  }
}

Translate the above Java code to C++ and end with comment "