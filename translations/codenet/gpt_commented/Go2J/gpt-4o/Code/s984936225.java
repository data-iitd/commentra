import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // Number of vertices
        int M = scanner.nextInt(); // Number of edges

        long Inf = Long.MAX_VALUE; // Using a large value for infinity
        int[] a = new int[M]; // Array to store the starting vertices of edges
        int[] b = new int[M]; // Array to store the ending vertices of edges
        long[] c = new long[M]; // Array to store the weights of edges

        // Read the edges and their weights from input
        for (int i = 0; i < M; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = -scanner.nextInt(); // Negate the weights for the algorithm (to handle maximization)
        }

        long[] dist = new long[N]; // Array to store the minimum cost to reach each vertex
        for (int i = 0; i < N; i++) {
            dist[i] = Inf; // Set all distances to infinity initially
        }
        dist[0] = 0; // The starting vertex (0) has a distance of 0

        // Relax edges N times to find the shortest paths
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                // Skip if the starting vertex distance is infinity (not reachable)
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                // If a shorter path to vertex b[i] is found, update the distance
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i]; // Update the distance to b[i]
                }
            }
        }

        long ans = dist[N - 1]; // The answer is the distance to the last vertex
        boolean[] navigate = new boolean[N]; // Array to track reachable vertices

        // Check for negative cycles and update reachable vertices
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                // Skip if the starting vertex distance is infinity (not reachable)
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                // If a shorter path to vertex b[i] is found, update the distance and mark it as reachable
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                    navigate[b[i] - 1] = true; // Mark b[i] as reachable
                }
                // If a[i] is reachable, then b[i] is also reachable
                if (navigate[a[i] - 1]) {
                    navigate[b[i] - 1] = true;
                }
            }
        }

        // Output the result based on the reachability of the last vertex
        if (navigate[N - 1]) {
            System.out.println("inf"); // If the last vertex is reachable, print "inf" (indicating a negative cycle)
        } else {
            System.out.println(-ans); // Otherwise, print the negative of the answer (since weights were negated)
        }

        scanner.close();
    }
}
// <END-OF-CODE>
