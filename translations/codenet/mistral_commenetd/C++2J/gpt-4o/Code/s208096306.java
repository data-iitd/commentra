import java.util.Scanner;

public class GCDCalculator {
    
    // Function to find the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp; // Swap 'a' and 'b' if 'a' is smaller than 'b'
        }

        // Use Euclidean algorithm to find the GCD of 'a' and 'b'
        int r;
        while ((r = a % b) > 0) {
            a = b;
            b = r;
        }

        // Return the GCD of 'a' and 'b'
        return b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int n = scanner.nextInt(); // Read the number of integers 'n' from the standard input

        int ans = scanner.nextInt(); // Read the first integer 'ans' from the standard input

        // Read and process the remaining integers
        for (int i = 1; i < n; ++i) {
            int a = scanner.nextInt(); // Read the next integer 'a' from the standard input

            // Update the answer by finding the GCD of the current answer and the new integer 'a'
            ans = gcd(ans, a);
        }

        // Print the final answer to the standard output
        System.out.println(ans);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
