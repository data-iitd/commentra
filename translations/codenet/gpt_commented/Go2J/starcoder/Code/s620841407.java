/*
URL:
https://atcoder.jp/contests/dp/tasks/dp_v
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

/********** FAU standard libraries **********/

// Example of binary expression formatting
// System.out.printf("%64s\n", Integer.toBinaryString(n));

/********** I/O usage **********/

// Example of input reading functions
// String next() {
//     String line = br.readLine();
//     return line;
// }

// String nextLine() {
//     String line = br.readLine();
//     return line;
// }

// Integer.parseInt() equivalent
// int parseInt(String s) {
//     return Integer.parseInt(s);
// }

// Long.parseLong() equivalent
// long parseLong(String s) {
//     return Long.parseLong(s);
// }

// Short.parseShort() equivalent
// short parseShort(String s) {
//     return Short.parseShort(s);
// }

// Boolean.parseBoolean() equivalent
// boolean parseBoolean(String s) {
//     return Boolean.parseBoolean(s);
// }

// Float.parseFloat() equivalent
// float parseFloat(String s) {
//     return Float.parseFloat(s);
// }

// Double.parseDouble() equivalent
// double parseDouble(String s) {
//     return Double.parseDouble(s);
// }

// Scanner wrapper to read line using buffering
class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(InputStream stream) {
		br = new BufferedReader(new InputStreamReader(stream));
	}

	public String next() {
		while (st == null ||!st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public float nextFloat() {
		return Float.parseFloat(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}

/********** End of I/O usage **********/

// Node structure for the re-rooting solver
class Node {
	int index; // Index of the node
	int parent; // Index of the parent node
	int[] adjacents; // Adjacent nodes
	int[] indexForAdjacents; // Index mapping for adjacents
	T identity; // Identity element for operations
	Function<T, T, T> operate; // Operation function
	Function<T, Integer, T> operateNode; // Node operation function
	T[] dp; // Dynamic programming table
	T res; // Result array
}

// Constructor for Node
public Node(int nodeCount, int[][] edges, T identity, Function<T, T, T> operate, Function<T, Integer, T> operateNode) {
	// Initialize the node with parameters
	index = nodeCount;
	parent = -1;
	adjacents = new int[nodeCount];
	indexForAdjacents = new int[nodeCount];
	this.identity = identity;
	this.operate = operate;
	this.operateNode = operateNode;

	// Initialize adjacency lists
	for (int[] e : edges) {
		// Build adjacency list and index mapping
		indexForAdjacents[e[0]] = adjacents.length;
		indexForAdjacents[e[1]] = adjacents.length;
		adjacents = Arrays.copyOf(adjacents, adjacents.length + 1);
		adjacents[e[0]] = e[1];
		adjacents[e[1]] = e[0];
	}

	// Initialize DP and result arrays
	dp = new T[adjacents.length];
	res = new T[adjacents.length];

	for (int i = 0; i < adjacents.length; i++) {
		dp[i] = new T[adjacents[i].length]; // Allocate DP table
	}

	// Initialize the node if there are more than one node
	if (nodeCount > 1) {
		initialize();
	} else {
		// Base case for a single node
		res[0] = operateNode.apply(identity, 0);
	}
}

// Query function to get the result for a specific node
public T query(int node) {
	return res[node]; // Return the result for the queried node
}

// Initialize the re-rooting solver
public void initialize() {
	int[] parents, order;

	// Depth-first search to establish parent-child relationships and order of nodes
	parents = new int[index];
	order = new int[index];
	int index = 0;
	Stack<Integer> stack = new Stack<Integer>();
	stack.push(0); // Start from the root node
	parents[0] = -1; // Root has no parent
	while (!stack.isEmpty()) {
		int node = stack.pop();
		order[index] = node; // Record the order of nodes
		index++;
		for (int i = 0; i < adjacents[node].length; i++) {
			int adjacent = adjacents[node][i];
			if (adjacent == parents[node]) {
				continue; // Skip the parent node
			}
			stack.push(adjacent); // Add child to the stack
			parents[adjacent] = node; // Set parent
		}
	}

	// Process nodes from leaves to root
	for (int i = order.length - 1; i >= 1; i--) {
		int node = order[i];
		int parent = parents[node];

		T accum = identity; // Initialize accumulator
		int parentIndex = -1;
		for (int j = 0; j < adjacents[node].length; j++) {
			if (adjacents[node][j] == parent) {
				parentIndex = j; // Find index of parent
				continue;
			}
			accum = operate.apply(accum, dp[node][j]); // Accumulate results from children
		}
		dp[parent][indexForAdjacents[node][parentIndex]] = operateNode.apply(accum, node); // Update DP for parent
	}

	// Process nodes from root to leaves
	for (int i = 0; i < order.length; i++) {
		int node = order[i];
		T accum = identity; // Initialize accumulator
		T[] accumsFromTail = new T[adjacents[node].length];
		accumsFromTail[accumsFromTail.length - 1] = identity; // Initialize tail accumulator
		for (int j = accumsFromTail.length - 1; j >= 1; j--) {
			accumsFromTail[j - 1] = operate.apply(dp[node][j], accumsFromTail[j]); // Accumulate results from tail
		}
		for (int j = 0; j < accumsFromTail.length; j++) {
			// Update DP for adjacent nodes
			dp[adjacents[node][j]][indexForAdjacents[node][j]] = operateNode.apply(operate.apply(accum, accumsFromTail[j]), node);
			accum = operate.apply(accum, dp[node][j]); // Update accumulator
		}
		res[node] = operateNode.apply(accum, node); // Store result for the node
	}
}

// Main function for the program
public static void main(String[] args) {
	// Read the number of nodes and edges
	FastScanner fs = new FastScanner(System.in);
	int n = fs.nextInt();
	int m = fs.nextInt();
	// Read edges and build the adjacency list
	int[][] edges = new int[m][2];
	for (int i = 0; i < m; i++) {
		edges[i][0] = fs.nextInt() - 1;
		edges[i][1] = fs.nextInt() - 1;
	}

	// Define operations for the re-rooting solver
	Function<Integer, Integer, Integer> f = (x, y) -> (x * y) % m; // Multiplication operation
	Function<Integer, Integer, Integer> g = (v, p) -> v + 1; // Increment operation

	// Create a new re-rooting solver instance
	Node s = new Node(n, edges, 1, f, g);
	// Query results for each node and print them
	for (int i = 0; i < n; i++) {
		System.out.println(s.query(i) - 1); // Output the result for each node
	}
}

