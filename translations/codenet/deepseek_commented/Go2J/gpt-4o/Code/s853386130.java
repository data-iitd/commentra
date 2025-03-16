import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Constants for the modulo operation and infinity value
    static final int MOD = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of cities, roads, and restaurants
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int R = scanner.nextInt();

        // Read the indices of the restaurants and decrement by 1 for 0-based indexing
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1;
        }

        // Initialize the cost matrix with INF and set diagonal to 0
        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = INF;
            }
            costs[i][i] = 0;
        }

        // Read the road connections and their costs, updating the cost matrix
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            costs[a][b] = c;
            costs[b][a] = c;
        }

        // Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        // Generate all permutations of the restaurant indices and find the minimum cost tour
        List<int[]> perms = permutations(rs);
        int ans = INF;
        for (int[] perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.length; j++) {
                int from = perm[j - 1];
                int to = perm[j];
                tmp += costs[from][to];
            }
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans);
    }

    // Function to generate all permutations of a given array
    static List<int[]> permutations(int[] arr) {
        List<int[]> res = new ArrayList<>();
        boolean[] used = new boolean[arr.length];
        int[] current = new int[arr.length];

        backtrack(arr, used, current, 0, res);
        return res;
    }

    static void backtrack(int[] arr, boolean[] used, int[] current, int depth, List<int[]> res) {
        if (depth == arr.length) {
            res.add(current.clone());
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (!used[i]) {
                used[i] = true;
                current[depth] = arr[i];
                backtrack(arr, used, current, depth + 1, res);
                used[i] = false;
            }
        }
    }
}
// <END-OF-CODE>
