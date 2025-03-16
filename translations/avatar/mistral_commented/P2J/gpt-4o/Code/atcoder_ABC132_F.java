import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Set the modulus value
        final int MOD = 1000000007;

        // Read input values for n and k
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        int k = scanner.nextInt();

        // Initialize an array 'coef' to store coefficients
        long[] coef = new long[(int) (Math.sqrt(n) + 1)];
        int index = 0;

        // Calculate coefficients for n up to its square root
        for (long i = 1; i * i <= n; i++) {
            coef[index++] = n / i - n / (i + 1);
        }

        // Add remaining coefficients to the list
        long remaining = n - sum(coef, index);
        for (int i = 0; i < remaining; i++) {
            coef[index++] = 1;
        }

        // Reverse the list 'coef'
        long[] reversedCoef = new long[index];
        for (int i = 0; i < index; i++) {
            reversedCoef[i] = coef[index - 1 - i];
        }

        // Initialize a 2D array 'dp' to store intermediate results
        long[][] dp = new long[k + 1][index];

        // Initialize the first row of dp with 1 at index 0
        dp[0][0] = 1;

        // Calculate dp[i][j] for i from 1 to k and j from index-1 to 0
        for (int i = 1; i <= k; i++) {
            long tmp = 0;
            // Iterate through the reversed list 'coef' from j = index-1 to j = 0
            for (int j = index - 1; j >= 0; j--) {
                // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
                tmp = (tmp + dp[i - 1][j]) % MOD;
                // Update dp[i][j] with the product of coef[j] and tmp
                dp[i][j] = (reversedCoef[j] * tmp) % MOD;
            }
        }

        // Calculate the final answer by summing up dp[k]
        long result = 0;
        for (int j = 0; j < index; j++) {
            result = (result + dp[k][j]) % MOD;
        }
        System.out.println(result);
    }

    // Helper method to sum the coefficients
    private static long sum(long[] array, int length) {
        long total = 0;
        for (int i = 0; i < length; i++) {
            total += array[i];
        }
        return total;
    }
}
// <END-OF-CODE>
