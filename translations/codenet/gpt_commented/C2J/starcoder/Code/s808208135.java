import java.util.*;

public class BellmanFord {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = Integer.MAX_VALUE;
        }
        d[0] = 0;
        for (int i = 0; i < m; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            int w = in.nextInt();
            if (d[u]!= Integer.MAX_VALUE && d[u] + w < d[v]) {
                d[v] = d[u] + w;
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }
}

