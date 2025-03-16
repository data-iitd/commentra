import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long mod = 1000000007;
        // Define the modulo value as 10^9 + 7

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Read the integer input `n`

        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextLong();
        }
        // Read the list of integers `c`

        Arrays.sort(c);
        // Sort the list `c` in ascending order
        reverseArray(c);
        // Reverse the array to get it in descending order

        long b = power(2, 2 * n - 2, mod);
        // Calculate `b` using the power function with base 2, exponent 2 * n - 2, and modulo `mod`

        long a = (2 * b) % mod;
        // Calculate `a` as twice `b` modulo `mod`

        long ans = 0;
        // Initialize `ans` to 0

        for (int i = 0; i < n; i++) {
            // Loop through each element in the range `n`
            ans = (ans + c[i] * (a + i * b)) % mod;
            // Update `ans` with the sum of the product of `c[i]` and (a + i * b)
        }

        System.out.println(ans);
        // Print the final result `ans`
    }

    // Function to calculate (base^exponent) % mod
    private static long power(long base, long exponent, long mod) {
        long result = 1;
        base = base % mod;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                result = (result * base) % mod;
            }
            exponent >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }

    // Function to reverse an array
    private static void reverseArray(long[] array) {
        int left = 0, right = array.length - 1;
        while (left < right) {
            long temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}
// <END-OF-CODE>
