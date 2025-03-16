import java.util.*;
import java.io.*;

// Main class
public class Main {
    // Define a constant for the modulus
    static final int MOD = 1000000007;

    // Function to perform modular exponentiation
    static int modpow(int a, int n) {
        int res = 1; // Initialize result
        while (n > 0) {
            if ((n & 1) == 1) { // If n is odd
                res = (int)((1L * res * a) % MOD); // Update result
            }
            a = (int)((1L * a * a) % MOD); // Square the base
            n >>= 1; // Divide n by 2
        }
        return res; // Return the final result
    }

    // Main function where execution starts
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // Read the number of integers
        int[] c = new int[n]; // Create an array to hold n integers

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(st.nextToken()); // Fill the array with integers from input
        }

        long ans = 0; // Initialize answer variable
        Arrays.sort(c); // Sort the array of integers

        // Calculate the answer based on the sorted integers
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)(n + 1 - i) * c[i] % MOD) % MOD; // Update the answer using the formula
        }

        // Print the final result after applying modular exponentiation
        pw.println(ans * modpow(4, n - 1) % MOD);
        pw.flush(); // Ensure all output is written
    }
}
//<END-OF-CODE>
