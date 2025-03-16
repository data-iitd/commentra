import java.util.*;
import java.io.*;

public class Main {
    // Define the modulo constant
    static final long MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // Read the integer input N
        int N = Integer.parseInt(input.readLine().trim());

        // Define a constant for the maximum size
        int M = 1000000;

        // Read the array A from input
        long[] A = new long[N];
        st = new StringTokenizer(input.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }

        // Define the size for factorial calculations
        int Nsq = 1000;

        // Initialize a 2D array to store factorial values
        long[][] fact = new long[Nsq][Nsq];

        // Set the first factorial value
        fact[0][0] = 1;

        // Compute factorial values for columns
        for (int n = 1; n < Nsq; n++) {
            fact[0][n] = (fact[0][n - 1] * n) % MOD; // Compute factorial for the first row
        }

        // Compute factorial values for rows
        for (int n = 1; n < Nsq; n++) {
            fact[n][0] = (fact[n - 1][0] * n) % MOD; // Compute factorial for the first column
            for (int m = 1; m < Nsq; m++) {
                fact[n][m] = (fact[n][m - 1] * fact[n - 1][m]) % MOD; // Fill the rest of the table
            }
        }

        // Flatten the factorial array to 1D
        long[] flatFact = new long[Nsq * Nsq];
        for (int i = 0; i < Nsq; i++) {
            System.arraycopy(fact[i], 0, flatFact, i * Nsq, Nsq);
        }

        // Create an array of indices from 0 to N-1
        long[] j = new long[N];
        for (int i = 0; i < N; i++) {
            j[i] = i;
        }

        // Calculate modular inverses of numbers from 1 to N
        long[] inv = new long[N];
        for (int i = 0; i < N; i++) {
            inv[i] = modInverse(i + 1, MOD);
        }

        // Compute cumulative sum of inverses and take modulo
        for (int i = 1; i < N; i++) {
            inv[i] = (inv[i] + inv[i - 1]) % MOD;
        }

        // Calculate temporary values based on the cumulative inverses
        long[] temp = new long[N];
        for (int i = 0; i < N; i++) {
            temp[i] = (inv[(int) j[i]] + inv[N - 1 - (int) j[i]] - 1 + MOD) % MOD;
        }

        // Compute the final answer by multiplying A with temp and summing the result
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + (A[i] * temp[i]) % MOD) % MOD;
        }

        // Multiply the answer by the factorial of N and take modulo
        ans = (ans * flatFact[N]) % MOD;

        // Print the final answer
        System.out.println(ans);
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    static long modInverse(long a, long mod) {
        return pow(a, mod - 2, mod);
    }

    // Function to calculate power with modulo
    static long pow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
