import java.util.*;
import java.io.*;

public class Main {
	// Constants
	static int mod = (int) 1e9 + 7;

	// Data structures
	static List<ArrayList<Integer>> to;
	static int dp[];

	// Functions
	public static void main(String[] args) {
		// Initialize FastScanner
		FastScanner fs = new FastScanner(System.in);

		// Read input
		int N = fs.nextInt();

		// Initialize adjacency list
		to = new ArrayList<>();
		for(int i=0;i<N;i++) to.add(new ArrayList<Integer>());

		// Read edges
		int edges[][] = new int[N-1][2]; //どちらが子になるかdfsするまでわからないので両方持っておく
		for(int i=0;i<N-1;i++) {
			int A = fs.nextInt()-1, B = fs.nextInt()-1;
			to.get(A).add(B);
			to.get(B).add(A);
			edges[i][0] = B;
			edges[i][1] = A;
		}

		// Initialize dynamic programming array
		dp = new int[N];

		// Depth-first search and compute the depth of each vertex
		rec(0, -1);

		// Calculate the sum of mul for all edges
		long mulsum = 0;
		for(int e[]:edges) {
			// Determine the child node
			int candidate1 = e[0];
			int candidate2 = e[1];
			int child = candidate1;
			if(dp[candidate1]>dp[candidate2])child = candidate2;

			// Calculate the number of nodes in the subtree rooted at the child node
			long a = dp[child];
			long b = N - a;

			// Calculate mul for this edge
			long mul = (modpow(2, a) - 1)*(modpow(2, b) - 1)%mod;
			mulsum += mul;
			mulsum %= mod;
		}

		// Calculate the total number of cases (2^N)
		long cases = modpow(2, N);

		// Calculate the sum of nodes in all subtrees
		long PN = mulsum + (cases - 1 + mod)%mod;

		// Calculate the number of black nodes in the tree
		long BN = N * modpow(2, N-1) %mod;

		// Calculate the number of white nodes in the tree
		long WN = PN - BN;

		// Calculate the answer
		long ans = WN * modpow(cases, mod-2);
		ans %= mod;

		// Print the answer
		System.out.println(ans);
	}

	// Depth-first search function to compute the depth of each vertex
	static int rec(int v, int parent) {
		int res = 1;
		for(int next:to.get(v)) {
			if(next == parent) continue;
			res += rec(next, v);
		}
		return dp[v] = res;
	}

	// Function to calculate modular exponentiation
	static long modpow(long x, long y) {
		if(y==0) return 1;
		if(y%2!=0) return x * modpow(x, y-1) % mod;
		long tmp = modpow(x, y/2);
		return tmp * tmp % mod; 
	}
}

// FastScanner class for reading input
class FastScanner {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScanner(InputStream in) {
		reader = new BufferedReader(new InputStreamReader(in));
		tokenizer = null;
	}

	// Read next token
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

	// Read next line
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

	// Read next long integer
	public long nextLong() {
		return Long.parseLong(next());
	}

	// Read next integer
	public int nextInt() {
		return Integer.parseInt(next());
	}

	// Read next double
	public double nextDouble() {
		return Double.parseDouble(next());
	}

	// Read next integer array
	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	// Read next long integer array
	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}
}