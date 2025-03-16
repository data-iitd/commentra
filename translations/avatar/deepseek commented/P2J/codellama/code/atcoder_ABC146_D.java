import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Deque<Integer>[] G = new Deque[N];
        for (int i = 0; i < N; i++) {
            G[i] = new LinkedList<>();
        }
        int[] node2color = new int[N];
        int[] visited = new int[N];
        int K = -1;
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            G[a].add(b);
            G[b].add(a);
            node2color[a] = node2color[b] = 0;
        }
        bfs(0, N, G, node2color, visited, K);
        System.out.println(K);
        for (int i = 0; i < N - 1; i++) {
            System.out.println(node2color[i]);
        }
    }

    public static void bfs(int v, int N, Deque<Integer>[] G, int[] node2color, int[] visited, int K) {
        Deque<Integer> queue = new LinkedList<>();
        queue.add(v);
        visited[v] = 1;
        while (!queue.isEmpty()) {
            int q = queue.remove();
            int color = 0;
            for (int nex : G[q]) {
                if (visited[nex] == 1) {
                    continue;
                }
                visited[nex] = 1;
                color++;
                if (color == node2color[q]) {
                    color++;
                }
                node2color[nex] = color;
                K = Math.max(K, color);
                queue.add(nex);
            }
        }
    }
}

