import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        System.out.println((A * B) / Euclid(A, B));
    }

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
        if (!(x % y)) return y;

        // Recursively call Euclid with y and the remainder of x divided by y
        return Euclid(y, x % y);
    }
}
