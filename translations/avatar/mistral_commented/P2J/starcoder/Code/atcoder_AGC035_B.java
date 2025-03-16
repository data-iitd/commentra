
// Import necessary libraries
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Take input number of vertices N and number of edges M
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize empty sets for each vertex representing its adjacent vertices
        Set<Integer>[] edges = new HashSet[N];
        for (int i = 0; i < N; i++) {
            edges[i] = new HashSet<Integer>();
        }

        // Initialize degree array to keep track of number of edges for each vertex
        int[] degs = new int[N];

        // Initialize parity array to keep track of parity of each vertex
        int[] parity = new int[N];

        // Initialize flag array to keep track of visited vertices
        boolean[] flag = new boolean[N];

        // Read edges from input and add them to their respective sets and update their degrees
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            // Add edge between vertices a and b in both their sets
            edges[a-1].add(b-1);
            edges[b-1].add(a-1);
            // Update degrees of both vertices
            degs[a-1] += 1;
            degs[b-1] += 1;
        }

        // Check if number of edges is even, if not print -1 and exit
        if (M % 2!= 0) {
            System.out.println(-1);
            return;
        }

        // Initialize empty list Q to store vertices based on their degrees
        List<Pair> Q = new ArrayList<Pair>();

        // Iterate through all vertices and add them to Q based on their degrees
        for (int i = 0; i < N; i++) {
            Q.add(new Pair(degs[i], i));
        }

        // Sort Q based on degrees in ascending order
        Collections.sort(Q, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.first - o2.first;
            }
        });

        // Iterate through Q until it is empty
        while (Q.size() > 0) {
            // Get vertex with minimum degree from Q
            Pair p = Q.get(0);
            Q.remove(0);
            int u = p.second;
            // Skip if vertex is already visited
            if (flag[u]) {
                continue;
            }
            // Mark vertex as visited
            flag[u] = true;
            // Iterate through all adjacent vertices and print their edges and update their parity
            for (int v : edges[u]) {
                // Skip if vertex is already visited
                if (flag[v]) {
                    continue;
                }
                // Print edge and update parity of both vertices
                if (parity[u]!= 0 && v == edges[u].iterator().next()) {
                    System.out.println(u+1 + " " + v+1);
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println(v+1 + " " + u+1);
                    parity[v] = 1 - parity[v];
                }
                // Decrease degree of adjacent vertex and add it to Q
                degs[v] -= 1;
                Q.add(new Pair(degs[v], v));
                Collections.sort(Q, new Comparator<Pair>() {
                    @Override
                    public int compare(Pair o1, Pair o2) {
                        return o1.first - o2.first;
                    }
                });
            }
        }
    }

    // Class to store pairs of integers
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}

