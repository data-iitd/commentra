
import java.util.Scanner;

public class s917269550{
    public static void main(String[] args) {
        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Declare two long long integer variables to store input values
        long long x = scanner.nextLong();
        long long y = scanner.nextLong();

        // Check if the absolute difference between x and y is less than or equal to 1
        if (Math.abs(x - y) <= 1) {
            // If the condition is true, output "Brown"
            System.out.println("Brown");
        } else {
            // If the condition is false, output "Alice"
            System.out.println("Alice");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
