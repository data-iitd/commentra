import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int INF = 1 << 62;
        int[] a = new int[M];
        int[] b = new int[M];
        int[] c = new int[M];
        for (int i = 0; i < M; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = -sc.nextInt();
        }
        int[] dist = new int[N];
        Arrays.fill(dist, INF);
        dist[0] = 0;
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == INF) continue;
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                }
            }
        }
        int ans = dist[N - 1];
        boolean[] navigate = new boolean[N];
        for (int loop = 0; loop < N; loop++) {
            for (int i = 0; i < M; i++) {
                if (dist[a[i] - 1] == INF) continue;
                if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                    dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                    navigate[b[i] - 1] = true;
                }
                if (navigate[a[i] - 1]) navigate[b[i] - 1] = true;
            }
        }
        if (navigate[N - 1]) System.out.println("inf");
        else System.out.println(-ans);
    }
}

