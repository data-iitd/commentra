import java.util.Scanner;

public class Main {
    // Function to compute the greatest common divisor (GCD) of two numbers
    public static long gcd(long x, long y) {
        long tmp = 0;
        // Ensure x is greater than or equal to y
        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }
        // Apply the Euclidean algorithm to find GCD
        while (y > 0) {
            long r = x % y;
            x = y;
            y = r;
        }
        return x; // Return the GCD
    }

    // Function to compute the least common multiple (LCM) of two numbers
    public static long lcm(long x, long y) {
        return x / gcd(x, y) * y; // LCM formula using GCD
    }

    // Function to compute the factorial of a number modulo 1,000,000,007
    public static long kaijo(long k) {
        long sum = 1;
        // Calculate factorial iteratively
        for (long i = 1; i <= k; ++i) {
            sum *= i; // Multiply current sum by i
            sum %= 1000000000 + 7; // Take modulo to prevent overflow
        }
        return sum; // Return the factorial
    }

    // Function to return the maximum of two numbers
    public static long lmax(long s, long t) {
        return (s > t) ? s : t; // Return the greater of s and t
    }

    // Function to return the minimum of two numbers
    public static long lmin(long s, long t) {
        return (s < t) ? s : t; // Return the smaller of s and t
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Input the value of n
        int k = scanner.nextInt(); // Input the value of k
        long sum = 0; // Initialize sum to zero

        // Loop through each integer b from 1 to n
        for (int b = 1; b <= n; b++) {
            // Calculate the count of multiples of b in the range [1, n]
            int cnt = (n + 1) / b;
            // Calculate the remainder when n + 1 is divided by b
            int md = (n + 1) % b;
            // Update the sum based on the count and the maximum values
            sum += cnt * Math.max((b - k), 0) + Math.max((md - k), 0);
            // Adjust the sum if k is zero
            if (k == 0) sum--;
        }

        // Output the final computed sum
        System.out.println(sum);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
