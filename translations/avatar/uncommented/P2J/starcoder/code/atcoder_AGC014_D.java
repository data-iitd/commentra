import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] adj = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = 0;
            }
        }
        for (int i = 1; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        Queue<Integer> que = new LinkedList<Integer>();
        que.add(1);
        boolean[] seen = new boolean[N + 1];
        seen[1] = true;
        int[] par = new int[N + 1];
        int[] child_num = new int[N + 1];
        while (!que.isEmpty()) {
            int v = que.poll();
            for (int u = 1; u <= N; u++) {
                if (seen[u] == false && adj[v][u] == 1) {
                    seen[u] = true;
                    par[u] = v;
                    child_num[v]++;
                    que.add(u);
                }
            }
        }
        Queue<Integer> seq = new LinkedList<Integer>();
        for (int i = 1; i <= N; i++) {
            if (child_num[i] == 0) {
                seq.add(i);
            }
        }
        while (!seq.isEmpty()) {
            int c = seq.poll();
            seen[c] = false;
            if (seen[par[c]] == false) {
                System.out.println("First");
                return;
            }
            seen[par[c]] = false;
            child_num[par[par[c]]]--;
            if (child_num[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }
        System.out.println("Second");
    }
}
