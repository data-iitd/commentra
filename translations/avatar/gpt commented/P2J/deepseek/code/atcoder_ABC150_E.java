import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define the modulo constant
        final long mod = (long) Math.pow(10, 9) + 7;

        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Read the list of integers and convert them to an array of integers
        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextLong();
        }

        // Sort the array in descending order
        Arrays.sort(c);

        // Calculate the value of b as 2^(2*n - 2) modulo mod
        long b = pow(2, 2 * n - 2, mod);

        // Calculate the value of a as 2 * b modulo mod
        long a = 2 * b % mod;

        // Initialize the answer variable
        long ans = 0;

        // Iterate through the sorted array and calculate the answer
        for (int i = 0; i < n; i++) {
            // Update the answer by adding the product of the current element and (a + i * b)
            ans += c[i] * (a + i * b);
            // Ensure the answer remains within the modulo
            ans %= mod;
        }

        // Print the final result
        System.out.println(ans);
    }

    // Function to perform modular exponentiation
    public static long pow(long base, long exp, long mod) {
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
