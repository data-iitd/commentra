import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Set the modulus value
        final long mod = (long) Math.pow(10, 9) + 7;

        // Read input values for n and k
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Initialize a list 'coef' to store coefficients
        ArrayList<Integer> coef = new ArrayList<>();

        // Calculate coefficients for n up to its square root
        for (int i = 1; i <= Math.sqrt(n); i++) {
            // Calculate the difference between the quotient and the next quotient
            coef.add(n / i - n / (i + 1));
        }

        // Add remaining coefficients to the list
        int remaining = n - coef.size();
        for (int i = 0; i < remaining; i++) {
            coef.add(1);
        }

        // Reverse the list 'coef'
        java.util.Collections.reverse(coef);

        // Initialize a 2D list 'dp' to store intermediate results
        int nn = coef.size();
        long[][] dp = new long[k + 1][nn];

        // Initialize the first row of dp with 1 at index 0
        dp[0][0] = 1;

        // Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
        for (int i = 1; i <= k; i++) {
            long tmp = 0;
            // Iterate through the reverse list 'coef' from j = nn-1 to j = 0
            for (int j = nn - 1; j >= 0; j--) {
                // Update 'tmp' with the sum of dp[i-1][j] and the product of coef.get(j) and tmp
                tmp = (tmp + dp[i - 1][j]) % mod;
                tmp = (tmp + coef.get(j)) % mod;
                // Update dp[i][j] with the product of coef.get(j) and tmp
                dp[i][j] = (coef.get(j) * tmp) % mod;
            }
        }

        // Calculate the final answer by summing up dp[k]
        long answer = 0;
        for (int i = 0; i < nn; i++) {
            answer = (answer + dp[k][i]) % mod;
        }
        System.out.println(answer);
    }
}
