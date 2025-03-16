import java.util.*;

public class Main {
    // Generate a unique identifier for an edge between two nodes.
    static int genid(int a, int b) {
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        return a * 100000 + b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize a list to store edges and an adjacency list for the graph.
        int[][] ab = new int[N - 1][2];
        List<List<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; i++) {
            // Read edge information and populate the adjacency list.
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            ab[i][0] = a;
            ab[i][1] = b;
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        // Initialize a map to store the color of each edge and a queue for DFS traversal.
        Map<Integer, Integer> colors = new HashMap<>();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, -1, -1});
        while (!q.isEmpty()) {
            // Pop the last element from the queue for DFS traversal.
            int[] currentNodeInfo = q.poll();
            int currentNode = currentNodeInfo[0];
            int usedColor = currentNodeInfo[1];
            int parentNode = currentNodeInfo[2];
            int color = 1;
            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors.put(genid(currentNode, childNode), color);
                q.add(new int[]{childNode, color, currentNode});
                color++;
            }
        }

        // Determine the maximum degree of any node in the graph.
        int K = -1;
        for (int i = 0; i < N; i++) {
            int degree = edges.get(i).size();
            if (degree > K) {
                K = degree;
            }
        }
        System.out.println(K);

        // Output the colors of the edges.
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }
    }
}
