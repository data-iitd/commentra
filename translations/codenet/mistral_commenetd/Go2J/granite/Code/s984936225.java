
import java.util.Scanner;

public class s984936225{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int Inf = 1 << 62;
        int[] a = new int[M];
        int[] b = new int[M];
        int[] c = new int[M];
        for (int i = 0; i < M; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = scanner.nextInt();
            c[i] = -c[i];
        }
        int[] dist = new int[N];
        for (int i = 0; i < N; i++) {
            dist[i] = Inf;
        }
        dist[0] = 0;
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
        int ans = dist[N - 1];
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
    }
}
