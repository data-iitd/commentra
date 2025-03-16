
import java.util.*;

public class BellmanFord {
  public static void main(String[] args) {
    int V, E, r; // V: number of vertices, E: number of edges, r: source vertex

    // Read input
    Scanner in = new Scanner(System.in);
    V = in.nextInt();
    E = in.nextInt();
    r = in.nextInt();

    // Initialize edges vector
    ArrayList<Edge> edges = new ArrayList<Edge>();
    for (int i = 0; i < E; i++) {
      int source, target, distance;
      source = in.nextInt();
      target = in.nextInt();
      distance = in.nextInt();
      Edge new_edge = new Edge(source, target, distance);
      edges.add(new_edge);
    }

    // Initialize distances array with maximum value
    int[] distances = new int[V];
    for (int i = 0; i < V; i++) {
      distances[i] = Integer.MAX_VALUE; // max value
    }

    // Set initial distance of source vertex to 0
    distances[r] = 0;

    // Bellman-Ford algorithm
    for (int i = 1; i < V; i++) {
      // Update distances for all vertices
      for (int j = 0; j < edges.size(); j++) {
	Edge edge = edges.get(j);
	int new_distance = distances[edge.source] + edge.weight;
	if (new_distance < distances[edge.target]) {
	  distances[edge.target] = new_distance;
	}
      }
    }

    // Print results
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
  int weight;

  public Edge(int source, int target, int weight) {
    this.source = source;
    this.target = target;
    this.weight = weight;
  }
}

