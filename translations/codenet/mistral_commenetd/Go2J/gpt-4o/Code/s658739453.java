import java.math.BigInteger; // Import BigInteger for handling large integers
import java.util.HashMap; // Import HashMap for storing distinct numbers
import java.util.Scanner; // Import Scanner for reading input

public class Main {
    private static final BigInteger d = BigInteger.valueOf(1000000007); // Define a constant 'd' as a BigInteger

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Initialize variables
        int n = scanner.nextInt(); // Read the first integer 'n' from the standard input
        int p = scanner.nextInt(); // Read the second integer 'p' from the standard input

        HashMap<Long, Long> mdans = new HashMap<>(); // Initialize an empty HashMap 'mdans' for storing distinct numbers

        // Read 'p' distinct numbers from the standard input and store them in the HashMap 'mdans'
        for (int index = 0; index < p; index++) {
            long n1 = scanner.nextLong();
            mdans.put(n1, n1); // Store the number 'n1' in the HashMap 'mdans' with its own key
        }

        long[] dp = new long[n + 1]; // Initialize an array 'dp' of size 'n+1' with a default value of '0'
        dp[0] = 1; // Initialize the first element of the array 'dp' with a value of '1'
        dp[1] = 1; // Initialize the second element of the array 'dp' with a value of '1'

        // Initialize the second element of the array 'dp' with a value of '0' if the number '1' is present in the HashMap 'mdans'
        if (mdans.containsKey(1L)) {
            dp[1] = 0;
        }

        // Calculate the remaining elements of the array 'dp' using the previous elements
        for (int i = 2; i <= n; i++) {
            if (mdans.containsKey((long) i)) {
                continue; // Skip the current iteration if the number 'i' is present in the HashMap 'mdans'
            }
            dp[i] = (dp[i - 1] + dp[i - 2]) % d.longValue(); // Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'
        }

        // Print the final result
        System.out.println(dp[n]); // Print the value of the last element of the array 'dp'
    }
}
// <END-OF-CODE>
