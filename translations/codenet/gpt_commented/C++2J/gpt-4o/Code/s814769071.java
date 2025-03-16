import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input values for n and k
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();

        // Define MOD constant for modulo operations
        long MOD = 1000000007;

        // Calculate the maximum possible value based on n and k
        long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

        // Calculate the minimum possible value based on k
        long mn = k * (k - 1) / 2;

        // Initialize result variable
        long res = 0;

        // Loop through values from k to n+1 to compute the result
        for (int i = (int) k; i <= n + 1; ++i) {
            // Update result based on current mx and mn values
            res += mx - mn + 1;

            // Update mx and mn for the next iteration
            mx += n - i;
            mn += i;

            // Ensure result stays within the bounds of MOD
            res %= MOD;
        }

        // Output the final result
        System.out.println(res);
    }
}

// <END-OF-CODE>
