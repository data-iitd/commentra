package main;

import java.io.*;
import java.util.*;

public class Main {
	// Constants for the modulo operation and infinity value
	static final int mod = 1000000007;
	static final int INF = 1000000007;

	public static void main(String[] args) throws Exception {
		// Create a new reader to read from standard input
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		
		// Read the number of cities, roads, and restaurants
		int n, m, R;
		n = Integer.parseInt(r.readLine());
		m = Integer.parseInt(r.readLine());
		R = Integer.parseInt(r.readLine());

		// Read the indices of the restaurants and decrement by 1 for 0-based indexing
		int[] rs = new int[R];
		for (int i = 0; i < R; i++) {
			rs[i] = Integer.parseInt(r.readLine()) - 1;
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
		int a, b, c;
		for (int i = 0; i < m; i++) {
			a = Integer.parseInt(r.readLine());
			b = Integer.parseInt(r.readLine());
			c = Integer.parseInt(r.readLine());
			costs[a-1][b-1] = c;
			costs[b-1][a-1] = c;
		}

		// Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					costs[i][j] = Math.min(costs[i][j], costs[i][k]+costs[k][j]);
				}
			}
		}

		// Generate all permutations of the restaurant indices and find the minimum cost tour
		List<int[]> perms = permutations(rs);
		int ans = INF;
		for (int[] perm : perms) {
			int tmp = 0;
			for (int j = 1; j < perm.length; j++) {
				int from = perm[j-1];
				int to = perm[j];
				tmp += costs[from][to];
			}
			ans = Math.min(ans, tmp);
		}
		System.out.println(ans);
	}

	// Function to generate all permutations of a given array
	public static List<int[]> permutations(int[] arr) {
		List<int[]> res = new ArrayList<int[]>();
		int[] tmp = new int[arr.length];
		helper(arr, 0, tmp, res);
		return res;
	}

	public static void helper(int[] arr, int i, int[] tmp, List<int[]> res) {
		if (i == arr.length) {
			res.add(tmp.clone());
			return;
		}
		for (int j = i; j < arr.length; j++) {
			swap(arr, i, j);
			helper(arr, i+1, tmp, res);
			swap(arr, i, j);
		}
	}

	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

