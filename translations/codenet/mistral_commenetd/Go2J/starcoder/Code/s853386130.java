// Importing necessary packages
import java.io.*;
import java.util.*;

public class Main {
	// Global variables initialization
	static int mod = 1000000007;
	static int INF = 1000000007;

	public static void main(String[] args) throws Exception {
		// Reading input from standard input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// Variables initialization
		int n, m, R;
		n = Integer.parseInt(br.readLine()); // Reading number of cities n
		m = Integer.parseInt(br.readLine()); // Reading number of roads m
		R = Integer.parseInt(br.readLine()); // Reading number of starting points R

		// Initializing rs slice with starting points
		int[] rs = new int[R];
		for (int i = 0; i < R; i++) {
			rs[i] = Integer.parseInt(br.readLine()) - 1; // Reading starting point i and decreasing it for matrix indexing
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
			int a = Integer.parseInt(br.readLine()) - 1; // Reading road starting point a and decreasing it for matrix indexing
			int b = Integer.parseInt(br.readLine()) - 1; // Reading road ending point b and decreasing it for matrix indexing
			int c = Integer.parseInt(br.readLine());     // Reading road cost c
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
		List<List<Integer>> perms = permutations(rs); // Generating all permutations of starting points
		int ans = INF; // Initializing answer with infinite value
		for (List<Integer> perm : perms) { // Iterating through all permutations
			int tmp = 0; // Initializing temporary variable tmp with zero value
			for (int j = 1; j < perm.size(); j++) { // Iterating through all pairs of consecutive starting points
				int from = perm.get(j - 1); // Getting previous starting point
				int to = perm.get(j);     // Getting current starting point
				tmp += costs[from][to]; // Adding cost of road from from to to tmp
			}
			ans = Math.min(ans, tmp); // Updating answer with minimum of current answer and tmp
		}
		System.out.println(ans); // Printing answer
	}

	// Helper function to generate all permutations of given slice
	public static List<List<Integer>> permutations(int[] arr) {
		// Helper function initialization
		List<List<Integer>> res = new ArrayList<>();
		var helper = new Helper();

		helper.helper(arr, 0, res); // Calling helper function with arr, starting index and result
		return res;
	}

	// Helper class for permutations function
	static class Helper {
		public void helper(int[] arr, int i, List<List<Integer>> res) {
			if (i == arr.length) { // Base case: when only one element left in arr
				List<Integer> tmp = new ArrayList<>();
				for (int j = 0; j < arr.length; j++) { // Copying arr to tmp for returning
					tmp.add(arr[j]);
				}
				res.add(tmp);
				return;
			}

			for (int j = i; j < arr.length; j++) { // Iterating through all elements of arr
				swap(arr, i, j); // Swapping first and last elements
				helper.helper(arr, i + 1, res); // Recursively calling helper function with n-1
				swap(arr, i, j); // Swapping first and last elements back
			}
		}

		// Helper function to swap two elements of an array
		public void swap(int[] arr, int i, int j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}

