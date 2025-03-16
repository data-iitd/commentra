import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long Inf = 1L << 62;
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        int[] a = new int[M];
        int[] b = new int[M];
        long[] c = new long[M];
        
        for (int i = 0; i < M; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = -scanner.nextInt();
        }
        
        long[] dist = new long[N];
        for (int i = 0; i < N; i++) {
            dist[i] = Inf; // Initialize distances to a large value
        }
        dist[0] = 0; // Starting point
        
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
        
        long ans = dist[N - 1]; // Minimum distance to the last node
        boolean[] navigate = new boolean[N];
        
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == Inf) {
                    continue;
                }
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                    navigate[b[i] - 1] = true;
                }
                if (navigate[a[i] - 1]) {
                    navigate[b[i] - 1] = true;
                }
            }
        }
        
        if (navigate[N - 1]) {
            System.out.println("inf");
        } else {
            System.out.println(-ans);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
