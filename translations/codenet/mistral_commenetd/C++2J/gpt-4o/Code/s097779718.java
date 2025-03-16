import java.util.Scanner;

public class GCD {
    // Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
    public static long euclid(long x, long y) {
        long tmp; // Variable to store the temporary value

        // Swap x and y if x is smaller than y
        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        // If x is divisible by y, return y as the GCD
        if (x % y == 0) return y;

        // Recursively call euclid function with y and the remainder of x divided by y
        return euclid(y, x % y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A, B; // Declare variables to store input numbers

        // Read input values of A and B from the standard input
        A = scanner.nextLong();
        B = scanner.nextLong();

        // Calculate the product of A and B and print the result divided by their GCD
        System.out.println((A * B) / euclid(A, B));
        
        scanner.close();
    }
}

// <END-OF-CODE>
