public class Main {
    // Function to swap two integers
    static void swap(int[] x, int[] y) {
        int temp = x[0];
        x[0] = y[0];
        y[0] = temp;
    }

    // Function to compute the greatest common divisor (GCD) of two numbers
    static long gcd(long a, long b) {
        long c;
        // Use the Euclidean algorithm to find GCD
        while (b > 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a; // Return the GCD
    }

    // Comparison function for sorting in ascending order
    static int upll(final long[] a, final long[] b) {
        return Long.compare(a[0], b[0]);
    }

    // Comparison function for sorting in descending order
    static int downll(final long[] a, final long[] b) {
        return Long.compare(b[0], a[0]);
    }

    // Function to sort an array in ascending order
    static void sortup(long[] a) {
        java.util.Arrays.sort(a); // Use Arrays.sort with the ascending comparison
    }

    // Function to sort an array in descending order
    static void sortdown(long[] a) {
        java.util.Arrays.sort(a); // Use Arrays.sort with the descending comparison
    }

    // Function to compute modular exponentiation
    static long modpow(long a, long n, long mod) {
        long ans = 1;
        // Exponentiation by squaring method
        while (n > 0) {
            if ((n & 1) == 1) { // If n is odd
                ans = ans * a % mod; // Multiply the base with the result
            }
            a = a * a % mod; // Square the base
            n /= 2; // Divide n by 2
        }
        return ans; // Return the result
    }

    // Function to compute modular inverse using Fermat's little theorem
    static long modinv(long a, long mod) {
        return modpow(a, mod - 2, mod); // a^(mod-2) mod mod
    }

    // Function to return the maximum of two integers
    static int max(int a, int b) {
        return a < b ? b : a; // Return b if a is less than b
    }

    // Function to return the minimum of two integers
    static int min(int a, int b) {
        return a < b ? a : b; // Return a if it is less than b
    }

    // Function to update the value of a if b is greater
    static void chmax(int[] a, int b) {
        if (a[0] < b) {
            a[0] = b; // Update a to b if b is greater
        }
    }

    // Function to update the value of a if b is smaller
    static void chmin(int[] a, int b) {
        if (a[0] > b) {
            a[0] = b; // Update a to b if b is smaller
        }
    }

    // Main function
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read an integer n from input
        int sum = 0; // Initialize sum to 0
        int m = n; // Store the original value of n

        // Calculate the sum of the digits of n (up to 9 digits)
        for (int i = 0; i < 9; i++) {
            sum += n % 10; // Add the last digit to sum
            n /= 10; // Remove the last digit
        }

        // Check if m is divisible by the sum of its digits
        if (m % sum == 0) {
            System.out.println("Yes"); // Print "Yes" if divisible
        } else {
            System.out.println("No"); // Print "No" if not divisible
        }
    }
}
