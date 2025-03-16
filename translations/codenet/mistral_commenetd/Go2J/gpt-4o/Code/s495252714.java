import java.util.*;
import java.io.*;

// Main class
public class Main {
    // Constants
    static final int MOD = 1000000007;

    // Function to read an integer from standard input
    static int scanInt() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return Integer.parseInt(br.readLine());
    }

    // Function to read n integers from standard input
    static int[] scanInts(int n) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] res = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            res[i] = Integer.parseInt(st.nextToken());
        }
        return res;
    }

    // Function to calculate modular exponentiation
    static int modpow(int a, int n) {
        int res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = (int)((1L * res * a) % MOD);
            }
            a = (int)((1L * a * a) % MOD);
            n >>= 1;
        }
        return res;
    }

    // Main function
    public static void main(String[] args) throws IOException {
        // Read an integer n from standard input
        int n = scanInt();

        // Read n integers c from standard input and store them in an array
        int[] c = scanInts(n);

        // Initialize answer variable to 0
        long ans = 0;

        // Sort array c in ascending order
        Arrays.sort(c);

        // Iterate through array c and calculate answer
        for (int i = 0; i < n; i++) {
            // Calculate contribution of current integer to answer
            ans = (ans + (long)(n + 1 - i) * c[i] % MOD) % MOD;
        }

        // Calculate final answer by multiplying answer with (4^(n-1)) modulo MOD
        System.out.println(ans * modpow(4, n - 1) % MOD);
    }
}
// <END-OF-CODE>
