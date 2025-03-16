import java.util.*;

public class GraphColoring {
    private static final int MOD = 1000000007;
    private static List<List<Integer>> graph;
    private static int N, K;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input: number of nodes N and color limit K
        N = scanner.nextInt();
        K = scanner.nextInt();
        
        // Initialize an empty graph
        graph = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        // Read edges between nodes and add them to the graph
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // Call the dfs function with initial values and print the result
        long ans = dfs(0, -1, K);
        System.out.println(ans);
    }

    private static long dfs(int fro, int to, int f) {
        // Initialize case number and color number
        long caseNum = (f == K) ? 1 : 0;
        int colorNum = (f == K) ? K - 1 : K - 2;

        // Iterate through the neighbors of the current node
        for (int u : graph.get(fro)) {
            // Skip the target node
            if (u == to) {
                continue;
            }

            // Recursively call dfs on the neighbor and update case number
            long pat = dfs(u, fro, colorNum);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = (caseNum * pat) % MOD;
            colorNum--;
        }

        // Return the final case number
        return caseNum;
    }
}

// <END-OF-CODE>
