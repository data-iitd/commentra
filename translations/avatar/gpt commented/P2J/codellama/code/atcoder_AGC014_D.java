
import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] adj = new int[N + 1][];
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adj[a] = new int[]{b};
            adj[b] = new int[]{a};
        }
        int[] seen = new int[N + 1];
        seen[1] = 1;
        int[] par = new int[N + 1];
        int[] child_num = new int[N + 1];
        ArrayDeque<Integer> que = new ArrayDeque<>();
        que.add(1);
        while (!que.isEmpty()) {
            int v = que.remove();
            for (int u : adj[v]) {
                if (seen[u] == 0) {
                    seen[u] = 1;
                    par[u] = v;
                    child_num[v]++;
                    que.add(u);
                }
            }
        }
        ArrayDeque<Integer> seq = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            if (child_num[i] == 0) {
                seq.add(i);
            }
        }
        while (!seq.isEmpty()) {
            int c = seq.remove();
            seen[c] = 0;
            if (seen[par[c]] == 0) {
                System.out.println("First");
                return;
            }
            seen[par[c]] = 0;
            child_num[par[par[c]]]--;
            if (child_num[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }
        System.out.println("Second");
    }
}

