
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		// Initialize a buffered reader to read input
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n, m, R;
		
		// Read the number of nodes (n), edges (m), and the number of required nodes (R)
		try {
			n = Integer.parseInt(r.readLine());
			m = Integer.parseInt(r.readLine());
			R = Integer.parseInt(r.readLine());
		} catch (Exception e) {
			System.out.println("Error reading input");
			return;
		}

		// Read the required nodes and adjust for 0-based indexing
		int[] rs = new int[R];
		for (int i = 0; i < R; i++) {
			try {
				rs[i] = Integer.parseInt(r.readLine()) - 1;
			} catch (Exception e) {
				System.out.println("Error reading input");
				return;
			}
		}

		// Initialize the cost matrix with INF values
		int[][] costs = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(costs[i], Integer.MAX_VALUE);
			costs[i][i] = 0; // The cost to reach itself is 0
		}
		
		// Read the edges and their costs
		int a, b, c;
		for (int i = 0; i < m; i++) {
			try {
				a = Integer.parseInt(r.readLine());
				b = Integer.parseInt(r.readLine());
				c = Integer.parseInt(r.readLine());
				a--;
				b--;
				costs[a][b] = c; // Set cost for edge a to b
				costs[b][a] = c; // Set cost for edge b to a (undirected graph)
			} catch (Exception e) {
				System.out.println("Error reading input");
				return;
			}
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
		int ans = Integer.MAX_VALUE;
		
		// Evaluate each permutation to find the minimum cost path
		for (List<Integer> perm : perms) {
			int tmp = 0;
			for (int j = 1; j < perm.size(); j++) {
				int from = perm.get(j-1);
				int to = perm.get(j);
				tmp += costs[from][to]; // Accumulate the cost of the current permutation
			}
			ans = Math.min(ans, tmp); // Update the answer with the minimum cost found
		}
		
		// Output the minimum cost
		System.out.println(ans);
	}

	// permutations generates all permutations of an array
	public static List<List<Integer>> permutations(int[] arr) {
		List<List<Integer>> res = new ArrayList<>();

		// Recursive helper function to generate permutations
		void helper(int[] arr, int n) {
			if (n == 1) {
				List<Integer> tmp = new ArrayList<>();
				for (int i : arr) {
					tmp.add(i);
				}
				res.add(tmp);
			} else {
				for (int i = 0; i < n; i++) {
					helper(arr, n-1);
					// Swap elements based on the parity of n
					if (n%2 == 1) {
						int tmp = arr[i];
						arr[i] = arr[n-1];
						arr[n-1] = tmp;
					} else {
						int tmp = arr[0];
						arr[0] = arr[n-1];
						arr[n-1] = tmp;
					}
				}
			}
		}
		helper(arr, arr.length);
		return res;
	}

	// Utility functions

	// min returns the smaller of two integers
	public static int min(int x, int y) {
		return x < y ? x : y;
	}

	// max returns the larger of two integers
	public static int max(int x, int y) {
		return x > y ? x : y;
	}

	// abs returns the absolute value of an integer
	public static int abs(int x) {
		return x < 0 ? -x : x;
	}

	// primeFactor returns the prime factorization of x
	public static Map<Integer, Integer> primeFactor(int x) {
		Map<Integer, Integer> res = new HashMap<>();
		for (int i = 2; i*i <= x; i++) {
			while (x % i == 0) {
				res.put(i, res.getOrDefault(i, 0) + 1);
				x /= i;
			}
		}
		if (x != 1) {
			res.put(x, 1);
		}
		return res;
	}

	// divisor returns all divisors of x
	public static List<Integer> divisor(int x) {
		List<Integer> res = new ArrayList<>();
		for (int i = 1; i*i <= x; i++) {
			if (x % i == 0) {
				res.add(i);
				if (i != x/i) {
					res.add(x/i);
				}
			}
		}
		return res;
	}

	// gcd returns the greatest common divisor of x and y
	public static int gcd(int x, int y) {
		return y == 0 ? x : gcd(y, x%y);
	}

	// lcm returns the least common multiple of x and y
	public static int lcm(int x, int y) {
		return x / gcd(x, y) * y;
	}

	// reverseString returns the reversed version of a string
	public static String reverseString(String s) {
		return new StringBuilder(s).reverse().toString();
	}

	// pow calculates a raised to the power of n
	public static int pow(int a, int n) {
		int res = 1;
		for (int i = 1; i <= n; i++) {
			res *= a;
		}
		return res;
	}

	// Queue structure for implementing a queue
	public static class Queue {
		private List<Integer> q = new ArrayList<>();

		// empty checks if the queue is empty
		public boolean empty() {
			return q.isEmpty();
		}

		// push adds an element to the queue
		public void push(int i) {
			q.add(i);
		}

		// pop removes and returns the front element of the queue
		public int pop() {
			if (empty()) {
				return -1;
			} else {
				int res = q.get(0);
				q.remove(0);
				return res;
			}
		}
	}

	// Stack structure for implementing a stack
	public static class Stack {
		private List<Integer> s = new ArrayList<>();

		// empty checks if the stack is empty
		public boolean empty() {
			return s.isEmpty();
		}

		// push adds an element to the stack
		public void push(int i) {
			s.add(i);
		}

		// pop removes and returns the top element of the stack
		public int pop() {
			if (empty()) {
				return -1;
			} else {
				int index = s.size() - 1;
				int res = s.get(index);
				s.remove(index);
				return res;
			}
		}
	}

	// priority_queue structure for implementing a max-heap
	public static class intHeap extends PriorityQueue<Integer> {
		public intHeap() {
			super();
		}
	}

	// sortable points structure for sorting points
	public static class point {
		int x;
		int y;

		public point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static class points implements Comparable<points> {
		int x;
		int y;

		public points(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(points p) {
			return x - p.x;
		}
	}

	// END-OF-CODE
}

