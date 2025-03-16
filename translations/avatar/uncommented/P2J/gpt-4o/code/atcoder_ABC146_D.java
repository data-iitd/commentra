import java.util.*;

public class Main {
    static int bfs(int v, int N, List<Deque<Integer>> G, Map<Pair<Integer, Integer>, Integer> E) {
        int[] visited = new int[N];
        Deque<Integer> queue = new ArrayDeque<>();
        int K = -1;
        int[] node2color = new int[N];
        Arrays.fill(node2color, -1);
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
                E.put(new Pair<>(Math.min(q, nex), Math.max(q, nex)), color);
                queue.add(nex);
            }
            K = Math.max(K, color);
        }
        return K;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        List<Deque<Integer>> G = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            G.add(new ArrayDeque<>());
        }
        Map<Pair<Integer, Integer>, Integer> E = new HashMap<>();

        for (int i = 0; i < N - 1; i++) {
            int a = input.nextInt() - 1;
            int b = input.nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(new Pair<>(a, b), 0);
        }

        int K = bfs(0, N, G, E);
        System.out.println(K);
        for (int value : E.values()) {
            System.out.println(value);
        }
        input.close();
    }

    static class Pair<K, V> {
        K first;
        V second;

        Pair(K first, V second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }
}
//<END-OF-CODE>
