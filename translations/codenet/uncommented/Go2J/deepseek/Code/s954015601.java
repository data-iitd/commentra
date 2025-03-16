import java.util.*;

public class Main {
    static class Edge {
        int to;
        Edge(int to) {
            this.to = to;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        List<Edge>[] edges = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            edges[i] = new ArrayList<>();
        }

        int[][] ab = new int[N - 1][2];
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            ab[i][0] = a;
            ab[i][1] = b;
            edges[a].add(new Edge(b));
            edges[b].add(new Edge(a));
        }

        int[] colors = new int[N - 1];
        Arrays.fill(colors, -1);

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, -1, -1});

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentNode = current[0];
            int usedColor = current[1];
            int parentNode = current[2];

            int color = 1;
            for (Edge edge : edges[currentNode]) {
                int childNode = edge.to;
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors[getEdgeIndex(ab, currentNode, childNode)] = color;
                queue.add(new int[]{childNode, color, currentNode});
                color++;
            }
        }

        int K = 0;
        for (int i = 0; i < N; i++) {
            K = Math.max(K, edges[i].size());
        }
        System.out.println(K);

        for (int color : colors) {
            System.out.println(color);
        }
    }

    private static int getEdgeIndex(int[][] ab, int a, int b) {
        for (int i = 0; i < ab.length; i++) {
            if ((ab[i][0] == a && ab[i][1] == b) || (ab[i][0] == b && ab[i][1] == a)) {
                return i;
            }
        }
        return -1;
    }
}
