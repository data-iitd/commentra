
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            // Step 1: Read the input values for N, u, and v
            int N = sc.nextInt();
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;

            // Step 2: Initialize the adjacency list for the graph
            List<Integer>[] edges = new List[N];
            for (int i = 0; i < N; i++) {
                edges[i] = new ArrayList<>();
            }

            // Step 3: Read the edges of the graph and populate the adjacency list
            for (int i = 0; i < N - 1; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                edges[a].add(b);
                edges[b].add(a);
            }

            // Step 4: Initialize the distance array for the first DFS traversal starting from node u
            int[] d = new int[N];
            for (int i = 0; i < N; i++) {
                d[i] = Integer.MAX_VALUE;
            }
            d[u] = 0;

            // Step 5: Perform DFS from node u to populate the distance array d
            dfs(u, d, edges);

            // Step 6: Initialize the distance array for the second DFS traversal starting from node v
            int[] e = new int[N];
            for (int i = 0; i < N; i++) {
                e[i] = Integer.MAX_VALUE;
            }
            e[v] = 0;

            // Step 7: Perform DFS from node v to populate the distance array e
            dfs(v, e, edges);

            // Step 8: Find the maximum value of e[i] where d[i] < e[i]
            int q = -1;
            for (int i = 0; i < N; i++) {
                if (d[i] < e[i]) {
                    if (e[i] > q) {
                        q = e[i];
                    }
                }
            }

            // Step 9: Print the result based on the maximum value found
            if (q <= 0) {
                System.out.println(0);
            } else {
                System.out.println(q - 1);
            }
        }
    }

    // Helper method to perform DFS and populate the distance array
    static void dfs(int u, int[] d, List<Integer>[] edges) {
        for (Integer nu : edges[u]) {
            if (d[nu] == Integer.MAX_VALUE) {
                d[nu] = d[u] + 1;
                dfs(nu, d, edges);
            }
        }
    }
}

