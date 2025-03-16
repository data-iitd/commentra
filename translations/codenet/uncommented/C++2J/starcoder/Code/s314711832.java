
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int V = in.nextInt();
    int E = in.nextInt();
    int r = in.nextInt();

    int[] distances = new int[V];
    Arrays.fill(distances, Integer.MAX_VALUE);
    distances[r] = 0;

    for (int i = 0; i < E; i++) {
      int source = in.nextInt();
      int target = in.nextInt();
      int distance = in.nextInt();
      if (distances[source] + distance < distances[target]) {
	distances[target] = distances[source] + distance;
      }
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

