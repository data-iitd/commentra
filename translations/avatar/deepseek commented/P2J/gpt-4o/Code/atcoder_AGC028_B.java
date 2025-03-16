import java.util.Scanner;

public class Main {
    private static final long MOD = 1000000007;  // Define the modulo constant
    private static final int M = 1000000;  // Define a constant for the factorial table size
    private static final int Nsq = 1000;  // Define a constant for the size of the factorial table

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();  // Read the size of the array
        long[] A = new long[N];  // Array to hold the input values
        
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();  // Read the array elements
        }

        // Initialize the factorial table
        long[][] fact = new long[Nsq][Nsq];
        fact[0][0] = 1;

        // Compute the factorial table
        for (int n = 1; n < Nsq; n++) {
            for (int j = 0; j < Nsq; j++) {
                fact[j][n] = (fact[j][n - 1] * n) % MOD;  // Multiply current column with the previous column
            }
        }

        // Compute the factorial table row-wise
        for (int n = 1; n < Nsq; n++) {
            for (int j = 0; j < Nsq; j++) {
                fact[n][j] = (fact[n][j] * fact[n - 1][Nsq - 1]) % MOD;  // Multiply current row with the last element of the previous row
            }
        }

        // Compute the inverse factorial values
        long[] inv = new long[N];
        for (int i = 0; i < N; i++) {
            inv[i] = modPow(i + 1, MOD - 2, MOD);  // Compute modular inverse
        }

        // Compute the cumulative sum of inverse factorials
        for (int i = 1; i < N; i++) {
            inv[i] = (inv[i] + inv[i - 1]) % MOD;
        }

        // Compute the temporary value
        long[] temp = new long[N];
        for (int j = 0; j < N; j++) {
            temp[j] = (inv[j] + inv[N - 1 - j] - 1 + MOD) % MOD;  // Ensure non-negative
        }

        // Compute the final answer
        long ans = 0;
        for (int j = 0; j < N; j++) {
            ans = (ans + A[j] * temp[j]) % MOD;  // Sum the products
        }

        // Multiply the final answer with the factorial of N
        ans = (ans * fact[N][Nsq - 1]) % MOD;

        // Print the final answer
        System.out.println(ans);
    }

    // Function to compute modular exponentiation
    private static long modPow(long base, long exp, long mod) {
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
// <END-OF-CODE>
