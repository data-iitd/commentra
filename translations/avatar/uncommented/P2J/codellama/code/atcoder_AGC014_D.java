import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

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
        Queue<Integer> que = new LinkedList<>();
        que.add(1);
        boolean[] seen = new boolean[N + 1];
        seen[1] = true;
        int[] par = new int[N + 1];
        int[] child_num = new int[N + 1];
        while (!que.isEmpty()) {
            int v = que.poll();
            for (int u : adj[v]) {
                if (!seen[u]) {
                    seen[u] = true;
                    par[u] = v;
                    child_num[v]++;
                    que.add(u);
                }
            }
        }
        Queue<Integer> seq = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (child_num[i] == 0) {
                seq.add(i);
            }
        }
        while (!seq.isEmpty()) {
            int c = seq.poll();
            seen[c] = false;
            if (!seen[par[c]]) {
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



Translate the above Java code to C++ and end with comment "