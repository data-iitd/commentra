// Import required packages
import javax.swing.text.Style;
import java.io.*;
import java.util.*;

// Define a static inner class Pair to represent a pair of integers
static class Pair {
    int l, r;

    // Constructor for Pair
    Pair(int a, int b) {
        l = a;
        r = b;
    }

    // Override toString method to return a string representation of the pair
    @Override
    public String toString() {
        return l + " " + r;
    }
}

// Declare static variables and arrays
static int[][][] memo;
static int[][] a;
static int n;

// Define a recursive function dp to find the minimum number of flips required to make both arrays equal
static int dp(int fliped, int idx, int msk) {
    // Base case: if all bits are set, return 0
    if (msk == (1 << n) - 1) return 0;

    // Memoization: if the result is already computed, return it
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];

    // Calculate the number of set bits in the mask
    int x = Integer.bitCount(msk);

    // Initialize variables for the loop
    int ff = 0;
    int ans = (int) 1e9;

    // Iterate through all possible indices i
    for (int i = 0; i < n; i++) {
        // If the current bit is not set in the mask, process it
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;

            // Check if the current index idx is the last index or the current element is smaller than the corresponding element in the other array
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                // Recursively call the dp function with the updated parameters and calculate the minimum number of flips
                ans = Math.min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i));
            }

            // Increment the counter ff
            ff++;

            // Decrement the number of set bits in the mask
            x--;
        }
    }

    // Memoization: store the calculated result in the memo table
    return memo[fliped][idx][msk] = ans;
}

// Define the main function to read input and call the dp function
public static void main(String[] args) throws IOException, InterruptedException {
    // Initialize the scanner and print writer objects
    Scanner sc = new Scanner(System.in);
    PrintWriter pw = new PrintWriter(System.out);

    // Read the number of elements in the arrays
    n = sc.nextInt();

    // Initialize the 2D array a with the given input
    a = new int[2][n];
    for (int i = 0; i < n; i++) a[0][i] = sc.nextInt();
    for (int i = 0; i < n; i++) a[1][i] = sc.nextInt();

    // Initialize the memo table with -1 values
    memo = new int[2][n + 1][1 << n];
    for (int[][] z : memo) for (int[] x : z) Arrays.fill(x, -1);

    // Call the dp function and print the result
    int ans = dp(0, n, 0);
    pw.println(ans >= 1e8 ? -1 : ans);

    // Close the scanner and print writer objects
    sc.close();
    pw.close();
}

// Define a custom Scanner class to read input efficiently
static class Scanner {
    StringTokenizer st;
    BufferedReader br;

    // Constructor for the Scanner class
    public Scanner(FileReader r) {
        br = new BufferedReader(r);
    }

    public Scanner(InputStream s) {
        br = new BufferedReader(new InputStreamReader(s));
    }

    // Read the next token as a string
    public String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    // Read the next integer
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    // Read the next long integer
    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    // Read the next line as a string
    public String nextLine() throws IOException {
        return br.readLine();
    }

    // Read the next double
    public double nextDouble() throws IOException {
        String x = next();
        StringBuilder sb = new StringBuilder("0");
        double res = 0, f = 1;
        boolean dec = false, neg = false;
        int start = 0;

        // Handle negative numbers
        if (x.charAt(0) == '-') {
            neg = true;
            start++;
        }

        // Parse the number using StringBuilder and return the result
        for (int i = start; i < x.length(); i++) {
            char c = x.charAt(i);
            if (c == '.') {
                res = Long.parseLong(sb.toString());
                sb = new StringBuilder("0");
                dec = true;
            } else {
                sb.append(c);
                if (dec) f *= 10;
            }
        }
        res += Long.parseLong(sb.toString()) / f;
        return res * (neg ? -1 : 1);
    }

    // Check if there is more input available
    public boolean ready() throws IOException {
        return br.ready();
    }
}