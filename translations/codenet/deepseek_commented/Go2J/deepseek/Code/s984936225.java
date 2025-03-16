import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of vertices (N)
        int M = scanner.nextInt(); // Read the number of edges (M)

        long Inf = (long) Math.pow(2, 62); // Set Inf to 2^62, representing a large number
        int[] a = new int[M];
        int[] b = new int[M];
        long[] c = new long[M];
        for (int i = 0; i < M; i++) {
            a[i] = scanner.nextInt(); // Read the start vertex
            b[i] = scanner.nextInt(); // Read the end vertex
            c[i] = -scanner.nextLong(); // Read the cost of the edge and negate it
        }

        long[] dist = new long[N]; // Initialize the dist array to store the minimum cost to reach each vertex
        for (int i = 0; i < N; i++) {
            dist[i] = Inf; // Set initial distances to Inf except for the starting vertex (0)
        }
        dist[0] = 0; // The starting vertex has a cost of 0

        // Bellman-Ford Algorithm
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == Inf) {
                    continue; // Skip if the start vertex is at infinite distance
                }
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    // Update the distance if a shorter path is found
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                }
            }
        }

        long ans = dist[N - 1]; // The minimum cost to reach the last vertex
        boolean[] navigate = new boolean[N];

        // Negative Cycle Detection
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == Inf) {
                    continue; // Skip if the start vertex is at infinite distance
                }
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                    navigate[b[i] - 1] = true; // Mark the end vertex as part of a negative cycle
                }
                if (navigate[a[i] - 1]) {
                    navigate[b[i] - 1] = true; // Propagate the negative cycle
                }
            }
        }

        if (navigate[N - 1]) {
            System.out.println("inf"); // Print "inf" if a negative cycle is detected
        } else {
            System.out.println(-ans); // Print the negative of the minimum cost to reach the last vertex
        }
    }
}
