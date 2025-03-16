
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	// Variables
	static int n, q;
	static int[] C;
	static List<Query> Q = new ArrayList<>();
	static int[] P = new int[500000 + 50];
	static int[] Answers = new int[500000 + 50];

	public static void main(String[] args) throws IOException {
		// Set up the input reader and output writer
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		// Read the number of elements and queries
		n = Integer.parseInt(br.readLine());
		q = Integer.parseInt(br.readLine());
		C = new int[n];

		// Initialize the position array with -1 (indicating unvisited)
		for (int i = 1; i <= n; i++) {
			P[i] = -1;
		}

		// Read each query and store it in the Q list
		for (int i = 0; i < q; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			Query query = new Query(i, l, r);
			Q.add(query);
		}

		// Sort the queries based on the right bound
		Q.sort((a, b) -> Integer.compare(a.r, b.r));
		FenwickTree ft = new FenwickTree(500000 + 50); // Initialize a Fenwick Tree for range queries

		int k = 0; // Pointer to track the current position in the input array
		// Process each query
		for (Query query : Q) {
			// Update the Fenwick Tree for all elements up to the right bound of the current query
			while (k < query.r) {
				if (P[C[k]] != -1) { // If the current value has been seen before
					ft.add(P[C[k]] + 1, -1); // Remove its previous occurrence from the Fenwick Tree
				}
				P[C[k]] = k; // Update the last position of the current value
				ft.add(k + 1, 1); // Add the current value to the Fenwick Tree

				k++; // Move to the next position
			}
			// Calculate the answer for the current query using the Fenwick Tree
			Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
		}

		// Output the answers for all queries
		for (int i = 0; i < q; i++) {
			sb.append(Answers[i] + "\n"); // Print each answer
		}
		System.out.println(sb); // Output the answers to stdout
	}

	// Fenwick Tree structure for efficient range queries
	static class FenwickTree {
		int[] dat; // Array to store the tree data
		int n; // Number of elements
		int minPow2; // Minimum power of 2 greater than or equal to n

		// Initialize a new Fenwick Tree
		public FenwickTree(int n) {
			this.n = n;

			// Calculate the minimum power of 2 greater than or equal to n
			minPow2 = 1;
			while (minPow2 << 1 <= n) {
				minPow2 <<= 1;
			}

			dat = new int[n + 1]; // Create the data array
		}

		// Calculate the prefix sum from 1 to i (1-based)
		public int sum(int i) {
			int s = 0; // Variable to hold the sum

			// Traverse the tree to calculate the sum
			for (; i > 0; i -= i & -i) {
				s += dat[i]; // Add the current index value to the sum
			}

			return s; // Return the calculated sum
		}

		// Update the Fenwick Tree by adding x to the index i (1-based)
		public void add(int i, int x) {
			// Update the tree for the given index
			for (; i <= n; i += i & -i) {
				dat[i] += x; // Add x to the current index
			}
		}

		// Return the minimum index such that the sum is greater than or equal to w
		public int lowerBound(int w) {
			if (w <= 0) {
				return 0; // If w is non-positive, return 0
			}

			int x = 0; // Variable to hold the index
			// Traverse the tree to find the lower bound
			for (int k = minPow2; k > 0; k >>= 1) {
				if (x + k <= n && dat[x + k] < w) {
					w -= dat[x + k]; // Decrease w by the current index value
					x += k; // Move to the next index
				}
			}

			return x + 1; // Return the found index (1-based)
		}
	}

	// Query struct to hold the details of each query
	static class Query {
		int idx, l, r; // Index, left, and right bounds of the query

		// Create a new query
		public Query(int idx, int l, int r) {
			this.idx = idx;
			this.l = l;
			this.r = r;
		}
	}

	// Sort the queries based on the right bound
	static void sortQueries(List<Query> Q) {
		Q.sort((a, b) -> Integer.compare(a.r, b.r));
	}

	// Print the answers for all queries
	static void printAnswers(int[] Answers) {
		for (int i = 0; i < Answers.length; i++) {
			System.out.println(Answers[i]); // Print each answer
		}
	}

	// Print the answers for all queries
	static void printAnswers(StringBuilder sb, int[] Answers) {
		for (int i = 0; i < Answers.length; i++) {
			sb.append(Answers[i] + "\n"); // Print each answer
		}
	}

	// Read a single integer
	static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}

	// Read a single integer array
	static int[] readIntArray(int n) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		return A;
	}

	// Read a single integer matrix
	static int[][] readIntMatrix(int r, int c) throws IOException {
		int[][] M = new int[r][c];
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		int[][] M = new int[r][c];
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int[][] M = new int[r][c];
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		int[][] M = new int[r][c];
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[][] M = new int[r][c];
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip, int[][] M) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip, int[][] M, int[][] N) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			N[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip, int[][] M, int[][] N, int[][] O) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			N[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			O[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip, int[][] M, int[][] N, int[][] O, int[][] P) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			N[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			O[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			P[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip, int[][] M, int[][] N, int[][] O, int[][] P, int[][] Q) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			N[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			O[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			P[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			Q[i] = readIntArray(c);
		}
		return M;
	}

	// Read a single integer matrix
	static int[][] readIntMatrixFromFile(String filename, int r, int c, int skip, int[][] M, int[][] N, int[][] O, int[][] P, int[][] Q, int[][] R) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < r; i++) {
			M[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			N[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			O[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			P[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			Q[i] = readIntArray(c);
		}
		for (int i = 0; i < r; i++) {
			R[i] = readIntArray