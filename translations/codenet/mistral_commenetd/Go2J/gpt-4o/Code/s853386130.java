// Importing necessary packages
import java.util.*;

public class Main {
    // Global variables initialization
    static final int MOD = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        // Reading input from standard input
        Scanner scanner = new Scanner(System.in);
        
        // Variables initialization
        int n = scanner.nextInt(); // Reading number of cities n
        int m = scanner.nextInt(); // Reading number of roads m
        int R = scanner.nextInt(); // Reading number of starting points R

        // Initializing rs list with starting points
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1; // Reading starting point i and decreasing index for matrix indexing
        }

        // Initializing costs matrix with infinite values
        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(costs[i], INF); // Initializing costs[i][j] with infinite value
            costs[i][i] = 0; // Initializing costs[i][i] with zero value
        }

        // Reading roads and filling costs matrix with their costs
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1; // Reading road starting point a
            int b = scanner.nextInt() - 1; // Reading road ending point b
            int c = scanner.nextInt(); // Reading road cost c
            costs[a][b] = c; // Filling costs[a][b] with cost c
            costs[b][a] = c; // Filling costs[b][a] with cost c
        }

        // Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]); // Updating costs[i][j]
                }
            }
        }

        // Calculating minimum cost of visiting all cities in a single tour
        List<int[]> perms = permutations(rs); // Generating all permutations of starting points
        int ans = INF; // Initializing answer with infinite value
        for (int[] perm : perms) { // Iterating through all permutations
            int tmp = 0; // Initializing temporary variable tmp with zero value
            for (int j = 1; j < perm.length; j++) { // Iterating through all pairs of consecutive starting points
                int from = perm[j - 1]; // Getting previous starting point
                int to = perm[j]; // Getting current starting point
                tmp += costs[from][to]; // Adding cost of road from from to to tmp
            }
            ans = Math.min(ans, tmp); // Updating answer with minimum of current answer and tmp
        }
        System.out.println(ans); // Printing answer
    }

    // Helper function to generate all permutations of given array
    static List<int[]> permutations(int[] arr) {
        List<int[]> res = new ArrayList<>();
        boolean[] used = new boolean[arr.length];
        int[] current = new int[arr.length];

        // Helper function for generating permutations
        backtrack(arr, used, current, 0, res);
        return res;
    }

    static void backtrack(int[] arr, boolean[] used, int[] current, int depth, List<int[]> res) {
        if (depth == arr.length) { // Base case: when all elements are used
            res.add(current.clone()); // Adding current permutation to result
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            if (!used[i]) { // If the element is not used
                used[i] = true; // Mark as used
                current[depth] = arr[i]; // Add to current permutation
                backtrack(arr, used, current, depth + 1, res); // Recur
                used[i] = false; // Backtrack
            }
        }
    }
}
// <END-OF-CODE>
