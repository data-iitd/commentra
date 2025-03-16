import javax.swing.text.Style;
import java.io.*;
import java.util.*;

public class Main {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////                                                                                                               /////////
    ////////                                                                                                               /////////
    ////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
    ////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMMMM      MMMMMM      OOO      OOO        SSSS   SSS     EEEEEEEEEEEEE  /////////
    ////////   HHHH        HHHH  EEEEE           MMMM MMM  MMM MMMM    OOO          OOO    SSSS       SSS   EEEEE          /////////
    ////////   HHHH        HHHH  EEEEE           MMMM  MMMMMM  MMMM   OOO            OOO   SSSS             EEEEE          /////////
    ////////   HHHH        HHHH  EEEEE           MMMM          MMMM  OOO              OOO   SSSSSSS         EEEEE          /////////
    ////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO      SSSSSS       EEEEEEEEEEE    /////////
    ////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO         SSSSSSS   EEEEEEEEEEE    /////////
    ////////   HHHH        HHHH  EEEEE           MMMM          MMMM   OOO            OOO              SSSS  EEEEE          /////////
    ////////   HHHH        HHHH  EEEEE           MMMM          MMMM    OOO          OOO     SSS       SSSS  EEEEE          /////////
    ////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM      OOO      OOO        SSS    SSSS    EEEEEEEEEEEEE  /////////
    ////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
    ////////                                                                                                               /////////
    ////////                                                                                                               /////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Class to represent a pair of integers
    static class Pair {
        int l, r; // Left and right values

        // Constructor to initialize the pair
        Pair(int a, int b) {
            l = a;
            r = b;
        }

        // Override toString method to return the pair as a string
        @Override
        public String toString() {
            return l + " " + r;
        }
    }

    // Memoization array to store results of subproblems
    static int[][][] memo;
    // 2D array to store input values
    static int[][] a;
    // Number of elements
    static int n;

    // Dynamic programming function to compute the minimum flips required
    static int dp(int flipped, int idx, int msk) {
        // Base case: if all elements are flipped
        if (msk == (1 << n) - 1) return 0;

        // Return cached result if already computed
        if (memo[flipped][idx][msk] != -1) return memo[flipped][idx][msk];

        int x = Integer.bitCount(msk); // Count of flipped elements
        int ff = 0; // Counter for the number of flips
        int ans = (int) 1e9; // Initialize answer to a large value

        // Iterate through all elements
        for (int i = 0; i < n; i++) {
            // Check if the current element is not flipped
            if ((msk & (1 << i)) == 0) {
                int nf = x % 2; // Determine the next flip state
                // Check if the current index is valid for the flip
                if (idx == n || a[flipped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                    // Recursively compute the minimum flips required
                    ans = Math.min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i));
                }
                ff++; // Increment the flip counter
            } else {
                x--; // Decrement the count of flipped elements
            }
        }
        // Cache the result before returning
        return memo[flipped][idx][msk] = ans;
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        // Initialize scanner for input
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        // Read the number of elements
        n = sc.nextInt();
        a = new int[2][n]; // Initialize the array to store input values

        // Read the first set of values
        for (int i = 0; i < n; i++) a[0][i] = sc.nextInt();
        // Read the second set of values
        for (int i = 0; i < n; i++) a[1][i] = sc.nextInt();

        // Initialize the memoization array
        memo = new int[2][n + 1][1 << n];
        for (int[][] z : memo) for (int[] x : z) Arrays.fill(x, -1); // Fill with -1

        // Compute the answer using the dp function
        int ans = dp(0, n, 0);
        // Print the result, -1 if no valid flips found
        pw.println(ans >= 1e8 ? -1 : ans);
        pw.flush(); // Flush the output
    }

    // Custom scanner class for input handling
    static class Scanner {
        StringTokenizer st; // Tokenizer for input
        BufferedReader br; // Buffered reader for input

        // Constructor for file reader
        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        // Constructor for input stream
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        // Method to read the next token
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        // Method to read the next integer
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        // Method to read the next long
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        // Method to read the next line
        public String nextLine() throws IOException {
            return br.readLine();
        }

        // Method to read the next double
        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        // Method to check if the input is ready
        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}
