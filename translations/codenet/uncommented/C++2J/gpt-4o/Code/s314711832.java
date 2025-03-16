import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Edge {
    int source;
    int target;
    int weight;

    Edge(int source, int target, int weight) {
        this.source = source;
        this.target = target;
        this.weight = weight;
    }
}

public class Main {
    static final int INF = 1000000001;
    static final int N = 100000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Edge> edges = new ArrayList<>();

        int V = scanner.nextInt();
        int E = scanner.nextInt();
        int r = scanner.nextInt();

        for (int i = 0; i < E; i++) {
            int source = scanner.nextInt();
            int target = scanner.nextInt();
            int distance = scanner.nextInt();
            edges.add(new Edge(source, target, distance));
        }

        int[] distances = new int[N];
        int[] prevDistances = new int[N];

        // Initialize distances array
        for (int i = 0; i < N; i++) {
            distances[i] = INF; // max value
        }

        distances[r] = 0;

        for (int i = 1; i < V; i++) {
            System.arraycopy(distances, 0, prevDistances, 0, V);

            for (Edge edge : edges) {
                distances[edge.target] = Math.min(distances[edge.source] + edge.weight, distances[edge.target]);
            }

            boolean same = true;
            for (int j = 0; j < V; j++) {
                if (distances[j] != prevDistances[j]) {
                    same = false;
                    break;
                }
            }

            if (same) break;
        }

        for (int i = 0; i < V; i++) {
            if (distances[i] == INF) {
                System.out.println("INF");
            } else {
                System.out.println(distances[i]);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
