public class Main {
    // Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
    public static long Euclid(long x, long y) {
        long tmp;

        // Ensure x is the larger number
        if (x < y) {
            tmp = x; // Store the smaller number in tmp
            x = y;   // Assign the larger number to x
            y = tmp; // Assign the smaller number to y
        }

        // If y divides x evenly, y is the GCD
        if (x % y == 0) return y;

        // Recursively call Euclid with y and the remainder of x divided by y
        return Euclid(y, x % y);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long A = scanner.nextLong(); // Read input value for A
        long B = scanner.nextLong(); // Read input value for B

        // Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
        System.out.println((A * B) / Euclid(A, B));
    }
}
