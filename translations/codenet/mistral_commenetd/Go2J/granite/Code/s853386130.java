
// Importing necessary packages
import java.util.*;

public class s853386130{
    // Global variables initialization
    static final int mod = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        // Reading input from standard input
        Scanner scanner = new Scanner(System.in);
        // Variables initialization
        int n = scanner.nextInt(); // Reading number of cities n
        int m = scanner.nextInt(); // Reading number of roads m
        int R = scanner.nextInt(); // Reading number of starting points R

        // Initializing rs array with starting points
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1; // Reading starting point i and decreasing index for matrix indexing
        }

        // Initializing costs matrix with infinite values
        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = INF; // Initializing costs[i][j] with infinite value
                costs[i][i] = 0;   // Initializing costs[i][i] with zero value
            }
        }

        // Reading roads and filling costs matrix with their costs
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1; // Reading road starting point a and decreasing index for matrix indexing
            int b = scanner.nextInt() - 1; // Reading road ending point b and decreasing index for matrix indexing
            int c = scanner.nextInt(); // Reading road cost c
            costs[a][b] = c; // Filling costs[a][b] with cost c
            costs[b][a] = c; // Filling costs[b][a] with cost c
        }

        // Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]); // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
                }
            }
        }

        // Calculating minimum cost of visiting all cities in a single tour
        List<List<Integer>> perms = permutations(rs); // Generating all permutations of starting points
        int ans = INF; // Initializing answer with infinite value
        for (List<Integer> perm : perms) { // Iterating through all permutations
            int tmp = 0; // Initializing temporary variable tmp with zero value
            for (int j = 1; j < perm.size(); j++) { // Iterating through all pairs of consecutive starting points
                int from = perm.get(j - 1); // Getting previous starting point
                int to = perm.get(j); // Getting current starting point
                tmp += costs[from][to]; // Adding cost of road from from to to tmp
            }
            ans = Math.min(ans, tmp); // Updating answer with minimum of current answer and tmp
        }
        System.out.println(ans); // Printing answer
        scanner.close(); // Closing scanner
    }

    // Helper function to generate all permutations of given array
    static List<List<Integer>> permutations(int[] arr) {
        // Helper function initialization
        List<List<Integer>> res = new ArrayList<>();
        Deque<Integer> stack = new ArrayDeque<>();

        // Helper function to generate permutations
        void helper(int[] arr, int n) {
            if (n == 1) { // Base case: when only one element left in arr
                List<Integer> tmp = new ArrayList<>();
                for (int i : arr) {
                    tmp.add(i); // Adding elements of arr to tmp for returning
                }
                res.add(tmp); // Adding tmp to result
                return;
            }

            for (int i = 0; i < n; i++) { // Iterating through all elements of arr
                helper(arr, n - 1); // Recursively calling helper function with n-1
                if (n % 2 == 1) { // Swapping first and last elements when n is odd
                    int tmp = arr[i];
                    arr[i] = arr[n - 1];
                    arr[n - 1] = tmp;
                } else { // Swapping first and last elements when n is even
                    int tmp = arr[0];
                    arr[0] = arr[n - 1];
                    arr[n - 1] = tmp;
                }
            }
        }
        helper(arr, arr.length); // Calling helper function with arr and its length
        return res;
    }
}

