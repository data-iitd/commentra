import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Initialize empty sets for each vertex representing its adjacent vertices
        List<Set<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new HashSet<>());
        }

        // Initialize degree array to keep track of number of edges for each vertex
        int[] degs = new int[N];

        // Initialize parity array to keep track of parity of each vertex
        int[] parity = new int[N];

        // Initialize flag array to keep track of visited vertices
        boolean[] flag = new boolean[N];

        // Read edges from input and add them to their respective sets and update their degrees
        for (int i = 0; i < M; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            // Add edge between vertices a and b in both their sets
            edges.get(a).add(b);
            edges.get(b).add(a);
            // Update degrees of both vertices
            degs[a]++;
            degs[b]++;
        }

        // Check if number of edges is even, if not print -1 and exit
        if (M % 2 != 0) {
            System.out.println(-1);
            return;
        }

        // Initialize empty list Q to store vertices based on their degrees
        PriorityQueue<int[]> Q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        // Iterate through all vertices and add them to Q based on their degrees
        for (int i = 0; i < N; i++) {
            Q.offer(new int[]{degs[i], i});
        }

        // Iterate through Q until it is empty
        while (!Q.isEmpty()) {
            // Get vertex with minimum degree from Q
            int[] top = Q.poll();
            int u = top[1];
            // Skip if vertex is already visited
            if (flag[u]) {
                continue;
            }
            // Mark vertex as visited
            flag[u] = true;
            // Iterate through all adjacent vertices and print their edges and update their parity
            for (int v : edges.get(u)) {
                // Skip if vertex is already visited
                if (flag[v]) {
                    continue;
                }
                // Print edge and update parity of both vertices
                if (parity[u] != 0) {
                    System.out.println((u + 1) + " " + (v + 1));
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println((v + 1) + " " + (u + 1));
                    parity[v] = 1 - parity[v];
                }
                // Decrease degree of adjacent vertex and add it to Q
                degs[v]--;
                Q.offer(new int[]{degs[v], v});
            }
        }
    }
}
