import java.util.Scanner;

public class Main {
    // Direction vectors for moving in 4 directions (up, right, down, left)
    static int[] dy = {-1, 0, +1, 0};
    static int[] dx = {0, +1, 0, -1};

    // Constants for infinity and modulo operations
    static final long INF = 1L << 60;
    static final long MOD = 1000000007;

    // Function to compute the greatest common divisor (GCD) using recursion
    static int gcd(int a, int b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive case
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n; // Variable to hold the input number

        // Read an integer from standard input
        n = scanner.nextInt();

        // Initialize an empty string to hold the binary representation
        StringBuilder s = new StringBuilder();

        // Special case: if the input number is 0, output '0' and exit
        if (n == 0) {
            System.out.println('0');
            return;
        }

        // Loop to convert the number to its binary representation in a specific format
        while (n != 0) {
            // Check if the current number is even or odd
            if (n % 2 == 0) {
                s.append('0'); // Append '0' for even numbers
            } else {
                s.append('1'); // Append '1' for odd numbers
            }

            // Adjust the number for the next iteration
            n -= Math.abs(n % 2); // Reduce n by 1 if it's odd
            n /= -2; // Divide n by -2 to continue the conversion
        }

        // Reverse the string to get the correct binary representation
        s.reverse();

        // Output the final binary string
        System.out.println(s.toString());
    }
}

//<END-OF-CODE>
