import java.util.*;

public class Main {
    // Constants for the modulo operation and infinity value
    static final int mod = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        // Create a new scanner to read from standard input
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
            Arrays.fill(costs[i], INF);
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

    // Function to generate all permutations of a given array
    public static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        permute(arr, 0, res);
        return res;
    }

    private static void permute(int[] arr, int n, List<List<Integer>> res) {
        if (n == arr.length - 1) {
            List<Integer> tmp = new ArrayList<>();
            for (int num : arr) {
                tmp.add(num);
            }
            res.add(tmp);
        } else {
            for (int i = n; i < arr.length; i++) {
                swap(arr, n, i);
                permute(arr, n + 1, res);
                swap(arr, n, i); // backtrack
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
