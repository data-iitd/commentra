import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());

        List<List<Integer>> adj = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            String[] ab = reader.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        int[] seen = new int[N + 1];
        int[] par = new int[N + 1];
        int[] childNum = new int[N + 1];

        Queue<Integer> que = new LinkedList<>();
        que.add(1);
        seen[1] = 1;

        while (!que.isEmpty()) {
            int v = que.poll();
            for (int u : adj.get(v)) {
                if (seen[u] == 0) {
                    seen[u] = 1;
                    par[u] = v;
                    childNum[v]++;
                    que.add(u);
                }
            }
        }

        Queue<Integer> seq = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (childNum[i] == 0) {
                seq.add(i);
            }
        }

        while (!seq.isEmpty()) {
            int c = seq.poll();
            seen[c] = 0;
            if (seen[par[c]] == 0) {
                System.out.println("First");
                return;
            }
            seen[par[c]] = 0;
            childNum[par[par[c]]]--;
            if (childNum[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }

        System.out.println("Second");
    }
}
