import java.util.Scanner;

public class Main {
    // Function to swap two integers
    static void swap(int[] x, int[] y) {
        int temp = x[0]; // Store the value of x in temp
        x[0] = y[0]; // Assign the value of y to x
        y[0] = temp; // Assign the value of temp (i.e., the original value of x) to y
    }

    // Function to find the greatest common divisor (GCD) of two numbers
    static long gcd(long a, long b) {
        long c; // Variable to store the remainder
        // Continue the division process until the remainder becomes zero
        while (b > 0) {
            c = a % b; // Calculate the remainder
            a = b; // Update a with the value of b
            b = c; // Update b with the value of the previous remainder
        }
        return a; // Return the GCD (i.e., the last non-zero value of a)
    }

    // Function to calculate a^n modulo m
    static long modpow(long a, long n, long mod) {
        long ans = 1; // Initialize the answer as 1
        while (n > 0) {
            if ((n & 1) == 1) { // Check if n is odd
                ans = ans * a % mod; // Multiply the answer with a and take modulo m
            }
            a = a * a % mod; // Square a and take modulo m
            n /= 2; // Divide n by 2
        }
        return ans; // Return the final answer
    }

    // Function to find the modular multiplicative inverse of a modulo m
    static long modinv(long a, long mod) {
        return modpow(a, mod - 2, mod);
    }

    // Function to find the maximum of two integers
    static int max(int a, int b) {
        return (a < b) ? b : a; // Return the maximum
    }

    // Function to find the minimum of two integers
    static int min(int a, int b) {
        return (a < b) ? a : b; // Return the minimum
    }

    // Function to update the value of a variable with the maximum of the current value and a new value
    static void chmax(int[] a, int b) {
        if (a[0] < b) { // If the current value is smaller than the new value
            a[0] = b; // Update the current value with the new value
        }
    }

    // Function to update the value of a variable with the minimum of the current value and a new value
    static void chmin(int[] a, int b) {
        if (a[0] > b) { // If the current value is greater than the new value
            a[0] = b; // Update the current value with the new value
        }
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n; // Variable to store the number of digits in the given number
        int sum = 0; // Variable to store the sum of digits
        int m; // Variable to store the given number

        // Read the number of digits from the standard input
        n = scanner.nextInt();

        // Initialize m with the given number
        m = n;

        // Calculate the sum of digits
        for (int i = 0; i < 9; i++) {
            sum += m % 10; // Add the last digit to the sum
            m /= 10; // Remove the last digit and update m
        }

        // Check if the given number is divisible by the sum of its digits
        if (n % sum == 0) {
            System.out.println("Yes"); // If yes, print "Yes"
        } else {
            System.out.println("No"); // If no, print "No"
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
