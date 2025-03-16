import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Constants and initializations
        long Inf = 1L << 62;
        // a, b, and c are arrays of size M
        int[] a = new int[M];
        int[] b = new int[M];
        long[] c = new long[M];

        // Read input values for a, b, and c
        for (int i = 0; i < M; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = -scanner.nextInt(); // Set c to its negation
        }

        // Initialize the dist array with the maximum value
        long[] dist = new long[N];
        for (int i = 0; i < N; i++) {
            dist[i] = Inf;
        }
        // Set the initial distance of the source node to 0
        dist[0] = 0;

        // Dijkstra's algorithm loop
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                // Skip if the current node's distance is still the maximum value
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                // Update the distance if the new path is shorter
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                }
            }
        }

        // Calculate the answer
        long ans = dist[N - 1];
        boolean[] navigate = new boolean[N];

        // Dijkstra's algorithm loop (second pass)
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                // Skip if the current node's distance is still the maximum value
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                // Update the distance if the new path is shorter
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                    navigate[b[i] - 1] = true;
                }
                // If the previous node is in the navigate array, set the current node's navigate array value to true
                if (navigate[a[i] - 1]) {
                    navigate[b[i] - 1] = true;
                }
            }
        }

        // Print the result
        if (navigate[N - 1]) {
            System.out.println("inf");
        } else {
            System.out.println(-ans);
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
