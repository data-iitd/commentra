// Importing necessary packages
import java.util.Scanner;

// Global variables initialization
final int mod = 1000000007;
final int INF = 1000000007;

public class Main {
    // Main function
    public static void main(String[] args) {
        // Reading input from standard input
        Scanner r = new Scanner(System.in);
        // Variables initialization
        int n, m, R;
        n = r.nextInt(); // Reading number of cities n
        m = r.nextInt(); // Reading number of roads m
        R = r.nextInt(); // Reading number of starting points R

        // Initializing rs slice with starting points
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = r.nextInt(); // Reading starting point i
            rs[i]--; // Decreasing starting point index for matrix indexing
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
            int a = r.nextInt(); // Reading road starting point a
            int b = r.nextInt(); // Reading road ending point b
            int c = r.nextInt(); // Reading road cost c
            a--;                 // Decreasing starting point index for matrix indexing
            b--;                 // Decreasing ending point index for matrix indexing
            costs[a][b] = c;     // Filling costs[a][b] with cost c
            costs[b][a] = c;     // Filling costs[b][a] with cost c
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
        int[][] perms = permutations(rs); // Generating all permutations of starting points
        int ans = INF; // Initializing answer with infinite value
        for (int[] perm : perms) { // Iterating through all permutations
            int tmp = 0; // Initializing temporary variable tmp with zero value
            for (int j = 1; j < perm.length; j++) { // Iterating through all pairs of consecutive starting points
                int from = perm[j-1]; // Getting previous starting point
                int to = perm[j];     // Getting current starting point
                tmp += costs[from][to]; // Adding cost of road from from to to tmp
            }
            ans = Math.min(ans, tmp); // Updating answer with minimum of current answer and tmp
        }
        System.out.println(ans); // Printing answer
    }

    // Helper function to generate all permutations of given slice
    public static int[][] permutations(int[] arr) {
        // Helper function initialization
        int[][] res = new int[0][0];

        helper(arr, arr.length);

        return res;
    }

    public static void helper(int[] arr, int n) {
        if (n == 1) { // Base case: when only one element left in arr
            int[] tmp = new int[arr.length];
            for (int i = 0; i < arr.length; i++) {
                tmp[i] = arr[i];
            }
            res = append(res, tmp); // Adding tmp to result
            return;
        }

        for (int i = 0; i < n; i++) { // Iterating through all elements of arr
            helper(arr, n-1); // Recursively calling helper function with n-1
            if (n%2 == 1) { // Swapping first and last elements when n is odd
                int tmp = arr[i];
                arr[i] = arr[n-1];
                arr[n-1] = tmp;
            } else { // Swapping first and last elements when n is even
                int tmp = arr[0];
                arr[0] = arr[n-1];
                arr[n-1] = tmp;
            }
        }
    }

    public static int[][] append(int[][] arr, int[] tmp) {
        int[][] res = new int[arr.length+1][arr[0].length];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                res[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < tmp.length; i++) {
            res[arr.length][i] = tmp[i];
        }
        return res;
    }
}

