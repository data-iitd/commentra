
import java.util.*;    // Import the Scanner class for input

public class s929864256{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    // Create a Scanner object to read input from standard input
        long a = sc.nextLong();    // Read a long integer value for a from standard input
        long b = sc.nextLong();    // Read a long integer value for b from standard input

        // Calculate the maximum of the sum, difference, and product of a and b
        long max = Math.max(a + b, Math.max(a - b, a * b));    // Calculate the maximum value using the Math.max() function

        System.out.println(max);    // Output the maximum value to standard output
    }
}

