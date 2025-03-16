import java.util.*;
import java.io.*;

public class Main {
    static int mod = (int) 1e9 + 7; // Define a modulus for calculations
    static List<ArrayList<Integer>> to; // Adjacency list to represent the tree
    static int dp[]; // Array to store the size of subtrees

    public static void main(String[] args) {
        FastScanner fs = new FastScanner(System.in); // Initialize fast input scanner
        int N = fs.nextInt(); // Read the number of nodes
        to = new ArrayList<>(); // Initialize the adjacency list
        for(int i = 0; i < N; i++) to.add(new ArrayList<Integer>()); // Create empty lists for each node

        int edges[][] = new int[N-1][2]; // Array to store edges, both directions for DFS
        for(int i = 0; i < N - 1; i++) {
            int A = fs.nextInt() - 1, B = fs.nextInt() - 1; // Read edges and adjust for 0-based index
            to.get(A).add(B); // Add edge A-B to the adjacency list
            to.get(B).add(A); // Add edge B-A to the adjacency list
            edges[i][0] = B; // Store edge in both directions
            edges[i][1] = A;
        }

        dp = new int[N]; // Initialize the dp array
        rec(0, -1); // Perform DFS starting from node 0 with no parent

        long mulsum = 0; // Variable to accumulate the multiplication sums
        for(int e[] : edges) {
            // Determine which node is the child based on subtree sizes
            int candidate1 = e[0];
            int candidate2 = e[1];
            int child = candidate1;
            if(dp[candidate1] > dp[candidate2]) child = candidate2; // Choose the smaller subtree

            long a = dp[child]; // Size of the child subtree
            long b = N - a; // Size of the other part of the tree

            // Calculate the contribution of this edge to the total count
            long mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod; // Calculate the number of valid configurations
            mulsum += mul; // Add to the total multiplication sum
            mulsum %= mod; // Ensure the result is within modulus
        }

        long cases = modpow(2, N); // Total number of cases (2^N)
        // Calculate the total number of vertices included in S
        long PN = (mulsum + (cases - 1 + mod) % mod) % mod; // Total vertices in S

        // Calculate the number of black and white vertices in S
        long BN = N * modpow(2, N - 1) % mod; // Total black vertices in S
        long WN = (PN - BN + mod) % mod; // Total white vertices in S
        long ans = WN * modpow(cases, mod - 2) % mod; // Final answer calculation
        System.out.println(ans); // Output the result
    }

    // Recursive function to calculate the size of each subtree
    static int rec(int v, int parent) {
        int res = 1; // Initialize size of the subtree
        for(int next : to.get(v)) {
            if(next == parent) continue; // Skip the parent node to avoid cycles
            res += rec(next, v); // Recursively calculate the size of the subtree
        }
        return dp[v] = res; // Store the result in dp array
    }

    // Function to compute (x^y) % mod using fast exponentiation
    static long modpow(long x, long y) {
        if(y == 0) return 1; // Base case
        if(y % 2 != 0) return x * modpow(x, y - 1) % mod; // If y is odd
        long tmp = modpow(x, y / 2); // Recursive call for y/2
        return tmp * tmp % mod; // Combine results
    }
}

// Fast input scanner class for efficient reading
class FastScanner {
    private BufferedReader reader = null; // BufferedReader for fast input
    private StringTokenizer tokenizer = null; // Tokenizer for parsing input

    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in)); // Initialize reader
        tokenizer = null; // Initialize tokenizer
    }

    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine()); // Read a new line
            } catch (IOException e) {
                throw new RuntimeException(e); // Handle IOException
            }
        }
        return tokenizer.nextToken(); // Return the next token
    }

    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine(); // Read a full line
            } catch (IOException e) {
                throw new RuntimeException(e); // Handle IOException
            }
        }
        return tokenizer.nextToken("\n"); // Return the next line token
    }

    public long nextLong() {
        return Long.parseLong(next()); // Parse and return the next long
    }

    public int nextInt() {
        return Integer.parseInt(next()); // Parse and return the next int
    }

    public double nextDouble() {
        return Double.parseDouble(next()); // Parse and return the next double
    }

    public int[] nextIntArray(int n) {
        int[] a = new int[n]; // Create an array of size n
        for (int i = 0; i < n; i++)
            a[i] = nextInt(); // Fill the array with integers
        return a; // Return the array
    }

    public long[] nextLongArray(int n) {
        long[] a = new long[n]; // Create an array of size n
        for (int i = 0; i < n; i++)
            a[i] = nextLong(); // Fill the array with longs
        return a; // Return the array
    }
}
