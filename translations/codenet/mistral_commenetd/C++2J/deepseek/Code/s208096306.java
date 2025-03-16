import java.util.Scanner;

public class Main {
    // Function to find the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        if (a < b) {
            // Swap 'a' and 'b' if 'a' is smaller than 'b'
            int temp = a;
            a = b;
            b = temp;
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
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of integers 'n' from the standard input

        int ans = scanner.nextInt(); // Read the first integer 'ans' from the standard input and store it in the variable 'ans'

        // Read and process the remaining integers
        for (int i = 1; i < n; ++i) {
            int a = scanner.nextInt(); // Read the next integer 'a' from the standard input and store it in the variable 'a'

            // Update the answer by finding the GCD of the current answer and the new integer 'a'
            ans = gcd(ans, a);
        }

        // Print the final answer to the standard output
        System.out.println(ans);
    }
}
