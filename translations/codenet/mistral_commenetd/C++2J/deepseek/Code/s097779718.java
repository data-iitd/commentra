public class Main {
    // Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
    public static long Euclid(long x, long y) {
        long tmp; // Variable to store the temporary value

        // Swap x and y if x is smaller than y
        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        // If x is divisible by y, return y as the GCD
        if (x % y == 0) return y;

        // Recursively call Euclid function with y and the remainder of x divided by y
        return Euclid(y, x % y);
    }

    public static void main(String[] args) {
        long A, B; // Declare variables to store input numbers

        // Read input values of A and B from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextLong();
        B = scanner.nextLong();

        // Calculate the product of A and B and print the result divided by their GCD
        System.out.println((A * B) / Euclid(A, B));
    }
}
