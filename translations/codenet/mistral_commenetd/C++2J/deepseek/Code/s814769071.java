import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long MOD = 1_000_000_007;

        // Calculate the maximum number of unique elements in a subset of size k from 1 to n
        long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

        // Calculate the minimum number of unique elements in a subset of size k from 1 to n
        long mn = k * (k - 1) / 2;

        // Initialize result variable
        long res = 0;

        // Iterate through all possible subset sizes from k to n+1
        for (int i = (int) k; i <= n + 1; ++i) {
            // Calculate the number of unique elements in the current subset
            res += mx - mn + 1;

            // Update the maximum and minimum number of unique elements for the next iteration
            mx += n - i;
            mn += i;

            // Update the result variable
            res %= MOD;
        }

        // Print the final result
        System.out.println(res);
    }
}

