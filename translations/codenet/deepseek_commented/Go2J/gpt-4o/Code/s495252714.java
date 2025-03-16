import java.util.*;
import java.io.*;

// Main class
public class Main {
    // Define the constant for modular arithmetic.
    static final int MOD = 1000000007;

    // Function to perform modular exponentiation.
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
        // Initialize buffered reader and writer for efficient I/O operations.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);

        // Read the number of elements.
        int n = Integer.parseInt(br.readLine().trim());

        // Read n integers into a list.
        int[] c = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(st.nextToken());
        }

        // Initialize the answer variable.
        long ans = 0;

        // Sort the array of integers.
        Arrays.sort(c);

        // Calculate the answer based on the sorted array.
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)(n + 1 - i) * c[i] % MOD) % MOD;
        }

        // Print the final answer, multiplied by 4^(n-1) modulo MOD.
        wr.println((ans * modpow(4, n - 1)) % MOD);
        wr.flush();
    }
}
//<END-OF-CODE>
