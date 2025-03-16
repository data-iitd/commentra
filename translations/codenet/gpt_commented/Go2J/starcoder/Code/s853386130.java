package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize a buffered reader to read input
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int n, m, R;
		
		// Read the number of nodes (n), edges (m), and the number of required nodes (R)
		n = Integer.parseInt(r.readLine());
		m = Integer.parseInt(r.readLine());
		R = Integer.parseInt(r.readLine());

		// Read the required nodes and adjust for 0-based indexing
		int[] rs = new int[R];
		for (int i = 0; i < R; i++) {
			rs[i] = Integer.parseInt(r.readLine()) - 1;
		}

		// Initialize the cost matrix with INF values
		int[][] costs = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = Integer.MAX_VALUE;
			}
			costs[i][i] = 0; // The cost to reach itself is 0
		}
		
		// Read the edges and their costs
		int a, b, c;
		for (int i = 0; i < m; i++) {
			a = Integer.parseInt(r.readLine());
			b = Integer.parseInt(r.readLine());
			c = Integer.parseInt(r.readLine());
			a--;
			b--;
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
		List<int[]> perms = permutations(rs);
		int ans = Integer.MAX_VALUE;
		
		// Evaluate each permutation to find the minimum cost path
		for (int[] perm : perms) {
			int tmp = 0;
			for (int j = 1; j < perm.length; j++) {
				int from = perm[j-1];
				int to = perm[j];
				tmp += costs[from][to]; // Accumulate the cost of the current permutation
			}
			ans = Math.min(ans, tmp); // Update the answer with the minimum cost found
		}
		
		// Output the minimum cost
		System.out.println(ans);
	}

	// permutations generates all permutations of an array
	public static List<int[]> permutations(int[] arr) {
		List<int[]> res = new ArrayList<int[]>();
		int[] tmp = new int[arr.length];
		helper(arr, 0, tmp, res);
		return res;
	}

	// Recursive helper function to generate permutations
	public static void helper(int[] arr, int n, int[] tmp, List<int[]> res) {
		if (n == arr.length) {
			int[] tmp2 = new int[arr.length];
			System.arraycopy(tmp, 0, tmp2, 0, arr.length);
			res.add(tmp2);
		} else {
			for (int i = 0; i < arr.length; i++) {
				tmp[n] = arr[i];
				helper(arr, n+1, tmp, res);
				// Swap elements based on the parity of n
				if (n % 2 == 1) {
					int tmp3 = tmp[i];
					tmp[i] = tmp[n];
					tmp[n] = tmp3;
				} else {
					int tmp3 = tmp[0];
					tmp[0] = tmp[n];
					tmp[n] = tmp3;
				}
			}
		}
	}

	// Union-Find structure for disjoint set operations
	static class unionFind {
		int[] d;

		// newUnionFind initializes a new Union-Find structure
		public unionFind(int n) {
			d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = -1; // Initialize each node as its own root
			}
		}

		// find finds the root of the set containing x
		public int find(int x) {
			if (d[x] < 0) {
				return x;
			}
			d[x] = find(d[x]); // Path compression
			return d[x];
		}

		// unite merges the sets containing x and y
		public boolean unite(int x, int y) {
			int rootX = find(x);
			int rootY = find(y);
			if (rootX == rootY) {
				return false; // x and y are already in the same set
			}

			// Union by size
			if (d[rootX] < d[rootY]) {
				d[rootX] += d[rootY];
				d[rootY] = rootX;
			} else {
				d[rootY] += d[rootX];
				d[rootX] = rootY;
			}

			return true;
		}

		// same checks if x and y are in the same set
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}

		// size returns the size of the set containing x
		public int size(int x) {
			return -d[find(x)];
		}
	}

	// Utility functions

	// min returns the smaller of two integers
	public static int min(int x, int y) {
		if (x < y) {
			return x;
		}
		return y;
	}

	// max returns the larger of two integers
	public static int max(int x, int y) {
		if (x > y) {
			return x;
		}
		return y;
	}

	// abs returns the absolute value of an integer
	public static int abs(int x) {
		if (x < 0) {
			return -x;
		}
		return x;
	}

	// primeFactor returns the prime factorization of x
	public static Map<Integer, Integer> primeFactor(int x) {
		Map<Integer, Integer> res = new HashMap<Integer, Integer>();
		for (int i = 2; i*i <= x; i++) {
			while (x%i == 0) {
				if (res.containsKey(i)) {
					res.put(i, res.get(i) + 1);
				} else {
					res.put(i, 1);
				}
				x = x / i;
			}
		}
		if (x!= 1) {
			res.put(x, 1);
		}
		return res;
	}

	// divisor returns all divisors of x
	public static List<Integer> divisor(int x) {
		List<Integer> res = new ArrayList<Integer>();
		for (int i = 1; i*i <= x; i++) {
			if (x%i == 0) {
				res.add(i);
				if (i!= x/i) {
					res.add(x/i);
				}
			}
		}
		return res;
	}

	// gcd returns the greatest common divisor of x and y
	public static int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		return gcd(y, x%y);
	}

	// lcm returns the least common multiple of x and y
	public static int lcm(int x, int y) {
		return x / gcd(x, y) * y;
	}

	// reverseString returns the reversed version of a string
	public static String reverseString(String s) {
		char[] r = s.toCharArray();
		for (int i = 0, j = r.length-1; i < r.length/2; i++, j--) {
			char tmp = r[i];
			r[i] = r[j];
			r[j] = tmp;
		}
		return new String(r);
	}

	// pow calculates a raised to the power of n
	public static int pow(int a, int n) {
		int ret = 1;
		for (int i = 1; i <= n; i++) {
			ret *= a;
		}
		return ret;
	}

	// Queue structure for implementing a queue
	static class Queue {
		int[] q;
		int head, tail;

		// empty checks if the queue is empty
		public boolean empty() {
			return head == tail;
		}

		// push adds an element to the queue
		public void push(int i) {
			q[tail] = i;
			tail = (tail + 1) % q.length;
		}

		// pop removes and returns the front element of the queue
		public int pop() {
			int res = q[head];
			head = (head + 1) % q.length;
			return res;
		}
	}

	// Stack structure for implementing a stack
	static class Stack {
		int[] s;
		int top;

		// empty checks if the stack is empty
		public boolean empty() {
			return top == -1;
		}

		// push adds an element to the stack
		public void push(int i) {
			s[++top] = i;
		}

		// pop removes and returns the top element of the stack
		public int pop() {
			return s[top--];
		}
	}

	// priority_queue structure for implementing a max-heap
	static class intHeap {
		int[] h;
		int size;

		// newIntHeap initializes a new heap with the given size
		public intHeap(int size) {
			h = new int[size+1];
			this.size = size;
		}

		// empty checks if the heap is empty
		public boolean empty() {
			return size == 0;
		}

		// peek returns the top element of the heap
		public int peek() {
			return h[1];
		}

		// pop removes and returns the top element of the heap
		public int pop() {
			int res = h[1];
			h[1] = h[size];
			size--;
			maxHeapify(1);
			return res;
		}

		// push adds an element to the heap
		public void push(int x) {
			size++;
			h[size] = x;
			int i = size;
			while (i > 1 && h[i/2] < h[i]) {
				int tmp = h[i/2];
				h[i/2] = h[i];
				h[i] = tmp;
				i /= 2;
			}
		}

		// maxHeapify maintains the max-heap property
		public void maxHeapify(int i) {
			int l = 2*i;
			int r = 2*i + 1;
			int largest = i;
			if (l <= size && h[l] > h[largest]) {
				largest = l;
			}
			if (r <= size && h[r] > h[largest]) {
				largest = r;
			}
			if (largest!= i) {
				int tmp = h[i];
				h[i] = h[largest];
				h[largest] = tmp;
				maxHeapify(largest);
			}
		}
	}

	// sortable points structure for sorting points
	static class point {
		int x;
		int y;
	}

	static class points implements Comparator<point> {
		public int compare(point a, point b) {
			if (a.x < b.x) {
				return -1;
			} else if (a.x > b.x) {
				return 1;
			} else {
				return 0;
			}
		}
	}
}

// 