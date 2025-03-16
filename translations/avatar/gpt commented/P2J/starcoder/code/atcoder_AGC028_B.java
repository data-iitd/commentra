import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the integer input N
        int N = sc.nextInt();

        // Define a constant for the maximum size
        int M = 1000000;

        // Read the array A from input and convert it to a numpy array of int64 type
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Define the size for factorial calculations
        int Nsq = 1000;

        // Initialize a 2D array to store factorial values
        long[][] fact = new long[Nsq][Nsq];

        // Set the first factorial value
        fact[0][0] = 1;

        // Compute factorial values for columns
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[i][n] = fact[i][n - 1] * i % MOD;
            }
        }

        // Compute factorial values for rows
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[n][i] = fact[n - 1][i] * fact[n][Nsq - 1] % MOD;
            }
        }

        // Flatten the factorial array to 1D
        long[] fact1D = new long[Nsq * Nsq];
        for (int i = 0; i < Nsq; i++) {
            for (int j = 0; j < Nsq; j++) {
                fact1D[i * Nsq + j] = fact[i][j];
            }
        }

        // Create an array of indices from 0 to N-1
        int[] j = new int[N];
        for (int i = 0; i < N; i++) {
            j[i] = i;
        }

        // Calculate modular inverses of numbers from 1 to N
        long[] inv = new long[N];
        for (int i = 0; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2, MOD);
        }

        // Compute cumulative sum of inverses and take modulo
        long[] invCum = new long[N];
        invCum[0] = inv[0];
        for (int i = 1; i < N; i++) {
            invCum[i] = (invCum[i - 1] + inv[i]) % MOD;
        }

        // Calculate temporary values based on the cumulative inverses
        long[] temp = new long[N];
        for (int i = 0; i < N; i++) {
            temp[i] = (invCum[i] + invCum[N - 1 - i] - 1) % MOD;
        }

        // Compute the final answer by multiplying A with temp and summing the result
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += A[i] * temp[i] % MOD;
            ans %= MOD;
        }

        // Multiply the answer by the factorial of N and take modulo
        ans *= fact1D[N];
        ans %= MOD;

        // Print the final answer
        System.out.println(ans);
    }

    // Define the modulo constant
    static final int MOD = 1000000007;

    // Calculate modular exponentiation
    static long pow(long a, long b, long mod) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
}

