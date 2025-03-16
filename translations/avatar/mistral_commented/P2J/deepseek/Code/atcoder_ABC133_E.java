import java.util.*;

public class Main {
    static final int MOD = (int) (1e9 + 7);
    static List<List<Integer>> graph = new ArrayList<>();
    static int N, K;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        // Initialize graph
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        // Read edges
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // Call the dfs function with initial values and print the result
        int ans = dfs(0, -1, K);
        System.out.println(ans);
    }

    static int dfs(int fro, int to, int f) {
        // Initialize case number and color number
        int caseNum = (f == K) ? 1 : 0;
        int colorNum = (f == K) ? K - 1 : K - 2;

        // Iterate through the neighbors of the current node
        for (int u : graph.get(fro)) {
            // Skip the target node
            if (u == to) {
                continue;
            }

            // Recursively call dfs on the neighbor and update case number
            int pat = dfs(u, fro, colorNum);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = (int) ((long) caseNum * pat % MOD);
            colorNum--;
        }

        // Return the final case number
        return caseNum;
    }
}
