package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		// IO
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String line;

		// PARSE HELPER SESSION
		// Read and log the input values
		int X = Integer.parseInt(br.readLine()); // Read an integer
		System.out.println(X); // Log the integer
		int N = Integer.parseInt(br.readLine()); // Read the size of the array
		System.out.println(N); // Log the size
		int[] p = new int[N];
		for (int i = 0; i < N; i++) {
			p[i] = Integer.parseInt(br.readLine()); // Read integers into the array p
		}
		System.out.println("p " + Arrays.toString(p[0:10])); // Log the first 10 elements of p

		// Check for numbers around X that are not in the array p
		for (int i = 0; i <= 100; i++) {
			if (find(X - i) == 1) { // Check X - i
				bw.write(Integer.toString(X - i) + "\n"); // Print the result
				bw.flush();
				return;
			}
			if (find(X + i) == 1) { // Check X + i
				bw.write(Integer.toString(X + i) + "\n"); // Print the result
				bw.flush();
				return;
			}
		}

		// OUTPUT GENERATION PART
		// ans := 0
		// bw.write(Integer.toString(ans) + "\n");

		// if (ans > 0) {
		//   bw.write("Yes\n");
		// } else {
		//   bw.write("No\n");
		// }

		// BFS/DFS PART
		// visited := new int[0];
		// bfs(1, neighbor, func(node int) {
		// 	visited = append(visited, node);
		// });
		// bw.write(Arrays.toString(visited) + "\n");

		// DFS 2
		// var dp = new int[2000000];
		// var nei = new HashMap<Integer, List<Integer>>();
		// nei.put(0, Arrays.asList(1, 2));
		// nei.put(1, Arrays.asList(0));
		// nei.put(2, Arrays.asList(0, 3));
		// nei.put(3, Arrays.asList(2));
		// dfs2(0, nei, func(n, p) {
		// 	System.out.printf("%d -> %d\n", p, n);
		// 	dp[n] = p;
		// }, func(n, p) {
		// 	System.out.printf("%d -> %d\n", n, p);
		// });
		// System.out.println(Arrays.toString(dp[0:5]));

		// COMBINATION
		// bw.write(Integer.toString(N) + " " + Integer.toString(M) + " " + Integer.toString(Math.max(N, M)) + "\n");
		// bw.write("Lucas " + Integer.toString(combMod(N, M, 13)) + " " + Integer.toString(combination(N, M)) + "\n");

		// bw.flush();
		// br.close();
		// bw.close();
	}

	// Function to check if a number exists in the array p
	public static int find(int n) {
		for (int i = 0; i < N; i++) {
			if (n == p[i]) {
				return 0; // Number found
			}
		}
		return 1; // Number not found
	}

	// Main solving function
	public static void solve() {
		// IO
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String line;

		// PARSE HELPER SESSION
		// Read and log the input values
		int X = Integer.parseInt(br.readLine()); // Read an integer
		System.out.println(X); // Log the integer
		int N = Integer.parseInt(br.readLine()); // Read the size of the array
		System.out.println(N); // Log the size
		int[] p = new int[N];
		for (int i = 0; i < N; i++) {
			p[i] = Integer.parseInt(br.readLine()); // Read integers into the array p
		}
		System.out.println("p " + Arrays.toString(p[0:10])); // Log the first 10 elements of p

		// Check for numbers around X that are not in the array p
		for (int i = 0; i <= 100; i++) {
			if (find(X - i) == 1) { // Check X - i
				bw.write(Integer.toString(X - i) + "\n"); // Print the result
				bw.flush();
				return;
			}
			if (find(X + i) == 1) { // Check X + i
				bw.write(Integer.toString(X + i) + "\n"); // Print the result
				bw.flush();
				return;
			}
		}

		// OUTPUT GENERATION PART
		// ans := 0
		// bw.write(Integer.toString(ans) + "\n");

		// if (ans > 0) {
		//   bw.write("Yes\n");
		// } else {
		//   bw.write("No\n");
		// }

		// BFS/DFS PART
		// visited := new int[0];
		// bfs(1, neighbor, func(node int) {
		// 	visited = append(visited, node);
		// });
		// bw.write(Arrays.toString(visited) + "\n");

		// DFS 2
		// var dp = new int[2000000];
		// var nei = new HashMap<Integer, List<Integer>>();
		// nei.put(0, Arrays.asList(1, 2));
		// nei.put(1, Arrays.asList(0));
		// nei.put(2, Arrays.asList(0, 3));
		// nei.put(3, Arrays.asList(2));
		// dfs2(0, nei, func(n, p) {
		// 	System.out.printf("%d -> %d\n", p, n);
		// 	dp[n] = p;
		// }, func(n, p) {
		// 	System.out.printf("%d -> %d\n", n, p);
		// });
		// System.out.println(Arrays.toString(dp[0:5]));

		// COMBINATION
		// bw.write(Integer.toString(N) + " " + Integer.toString(M) + " " + Integer.toString(Math.max(N, M)) + "\n");
		// bw.write("Lucas " + Integer.toString(combMod(N, M, 13)) + " " + Integer.toString(combination(N, M)) + "\n");

		// bw.flush();
		// br.close();
		// bw.close();
	}

	// Main function to execute the program
	public static void main(String[] args) throws Exception {
		// IO
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String line;

		// PARSE HELPER SESSION
		// Read and log the input values
		int X = Integer.parseInt(br.readLine()); // Read an integer
		System.out.println(X); // Log the integer
		int N = Integer.parseInt(br.readLine()); // Read the size of the array
		System.out.println(N); // Log the size
		int[] p = new int[N];
		for (int i = 0; i < N; i++) {
			p[i] = Integer.parseInt(br.readLine()); // Read integers into the array p
		}
		System.out.println("p " + Arrays.toString(p[0:10])); // Log the first 10 elements of p

		// Check for numbers around X that are not in the array p
		for (int i = 0; i <= 100; i++) {
			if (find(X - i) == 1) { // Check X - i
				bw.write(Integer.toString(X - i) + "\n"); // Print the result
				bw.flush();
				return;
			}
			if (find(X + i) == 1) { // Check X + i
				bw.write(Integer.toString(X + i) + "\n"); // Print the result
				bw.flush();
				return;
			}
		}

		// OUTPUT GENERATION PART
		// ans := 0
		// bw.write(Integer.toString(ans) + "\n");

		// if (ans > 0) {
		//   bw.write("Yes\n");
		// } else {
		//   bw.write("No\n");
		// }

		// BFS/DFS PART
		// visited := new int[0];
		// bfs(1, neighbor, func(node int) {
		// 	visited = append(visited, node);
		// });
		// bw.write(Arrays.toString(visited) + "\n");

		// DFS 2
		// var dp = new int[2000000];
		// var nei = new HashMap<Integer, List<Integer>>();
		// nei.put(0, Arrays.asList(1, 2));
		// nei.put(1, Arrays.asList(0));
		// nei.put(2, Arrays.asList(0, 3));
		// nei.put(3, Arrays.asList(2));
		// dfs2(0, nei, func(n, p) {
		// 	System.out.printf("%d -> %d\n", p, n);
		// 	dp[n] = p;
		// }, func(n, p) {
		// 	System.out.printf("%d -> %d\n", n, p);
		// });
		// System.out.println(Arrays.toString(dp[0:5]));

		// COMBINATION
		// bw.write(Integer.toString(N) + " " + Integer.toString(M) + " " + Integer.toString(Math.max(N, M)) + "\n");
		// bw.write("Lucas " + Integer.toString(combMod(N, M, 13)) + " " + Integer.toString(combination(N, M)) + "\n");

		// bw.flush();
		// br.close();
		// bw.close();
	}

	// Libraries

	// Io helps parsing inputs from standard input for programming contests.
	public static class Io {
		private BufferedReader reader;
		private BufferedWriter writer;
		private String[] tokens;
		private int nextToken;

		// Constructor
		public Io() {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new BufferedWriter(new OutputStreamWriter(System.out));
			nextToken = 0;
		}

		// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
		public void Flush() throws Exception {
			writer.flush();
		}

		// NextLine parses line as string.
		public String NextLine() throws Exception {
			String line = reader.readLine();
			if (line == null) {
				return null;
			}
			return line;
		}

		// Next parse next word as string.
		public String Next() throws Exception {
			while (nextToken >= tokens.length) {
				String line = reader.readLine();
				if (line == null) {
					return null;
				}
				tokens = line.split(" ");
				nextToken = 0;
			}
			return tokens[nextToken++];
		}

		// NextInt parse next word as Int.
		public int NextInt() throws Exception {
			return Integer.parseInt(Next());
		}

		// NextFloat parses next word as float64.
		public double NextFloat() throws Exception {
			return Double.parseDouble(Next());
		}

		// PrintLn does buffer write with linefeed.
		public void PrintLn(Object... objects) throws Exception {
			for (int i = 0; i < objects.length; i++) {
				if (i!= 0) {
					writer.write(" ");
				}
				writer.write(objects[i].toString());
			}
			writer.write("\n");
		}

		// Printf does formatted buffer write.
		public void Printf(String format, Object... objects) throws Exception {
			writer.write(String.format(format, objects));
		}

		// PrintIntLn prints Int array in a single line.
		public void PrintIntLn(int[] a) throws Exception {
			PrintLn(Arrays.toString(a));
		}

		// PrintStringLn prints string array in a single line.
		public void PrintStringLn(String[] a) throws Exception {
			PrintLn(Arrays.toString(a));
		}

		// Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
		public void Log(String name, Object value) {
			System.err.printf("%s=%+v\n", name, value);
		}

		// Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
		public void Logf(String format, Object... objects) {
			System.err.printf(format, objects);
		}

		// Helper functions for mathematical operations

		// Returns the minimum of two integers
		public int intMin(int a, int b) {
			if (a < b) {
				return a;
			}
			return b;
		}

		// Returns the maximum of two integers
		public int intMax(int a, int b) {
			if (a > b) {
				return a;
			}
			return b;
		}

		// Direct calculation of combination
		// n, m should be "small"
		public int combination(int n, i