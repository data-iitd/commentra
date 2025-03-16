import java.util.*;
import java.io.*;

public class Main {
	// Define the modulo value for all calculations
	static int mod = (int) 1e9 + 7;
	// Define the adjacency list to represent the tree
	static List<ArrayList<Integer>> to;
	// Define the dp array to store the size of each subtree
	static int dp[];

	public static void main(String[] args) {
		// Initialize the FastScanner to read input
		FastScanner fs = new FastScanner(System.in);
		// Read the number of nodes in the tree
		int N = fs.nextInt();
		// Initialize the adjacency list for the tree
		to = new ArrayList<>();
		for(int i=0; i<N; i++) to.add(new ArrayList<Integer>());
		// Initialize the edges array to store parent-child relationships
		int edges[][] = new int[N-1][2];
		// Read the edges of the tree and populate the adjacency list and edges array
		for(int i=0; i<N-1; i++) {
			int A = fs.nextInt() - 1, B = fs.nextInt() - 1;
			to.get(A).add(B);
			to.get(B).add(A);
			edges[i][0] = B;
			edges[i][1] = A;
		}
		// Initialize the dp array for subtree sizes
		dp = new int[N];
		// Perform a DFS to populate the dp array with subtree sizes
		rec(0, -1);
		// Initialize the sum for the multiplication results
		long mulsum = 0;
		// Iterate over each edge to calculate the probability
		for(int e[]: edges) {
			// Determine which node is the child in the current edge
			int candidate1 = e[0];
			int candidate2 = e[1];
			int child = candidate1;
			if(dp[candidate1] > dp[candidate2]) child = candidate2;
			// Calculate the sizes of the two subtrees created by the edge
			long a = dp[child];
			long b = N - a;
			// Calculate the multiplication factor for this edge
			long mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod;
			mulsum += mul;
			mulsum %= mod;
		}
		// Calculate the total number of cases
		long cases = modpow(2, N);
		// Calculate the total number of nodes in all cases
		long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
		// Calculate the expected number of black nodes
		long BN = N * modpow(2, N-1) % mod;
		long WN = (PN - BN + mod) % mod;
		long ans = WN * modpow(cases, mod-2) % mod;
		// Output the final result
		System.out.println(ans);
	}

	// DFS function to calculate the size of each subtree
	static int rec(int v, int parent) {
		int res = 1;
		for(int next: to.get(v)) {
			if(next == parent) continue;
			res += rec(next, v);
		}
		return dp[v] = res;
	}

	// Function to perform modular exponentiation
	static long modpow(long x, long y) {
		if(y == 0) return 1;
		if(y % 2 != 0) return x * modpow(x, y-1) % mod;
		long tmp = modpow(x, y/2);
		return tmp * tmp % mod;
	}
}

// FastScanner class to read input efficiently
class FastScanner {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScanner(InputStream in) {
		reader = new BufferedReader(new InputStreamReader(in));
		tokenizer = null;
	}

	public String next() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken("\n");
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}
}