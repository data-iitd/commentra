
import java.util.*;

public class s314711832{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int V = sc.nextInt();
    int E = sc.nextInt();
    int r = sc.nextInt();

    List<Edge> edges = new ArrayList<>();
    for (int i = 0; i < E; i++) {
      int source = sc.nextInt();
      int target = sc.nextInt();
      int distance = sc.nextInt();
      Edge edge = new Edge(source, target, distance);
      edges.add(edge);
    }

    int[] distances = new int[V];
    Arrays.fill(distances, Integer.MAX_VALUE);
    distances[r] = 0;

    for (int i = 1; i < V; i++) {
      int[] prevDistances = distances.clone();
      for (Edge edge : edges) {
        int source = edge.source;
        int target = edge.target;
        int distance = edge.distance;
        distances[target] = Math.min(distances[source] + distance, distances[target]);
      }
      boolean same = true;
      for (int j = 0; j < V; j++) {
        if (distances[j]!= prevDistances[j]) {
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

class Edge {
  int source;
  int target;
  int distance;

  public Edge(int source, int target, int distance) {
    this.source = source;
    this.target = target;
    this.distance = distance;
  }
}

