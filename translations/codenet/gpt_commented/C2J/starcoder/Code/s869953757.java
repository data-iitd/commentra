import java.util.*;

public class BFS {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
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
            int u = in.nextInt();
            int k = in.nextInt();
            u--;
            for (int j = 0; j < k; j++) {
                int v = in.nextInt();
                v--;
                T[u][v] = 1;
            }
        }
        bfs(0);
        for (int i = 0; i < n; i++) {
            if (d[i] == 1000000) d[i] = -1;
            System.out.println(i + 1 + " " + d[i]);
        }
    }

    public static void bfs(int s) {
        int i, u, v;
        for (i = 0; i < n; i++) {
            color[i] = 0;
            d[i] = 1000000;
        }
        color[s] = 1;
        d[s] = 0;
        enqueue(s);
        while (head!= tail) {
            u = dequeue();
            for (v = 0; v < n; v++) {
                if (T[u][v] == 1 && color[v] == 0) {
                    color[v] = 1;
                    d[v] = d[u] + 1;
                    enqueue(v);
                }
            }
            color[u] = 2;
        }
    }

    public static void enqueue(int x) {
        Q[tail] = x;
        tail = (tail + 1) % n;
    }

    public static int dequeue() {
        int x;
        x = Q[head];
        head = (head + 1) % n;
        return x;
    }
}

