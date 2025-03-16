import java.util.*;

public class Main {
    static final int MOD = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int R = scanner.nextInt();

        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1;
        }

        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(costs[i], INF);
            costs[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            costs[a][b] = Math.min(costs[a][b], c);
            costs[b][a] = Math.min(costs[b][a], c);
        }

        // Floyd-Warshall algorithm to calculate shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        // Generate all permutations of the visit order
        List<List<Integer>> perms = permutations(rs);
        int ans = INF;
        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j - 1);
                int to = perm.get(j);
                tmp += costs[from][to];
            }
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans);
    }

    // Generate permutations
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
    static int min(int x, int y) {
        return Math.min(x, y);
    }

    static int max(int x, int y) {
        return Math.max(x, y);
    }

    static int abs(int x) {
        return Math.abs(x);
    }

    static int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    static int lcm(int x, int y) {
        return x / gcd(x, y) * y;
    }
}

// <END-OF-CODE>
