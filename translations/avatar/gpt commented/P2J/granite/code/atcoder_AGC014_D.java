
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class atcoder_AGC014_D{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] adj = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }
        ArrayDeque<Integer> que = new ArrayDeque<>();
        que.add(1);
        int[] seen = new int[N + 1];
        seen[1] = 1;
        int[] par = new int[N + 1];
        int[] child_num = new int[N + 1];
        while (!que.isEmpty()) {
            int v = que.poll();
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
            int c = seq.pollLast();
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
