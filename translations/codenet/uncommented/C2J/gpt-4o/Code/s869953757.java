import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
    static final int M = 100;
    static final int whi = 0;
    static final int gra = 1;
    static final int bla = 2;

    static int n;
    static int[][] T = new int[M][M];
    static int[] color = new int[M];
    static int[] d = new int[M];

    public static void bfs(int s) {
        for (int i = 0; i < n; i++) {
            color[i] = whi;
            d[i] = 1000000;
        }

        color[s] = gra;
        d[s] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);

        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v = 0; v < n; v++) {
                if (T[u][v] == 1 && color[v] == whi) {
                    color[v] = gra;
                    d[v] = d[u] + 1;
                    queue.add(v);
                }
            }
            color[u] = bla;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1;
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                int v = scanner.nextInt() - 1;
                T[u][v] = 1;
            }
        }

        bfs(0);

        for (int i = 0; i < n; i++) {
            if (d[i] == 1000000) d[i] = -1;
            System.out.println((i + 1) + " " + d[i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
