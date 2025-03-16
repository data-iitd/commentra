import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] G = new int[N][N];
        int[][] E = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                G[i][j] = -1;
                E[i][j] = -1;
            }
        }
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            G[a][b] = b;
            G[b][a] = a;
            E[a][b] = 0;
            E[b][a] = 0;
        }
        int K = bfs(0, N, G, E);
        System.out.println(K);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(E[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static int bfs(int v, int N, int[][] G, int[][] E) {
        int[] visited = new int[N];
        Queue<Integer> queue = new LinkedList<Integer>();
        int K = -1;
        int[] node2color = new int[N];
        queue.add(v);
        visited[v] = 1;
        while (!queue.isEmpty()) {
            int q = queue.poll();
            int color = 0;
            for (int nex : G[q]) {
                if (visited[nex]) {
                    continue;
                }
                visited[nex] = 1;
                color += 1;
                if (color == node2color[q]) {
                    color += 1;
                }
                node2color[nex] = color;
                E[Math.min(q, nex)][Math.max(q, nex)] = color;
                queue.add(nex);
            }
            K = Math.max(K, color);
        }
        return K;
    }
}
