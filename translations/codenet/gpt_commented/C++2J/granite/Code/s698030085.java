
import java.util.Scanner;

public class s698030085{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Declare two long long integer variables to hold the input values
        long long a = scanner.nextLong();
        long long b = scanner.nextLong();

        // Check if the sum of a and b is even
        if ((a + b) % 2 == 0) {
            // If the sum is even, calculate and output the average
            System.out.println((a + b) / 2);
        } else {
            // If the sum is odd, output "IMPOSSIBLE"
            System.out.println("IMPOSSIBLE");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
