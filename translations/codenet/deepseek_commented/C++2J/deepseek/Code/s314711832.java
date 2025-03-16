import java.util.*;

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
        int V = scanner.nextInt();
        int E = scanner.nextInt();
        int r = scanner.nextInt();

        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < E; i++) {
            int source = scanner.nextInt();
            int target = scanner.nextInt();
            int weight = scanner.nextInt();
            edges.add(new Edge(source, target, weight));
        }

        int[] distances = new int[N];
        int[] prevDistances = new int[N];

        Arrays.fill(distances, INF);
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
    }
}
