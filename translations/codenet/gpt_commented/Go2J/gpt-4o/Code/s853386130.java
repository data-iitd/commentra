import java.util.*;

public class Main {
    static final int MOD = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes (n), edges (m), and the number of required nodes (R)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int R = scanner.nextInt();

        // Read the required nodes and adjust for 0-based indexing
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1;
        }

        // Initialize the cost matrix with INF values
        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(costs[i], INF);
            costs[i][i] = 0; // The cost to reach itself is 0
        }

        // Read the edges and their costs
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            costs[a][b] = c; // Set cost for edge a to b
            costs[b][a] = c; // Set cost for edge b to a (undirected graph)
        }

        // Calculate the shortest paths using the Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        // Generate all permutations of the required nodes
        List<List<Integer>> perms = permutations(rs);
        int ans = INF;

        // Evaluate each permutation to find the minimum cost path
        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j - 1);
                int to = perm.get(j);
                tmp += costs[from][to]; // Accumulate the cost of the current permutation
            }
            ans = Math.min(ans, tmp); // Update the answer with the minimum cost found
        }

        // Output the minimum cost
        System.out.println(ans);
    }

    // permutations generates all permutations of an array
    static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[] used = new boolean[arr.length];
        List<Integer> current = new ArrayList<>();
        backtrack(arr, used, current, res);
        return res;
    }

    static void backtrack(int[] arr, boolean[] used, List<Integer> current, List<List<Integer>> res) {
        if (current.size() == arr.length) {
            res.add(new ArrayList<>(current));
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (!used[i]) {
                used[i] = true;
                current.add(arr[i]);
                backtrack(arr, used, current, res);
                current.remove(current.size() - 1);
                used[i] = false;
            }
        }
    }

    // Utility functions

    // min returns the smaller of two integers
    static int min(int x, int y) {
        return Math.min(x, y);
    }

    // gcd returns the greatest common divisor of x and y
    static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }

    // lcm returns the least common multiple of x and y
    static int lcm(int x, int y) {
        return x / gcd(x, y) * y;
    }
}

// <END-OF-CODE>
