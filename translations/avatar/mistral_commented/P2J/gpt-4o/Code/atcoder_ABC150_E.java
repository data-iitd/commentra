import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Set the value of modulo for modular arithmetic calculations
        long mod = 1000000007;

        // Read an integer n from the standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Read n integers from the standard input and store them in an array c
        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextLong();
        }
        // Sort the array in descending order
        Arrays.sort(c);
        for (int i = 0; i < n / 2; i++) {
            long temp = c[i];
            c[i] = c[n - 1 - i];
            c[n - 1 - i] = temp;
        }

        // Calculate the value of b using the formula 2^(2*n-2) modulo mod
        long b = pow(2, 2 * n - 2, mod);

        // Calculate the value of a as 2*b modulo mod
        long a = (2 * b) % mod;

        // Initialize the variable ans to zero
        long ans = 0;

        // Iterate through each index i from 0 to n-1 in the array c
        for (int i = 0; i < n; i++) {
            // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
            ans = (ans + c[i] * (a + i * b)) % mod;
        }

        // Print the value of ans as the output
        System.out.println(ans);
    }

    // Method to perform modular exponentiation
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
