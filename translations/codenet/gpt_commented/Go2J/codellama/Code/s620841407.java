
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	// Constants for general purpose usage
	private static final int MOD = 1000000007;
	private static final int ALPHABET_NUM = 26;
	private static final int INF_INT = Integer.MAX_VALUE;
	private static final int INF_BIT = 1 << 30;
	private static final int NIL = -1;

	// Constants for graph algorithms
	private static final int WHITE = 0;
	private static final int GRAY = 1;
	private static final int BLACK = 2;

	// Type definition for generic operations
	private static class T {
		int value;

		public T(int value) {
			this.value = value;
		}
	}

	// Structure for the re-rooting solver
	private static class ReRootingSolver {
		int nodeCount;
		List<List<Integer>> adjacents;
		List<List<Integer>> indexForAdjacents;
		List<T> res;
		List<List<T>> dp;

		T identity;
		T operate(T l, T r) {
			return new T((l.value * r.value) % MOD);
		}
		T operateNode(T v, int p) {
			return new T((v.value + 1) % MOD);
		}

		public ReRootingSolver(int nodeCount, List<List<Integer>> edges, T identity, T operate, T operateNode) {
			this.nodeCount = nodeCount;
			this.identity = identity;
			this.operate = operate;
			this.operateNode = operateNode;

			// Initialize adjacency lists
			this.adjacents = new ArrayList<>(nodeCount);
			this.indexForAdjacents = new ArrayList<>(nodeCount);
			for (int i = 0; i < nodeCount; i++) {
				this.adjacents.add(new ArrayList<>());
				this.indexForAdjacents.add(new ArrayList<>());
			}
			for (List<Integer> e : edges) {
				// Build adjacency list and index mapping
				this.indexForAdjacents.get(e.get(0)).add(this.adjacents.get(e.get(1)).size());
				this.indexForAdjacents.get(e.get(1)).add(this.adjacents.get(e.get(0)).size());
				this.adjacents.get(e.get(0)).add(e.get(1));
				this.adjacents.get(e.get(1)).add(e.get(0));
			}

			// Initialize DP and result arrays
			this.dp = new ArrayList<>(nodeCount);
			this.res = new ArrayList<>(nodeCount);

			for (int i = 0; i < nodeCount; i++) {
				this.dp.add(new ArrayList<>(nodeCount)); // Allocate DP table
			}

			// Initialize the solver if there are more than one node
			if (this.nodeCount > 1) {
				this.initialize();
			} else {
				// Base case for a single node
				this.res.set(0, this.operateNode(this.identity, 0));
			}
		}

		// Query function to get the result for a specific node
		public T query(int node) {
			return this.res.get(node); // Return the result for the queried node
		}

		// Initialize the re-rooting solver
		public void initialize() {
			int[] parents = new int[this.nodeCount];
			int[] order = new int[this.nodeCount];

			// Depth-first search to establish parent-child relationships and order of nodes
			int index = 0;
			Stack<Integer> stack = new Stack<>();
			stack.push(0); // Start from the root node
			parents[0] = -1; // Root has no parent
			while (!stack.isEmpty()) {
				int node = stack.pop();
				order[index] = node; // Record the order of nodes
				index++;
				for (int i = 0; i < this.adjacents.get(node).size(); i++) {
					int adjacent = this.adjacents.get(node).get(i);
					if (adjacent == parents[node]) {
						continue; // Skip the parent node
					}
					stack.push(adjacent); // Add child to the stack
					parents[adjacent] = node; // Set parent
				}
			}

			// Process nodes from leaves to root
			for (int i = this.nodeCount - 1; i >= 1; i--) {
				int node = order[i];
				int parent = parents[node];

				T accum = this.identity; // Initialize accumulator
				int parentIndex = -1;
				for (int j = 0; j < this.adjacents.get(node).size(); j++) {
					if (this.adjacents.get(node).get(j) == parent) {
						parentIndex = j; // Find index of parent
						continue;
					}
					accum = this.operate(accum, this.dp.get(node).get(j)); // Accumulate results from children
				}
				this.dp.get(parent).set(this.indexForAdjacents.get(node).get(parentIndex), this.operateNode(accum, node)); // Update DP for parent
			}

			// Process nodes from root to leaves
			for (int i = 0; i < this.nodeCount; i++) {
				int node = order[i];
				T accum = this.identity; // Initialize accumulator
				T[] accumsFromTail = new T[this.adjacents.get(node).size()];
				accumsFromTail[accumsFromTail.length - 1] = this.identity; // Initialize tail accumulator
				for (int j = accumsFromTail.length - 1; j >= 1; j--) {
					accumsFromTail[j - 1] = this.operate(this.dp.get(node).get(j), accumsFromTail[j]); // Accumulate results from tail
				}
				for (int j = 0; j < accumsFromTail.length; j++) {
					// Update DP for adjacent nodes
					this.dp.get(this.adjacents.get(node).get(j)).set(this.indexForAdjacents.get(node).get(j), this.operateNode(this.operate(accum, accumsFromTail[j]), node));
					accum = this.operate(accum, this.dp.get(node).get(j)); // Update accumulator
				}
				this.res.set(node, this.operateNode(accum, node)); // Store result for the node
			}
		}
	}

	// Function to create a new input reading function
	private static BufferedReader newReadString(InputStreamReader ior) {
		BufferedReader br = new BufferedReader(ior);
		StringBuilder sb = new StringBuilder();
		return new BufferedReader() {
			@Override
			public String readLine() throws IOException {
				while (true) {
					int c = read();
					if (c == -1 || c == '\n') {
						break;
					}
					sb.append((char) c);
				}
				String res = sb.toString();
				sb.setLength(0);
				return res;
			}

			@Override
			public int read(char[] cbuf, int off, int len) throws IOException {
				return br.read(cbuf, off, len);
			}

			@Override
			public int read() throws IOException {
				return br.read();
			}
		};
	}

	// Function to read an integer
	private static int readInt() throws IOException {
		StringBuilder sb = new StringBuilder();
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		do {
			sb.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return Integer.parseInt(sb.toString());
	}

	// Function to read an integer array
	private static int[] readIntArray(int n) throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = readInt();
		}
		return A;
	}

	// Function to read an integer matrix
	private static int[][] readIntMatrix(int r, int c) throws IOException {
		int[][] mat = new int[r][c];
		for (int i = 0; i < r; i++) {
			mat[i] = readIntArray(c);
		}
		return mat;
	}

	// Function to read a long
	private static long readLong() throws IOException {
		StringBuilder sb = new StringBuilder();
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		do {
			sb.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return Long.parseLong(sb.toString());
	}

	// Function to read a long array
	private static long[] readLongArray(int n) throws IOException {
		long[] A = new long[n];
		for (int i = 0; i < n; i++) {
			A[i] = readLong();
		}
		return A;
	}

	// Function to read a long matrix
	private static long[][] readLongMatrix(int r, int c) throws IOException {
		long[][] mat = new long[r][c];
		for (int i = 0; i < r; i++) {
			mat[i] = readLongArray(c);
		}
		return mat;
	}

	// Function to check whether a character is a space character
	private static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	// Function to print an integer array
	private static void printIntArray(int[] A) {
		for (int i = 0; i < A.length; i++) {
			System.out.print(A[i] + " ");
		}
		System.out.println();
	}

	// Function to print an integer matrix
	private static void printIntMatrix(int[][] mat) {
		for (int[] row : mat) {
			for (int e : row) {
				System.out.print(e + " ");
			}
			System.out.println();
		}
	}

	// Function to print a long array
	private static void printLongArray(long[] A) {
		for (long e : A) {
			System.out.print(e + " ");
		}
		System.out.println();
	}

	// Function to print a long matrix
	private static void printLongMatrix(long[][] mat) {
		for (long[] row : mat) {
			for (long e : row) {
				System.out.print(e + " ");
			}
			System.out.println();
		}
	}

	// Function to print a string array
	private static void printStringArray(String[] A) {
		for (String e : A) {
			System.out.print(e + " ");
		}
		System.out.println();
	}

	// Function to print a string matrix
	private static void printStringMatrix(String[][] mat) {
		for (String[] row : mat) {
			for (String e : row) {
				System.out.print(e + " ");
			}
			System.out.println();
		}
	}

	// Function to print a boolean array
	private static void printBooleanArray(boolean[] A) {
		for (boolean e : A) {
			System.out.print(e + " ");
		}
		System.out.println();
	}

	// Function to print a boolean matrix
	private static void printBooleanMatrix(boolean[][] mat) {
		for (boolean[] row : mat) {
			for (boolean