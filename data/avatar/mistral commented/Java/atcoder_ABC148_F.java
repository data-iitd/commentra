
import java.util.ArrayList ;
import java.util.List ;
import java.util.Scanner ;

public class Main {
    // Main method starts the execution of the program
    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            // Read the number of nodes N from the standard input
            int N = sc.nextInt();
            // Read the indices u and v of the two nodes from the standard input
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;

            // Initialize the adjacency lists for the graph
            List<Integer> [ ] edges = new List[N];
            for (int i = 0; i < N; i++) {
                edges[i] = new ArrayList<>();
            }

            // Read the edges of the graph from the standard input and add them to the adjacency lists
            for (int i = 0; i < N - 1; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                // Add the edge between nodes a and b to both adjacency lists
                edges[a].add(b);
                edges[b].add(a);
            }

            // Initialize the distance arrays d and e for depth-first search
            int [ ] d = new int[N];
            for (int i = 0; i < N; i++) {
                d[i] = Integer.MAX_VALUE;
            }
            int [ ] e = new int[N];
            for (int i = 0; i < N; i++) {
                e[i] = Integer.MAX_VALUE;
            }

            // Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
            dfs(u, d, edges);
            dfs(v, e, edges);

            // Find the maximum difference between the distances of any node from u and v
            int q = -1;
            for (int i = 0; i < N; i++) {
                if (d[i] < e[i]) {
                    if (e[i] > q) {
                        q = e[i];
                    }
                }
            }

            // Print the result: the maximum difference between the distances of any node from u and v
            if (q <= 0) {
                System.out.println(0);
            } else {
                System.out.println(q - 1);
            }
        }
    }

    // Depth-first search recursive helper method
    static void dfs(int u, int[] d, List<Integer> [ ] edges) {
        for (Integer nu : edges[u]) {
            if (d[nu] == Integer.MAX_VALUE) {
                // Mark the current node as visited and update the distance of its neighbors
                d[nu] = d[u] + 1;
                dfs(nu, d, edges);
            }
        }
    }
}