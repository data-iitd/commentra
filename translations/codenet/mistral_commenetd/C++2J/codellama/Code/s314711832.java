
import java.util.Scanner;

public class BellmanFord {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int V = sc.nextInt();
    int E = sc.nextInt();
    int r = sc.nextInt();
    int[][] edges = new int[E][3];
    for (int i = 0; i < E; i++) {
      edges[i][0] = sc.nextInt();
      edges[i][1] = sc.nextInt();
      edges[i][2] = sc.nextInt();
    }
    int[] distances = new int[V];
    for (int i = 0; i < V; i++) {
      distances[i] = Integer.MAX_VALUE;
    }
    distances[r] = 0;
    for (int i = 1; i < V; i++) {
      int[] prev_distances = new int[V];
      for (int j = 0; j < V; j++) {
        prev_distances[j] = distances[j];
      }
      for (int j = 0; j < E; j++) {
        distances[edges[j][1]] = Math.min(distances[edges[j][0]] + edges[j][2], distances[edges[j][1]]);
      }
      boolean same = true;
      for (int j = 0; j < V; j++) {
        if (distances[j] != prev_distances[j]) {
          same = false;
          break;
        }
      }
      if (same) break;
    }
    for (int i = 0; i < V; i++) {
      if (distances[i] == Integer.MAX_VALUE) {
        System.out.println("INF");
      } else {
        System.out.println(distances[i]);
      }
    }
  }
}

