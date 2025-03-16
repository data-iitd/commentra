
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read input: number of nodes N and color limit K
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Read edges between nodes and add them to the graph
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (!graph.containsKey(a)) {
                graph.put(a, new ArrayList<>());
            }
            if (!graph.containsKey(b)) {
                graph.put(b, new ArrayList<>());
            }
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // Define a recursive function dfs to calculate the answer
        long mod = 1000000007;
        long dfs(int fro, int to, int f) {
            // Initialize case number and color number
            long caseNum = 1;
            if (f == K) {
                caseNum = 0;
            }
            int colorNum = K - 1;
            if (f == K) {
                colorNum = K - 2;
            }

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
                caseNum = caseNum * pat % mod;
                colorNum--;
            }

            // Return the final case number
            return caseNum;
        }

        // Call the dfs function with initial values and print the result
        long ans = dfs(0, -1, K);
        System.out.println(ans);
    }
}

