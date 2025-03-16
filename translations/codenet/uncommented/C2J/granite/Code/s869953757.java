
import java.util.Scanner;

public class s869953757{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] T = new int[n][n];
        int[] color = new int[n];
        int[] d = new int[n];
        int[] Q = new int[n];
        int head = 0, tail = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            int u = sc.nextInt() - 1;
            int k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                int v = sc.nextInt() - 1;
                T[u][v] = 1;
            }
        }

        bfs(n, T, color, d, Q, head, tail);

        for (int i = 0; i < n; i++) {
            if (d[i] == 1000000) {
                d[i] = -1;
            }
            System.out.println((i + 1) + " " + d[i]);
        }
    }

    public static void bfs(int n, int[][] T, int[] color, int[] d, int[] Q, int head, int tail) {
        for (int i = 0; i < n; i++) {
            color[i] = 0;
            d[i] = 1000000;
        }

        color[0] = 1;
        d[0] = 0;
        Q[tail] = 0;
        tail = (tail + 1) % n;

        while (head!= tail) {
            int u = Q[head];
            head = (head + 1) % n;
            for (int v = 0; v < n; v++) {
                if (T[u][v] == 1 && color[v] == 0) {
                    color[v] = 1;
                    d[v] = d[u] + 1;
                    Q[tail] = v;
                    tail = (tail + 1) % n;
                }
            }
            color[u] = 2;
        }
    }
}
