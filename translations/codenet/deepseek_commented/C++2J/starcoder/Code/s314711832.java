import java.util.*;

public class Dijkstra {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int V = in.nextInt();
    int E = in.nextInt();
    int r = in.nextInt();

    int[] distances = new int[V];
    int[] prev_distances = new int[V];

    for (int i = 0; i < V; i++) {
      distances[i] = Integer.MAX_VALUE;
      prev_distances[i] = 0;
    }

    distances[r] = 0;

    for (int i = 1; i < V; i++) {
      for (int j=0; j< V; j++) {
	prev_distances[j] = distances[j];  
      }
      
      for (int j=0; j< E; j++) {
	int source = in.nextInt();
	int target = in.nextInt();
	int distance = in.nextInt();
	distances[target] = Math.min(distances[source] + distance, distances[target]);
      }

      boolean same = true;
      for (int j=0; j< V; j++) {
	if (distances[j]!= prev_distances[j]) {
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

