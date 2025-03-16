import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define the modulo constant
        final long MOD = 1000000007;

        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Read the list of integers
        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextLong();
        }

        // Sort the list in descending order
        Arrays.sort(c);
        for (int i = 0; i < n / 2; i++) {
            long temp = c[i];
            c[i] = c[n - 1 - i];
            c[n - 1 - i] = temp;
        }

        // Calculate the value of b as 2^(2*n - 2) modulo MOD
        long b = pow(2, 2 * n - 2, MOD);

        // Calculate the value of a as 2 * b modulo MOD
        long a = (2 * b) % MOD;

        // Initialize the answer variable
        long ans = 0;

        // Iterate through the sorted list and calculate the answer
        for (int i = 0; i < n; i++) {
            // Update the answer by adding the product of the current element and (a + i * b)
            ans = (ans + c[i] * (a + i * b)) % MOD;
        }

        // Print the final result
        System.out.println(ans);
    }

    // Function to perform modular exponentiation
    public static long pow(long base, long exp, long mod) {
        long result = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }
}
// <END-OF-CODE>
