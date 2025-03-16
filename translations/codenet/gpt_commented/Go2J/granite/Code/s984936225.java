
import java.util.Scanner;

public class s984936225{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int Inf = 1 << 62; // Using a large value for infinity, considering the maximum possible distance
        int[] a = new int[M];
        int[] b = new int[M];
        int[] c = new int[M];
        for (int i = 0; i < M; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = -scanner.nextInt(); // Negate the weights for the algorithm (to handle maximization)
        }
        int[] dist = new int[N];
        for (int i = 0; i < N; i++) {
            dist[i] = Inf; // Set all distances to infinity initially
        }
        dist[0] = 0; // The starting vertex (0) has a distance of 0
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                }
            }
        }
        int ans = dist[N - 1]; // The answer is the distance to the last vertex
        boolean[] navigate = new boolean[N]; // Array to track reachable vertices
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                    navigate[b[i] - 1] = true; // Mark b[i] as reachable
                }
                if (navigate[a[i] - 1]) {
                    navigate[b[i] - 1] = true;
                }
            }
        }
        if (navigate[N - 1]) {
            System.out.println("inf"); // If the last vertex is reachable, print "inf" (indicating a negative cycle)
        } else {
            System.out.println(-ans); // Otherwise, print the negative of the answer (since weights were negated)
        }
    }
}
