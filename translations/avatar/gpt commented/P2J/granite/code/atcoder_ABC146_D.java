
import java.util.*;

public class atcoder_ABC146_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<List<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        Map<String, Integer> E = new HashMap<>();
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(String.format("%d %d", a, b), 0);
        }
        int K = bfs(0, N, G, E);
        System.out.println(K);
        for (int value : E.values()) {
            System.out.println(value);
        }
    }

    public static int bfs(int v, int N, List<List<Integer>> G, Map<String, Integer> E) {
        int[] visited = new int[N];
        Queue<Integer> queue = new LinkedList<>();
        int K = -1;
        int[] node2color = new int[N];

        queue.add(v);
        visited[v] = 1;

        while (!queue.isEmpty()) {
            int q = queue.poll();
            int color = 0;

            for (int nex : G.get(q)) {
                if (visited[nex] == 1) {
                    continue;
                }
                visited[nex] = 1;
                color++;

                if (color == node2color[q]) {
                    color++;
                }

                node2color[nex] = color;
                E.put(String.format("%d %d", Math.min(q, nex), Math.max(q, nex)), color);
                queue.add(nex);
            }

            K = Math.max(K, color);
        }

        return K;
    }
}

Translate the above Java code to C++ and end with comment "