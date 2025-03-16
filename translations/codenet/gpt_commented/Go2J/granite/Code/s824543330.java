
import java.util.Scanner;

public class s824543330{
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Check if the product of a and b is even or odd
        if (a * b % 2 == 0) {
            // If the product is even, print "Even"
            System.out.println("Even");
        } else {
            // If the product is odd, print "Odd"
            System.out.println("Odd");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
