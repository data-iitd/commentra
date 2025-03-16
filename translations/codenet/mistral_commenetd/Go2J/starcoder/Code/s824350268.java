package main;

import java.util.Scanner;

public class Main {

	// Constants definition
	public static final int initialBufSize = 10000;
	public static final int maxBufSize = 1000000;
	public static final int mod = 1e9 + 7;

	// Variables definition and initialization
	public static Scanner sc = new Scanner(System.in);

	// Main function
	public static void main(String[] args) {
		// Read the first integer from the standard input
		int N = getInt();

		// Calculate the square root of N
		int sqrtN = (int) Math.sqrt(N);

		// Initialize the minimum number with N
		int min = N;

		// Iterate through all numbers from 1 to the square root of N
		for (int i = 1; i <= sqrtN; i++) {
			// Check if N is divisible by i
			if (N % i!= 0) {
				continue;
			}

			// Calculate the number of divisors of i and N
			int num = i + (N / i) - 2;

			// Update the minimum number if the current number is smaller
			if (num < min) {
				min = num;
			}
		}

		// Print the minimum number
		System.out.println(min);
	}

	// Define a Graph data structure
	public static class Graph {
		int n;
		int[][] edges;

		public Graph(int n) {
			this.n = n;
			edges = new int[n][];
		}

		public void addEdge(int u, int v) {
			edges[v] = append(edges[v], u);
			edges[u] = append(edges[u], v);
		}
	}

	// Initialize a new Graph with n vertices
	public static Graph newGraph(int n) {
		Graph g = new Graph(n);
		return g;
	}

	// Depth First Search function
	public static void dfs(int c, int[][] edges, boolean[] visited) {
		// Mark the current vertex as visited
		visited[c] = true;

		// Iterate through all neighbors of the current vertex
		for (int v : edges[c]) {
			// If the neighbor is already visited, skip it
			if (visited[v]) {
				continue;
			}

			// Recursively call DFS for the neighbor
			dfs(v, edges, visited);
		}
	}

	// Helper functions for reading integers and strings from the standard input
	public static int getInt() {
		sc.next();
		return Integer.parseInt(sc.next());
	}

	public static String getString() {
		sc.next();
		return sc.next();
	}

	// Helper functions for basic arithmetic operations
	public static int abs(int a) {
		return Math.abs(a);
	}

	public static int pow(int p, int q) {
		return (int) Math.pow(p, q);
	}

	public static int powMod(int n, int p) {
		// Base case: if p is 0, return 1
		if (p == 0) {
			return 1;
		} else if (p % 2 == 0) {
			// Recursive case: if p is even, square the base and recursively call powMod
			int t = powMod(n, p / 2);
			return calcMod(t * t);
		} else {
			// Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
			return calcMod(n * powMod(n, p - 1));
		}
	}

	// Helper functions for finding the minimum and maximum values
	public static int min(int... nums) {
		// Base case: if there are no numbers, panic
		if (nums.length == 0) {
			throw new IllegalArgumentException("function min() requires at least one argument.");
		}

		// Initialize the minimum value with the first number
		int res = nums[0];

		// Iterate through all numbers and update the minimum value if necessary
		for (int i = 0; i < nums.length; i++) {
			res = Math.min(res, nums[i]);
		}

		// Return the minimum value
		return res;
	}

	public static int max(int... nums) {
		// Base case: if there are no numbers, panic
		if (nums.length == 0) {
			throw new IllegalArgumentException("function max() requires at least one argument.");
		}

		// Initialize the maximum value with the first number
		int res = nums[0];

		// Iterate through all numbers and update the maximum value if necessary
		for (int i = 0; i < nums.length; i++) {
			res = Math.max(res, nums[i]);
		}

		// Return the maximum value
		return res;
	}

	// Helper function for searching a string in an array of strings
	public static boolean strSearch(String[] a, String b) {
		// Iterate through all strings in the array and return true if the target string is found
		for (int i = 0; i < a.length; i++) {
			if (a[i].equals(b)) {
				return true;
			}
		}

		// If the target string is not found, return false
		return false;
	}

	// Helper function for printing an integer array
	public static void printIntArray(int[] array) {
		// Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
		String strArray = Arrays.toString(array);
		System.out.println(strArray.substring(1, strArray.length() - 1));
	}

	// Helper function for calculating the modulo operation
	public static int calcMod(int x) {
		// Calculate the modulo of x with the modulus constant
		return x % mod;
	}

	// Helper function for reversing a string
	public static String reverse(String s) {
		// Create a StringBuilder from the input string
		StringBuilder sb = new StringBuilder(s);

		// Reverse the string in-place
		sb.reverse();

		// Convert the StringBuilder to a string and return it
		return sb.toString();
	}

	// Helper function for checking if a number is prime
	public static boolean isPrime(int n) {
		// Base case: if n is less than 2, it is not prime
		if (n < 2) {
			return false;
		}

		// Base case: if n is 2, it is prime
		if (n == 2) {
			return true;
		}

		// Base case: if n is even, it is not prime
		if (n % 2 == 0) {
			return false;
		}

		// Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
		int sqrtN = (int) Math.sqrt(n);
		for (int i = 3; i <= sqrtN; i += 2) {
			// If n is divisible by i, it is not prime
			if (n % i == 0) {
				return false;
			}
		}

		// If we have reached here, n is prime
		return true;
	}
}

