import java.util.*;
import java.io.*;

public class Main {
    // Define constant value
    static final long MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        // Read input number of elements N
        int N = Integer.parseInt(input.readLine().trim());
        // Define a constant value for the size of the 2D array A
        int M = 1000000;

        // Initialize array A with given size and input data
        long[] A = Arrays.stream(input.readLine().split(" "))
                         .mapToLong(Long::parseLong)
                         .toArray();

        // Define a constant value for the size of the 2D array fact
        int Nsq = 1000;

        // Initialize 2D array fact with given size and initial value 1
        long[][] fact = new long[Nsq][Nsq];
        fact[0][0] = 1;

        // Calculate factorial for each cell in the 2D array fact using a loop
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[i][n] = (fact[i][n - 1] * (i + 1)) % MOD; // Multiply current row with previous row
            }
        }

        // Transpose the 2D array fact and calculate factorial for each cell in the new rows
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[n][i] = (fact[n - 1][Nsq - 1] * fact[n][i]) % MOD; // Multiply current row with last cell of previous row
            }
        }

        // Flatten the 2D array fact into a 1D array
        long[] flatFact = new long[Nsq * Nsq];
        for (int i = 0; i < Nsq; i++) {
            System.arraycopy(fact[i], 0, flatFact, i * Nsq, Nsq);
        }

        // Initialize array j with given size
        long[] j = new long[N];
        for (int i = 0; i < N; i++) {
            j[i] = i;
        }

        // Calculate the inverse of each element in the array inv
        long[] inv = new long[N];
        for (int i = 0; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2, MOD);
        }

        // Calculate cumulative sum of the array inv
        for (int i = 1; i < N; i++) {
            inv[i] = (inv[i] + inv[i - 1]) % MOD;
        }

        // Calculate temporary array temp using elements from j and inv
        long[] temp = new long[N];
        for (int i = 0; i < N; i++) {
            temp[i] = (inv[(int) j[i]] + inv[N - 1 - (int) j[i]] - 1 + MOD) % MOD;
        }

        // Calculate the answer ans using given formula
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + (A[i] * temp[i]) % MOD) % MOD;
        }

        // Multiply the answer ans with the last element of fact array
        ans = (ans * flatFact[N]) % MOD;

        // Print the answer ans
        System.out.println(ans);
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
// <END-OF-CODE>
