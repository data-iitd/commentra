

import java.util.Scanner;
import java.math.BigInteger; // Import BigInteger package for handling large integers

public class s658739453{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger d = new BigInteger("1000000007"); // Define a constant 'd' as a BigInteger

        int n = scanner.nextInt(); // Read the first integer 'n' from the standard input
        int p = scanner.nextInt(); // Read the second integer 'p' from the standard input

        Map<BigInteger, BigInteger> mdans = new HashMap<>(); // Initialize an empty map'mdans' for storing distinct numbers

        // Read 'p' distinct numbers from the standard input and store them in the map'mdans'
        for (int index = 0; index < p; index++) {
            BigInteger n1 = scanner.nextBigInteger();
            mdans.put(n1, n1); // Store the number 'n1' in the map'mdans' with its own key
        }

        BigInteger[] dp = new BigInteger[n + 1]; // Initialize an array 'dp' of size 'n+1' with a default value of '0'
        dp[0] = BigInteger.ONE; // Initialize the first element of the array 'dp' with a value of '1'
        dp[1] = BigInteger.ONE; // Initialize the second element of the array 'dp' with a value of '1'

        // Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the map'mdans'
        if (mdans.containsKey(BigInteger.ONE)) {
            dp[1] = BigInteger.ZERO;
        }

        // Calculate the remaining elements of the array 'dp' using the previous elements
        for (int i = 2; i <= n; i++) {
            if (mdans.containsKey(BigInteger.valueOf(i))) {
                continue; // Skip the current iteration if the number 'i' is present in the map'mdans'
            }
            dp[i] = dp[i - 1].add(dp[i - 2]).mod(d); // Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'
        }

        // Print the final result
        System.out.println(dp[n]); // Print the value of the last element of the array 'dp'
    }
}

