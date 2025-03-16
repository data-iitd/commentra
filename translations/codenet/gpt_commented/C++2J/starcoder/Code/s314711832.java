import java.util.*;

public class ShortestPath {
  public static void main(String[] args) {
    int V, E, r; // Variables for number of vertices, edges, and the source vertex

    // Read the number of vertices, edges, and the source vertex from input
    Scanner sc = new Scanner(System.in);
    V = sc.nextInt();
    E = sc.nextInt();
    r = sc.nextInt();

    // Read all edges from input and store them in the edges vector
    ArrayList<Edge> edges = new ArrayList<Edge>();
    for (int i = 0; i < E; i++) {
      int source, target, distance; // Variables to hold edge data
      source = sc.nextInt();
      target = sc.nextInt();
      distance = sc.nextInt();
      Edge new_edge = new Edge(source, target, distance); // Create a new edge
      edges.add(new_edge); // Add the new edge to the edges vector
    }

    // Initialize distances array to infinity for all vertices
    int[] distances = new int[V];
    for (int i = 0; i < V; i++) {
      distances[i] = Integer.MAX_VALUE; // Set all distances to a maximum value (infinity)
    }

    distances[r] = 0; // Set the distance to the source vertex to 0

    // Main loop to relax edges V-1 times
    for (int i = 1; i < V; i++) {
      // Relax all edges
      for (int j = 0; j < edges.size(); j++) {
        // Update the distance to the target vertex if a shorter path is found
        Edge edge = edges.get(j);
        distances[edge.target] = Math.min(distances[edge.source] + edge.weight, distances[edge.target]);
      }
    }

    // Output the shortest distances from the source vertex to all other vertices
    for (int i = 0; i < V; i++) {
      if (distances[i] == Integer.MAX_VALUE) {
        System.out.println("INF"); // Print "INF" if the vertex is unreachable
      } else {
        System.out.println(distances[i]); // Print the shortest distance
      }
    }
  }
}

class Edge {
  int source; // Source vertex of the edge
  int target; // Target vertex of the edge
  int weight; // Weight of the edge

  public Edge(int source, int target, int weight) {
    this.source = source;
    this.target = target;
    this.weight = weight;
  }
}

