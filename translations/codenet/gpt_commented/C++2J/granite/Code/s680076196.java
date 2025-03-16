
import java.util.Scanner; // Import the Scanner class from the java.util package

public class s680076196{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user

        int a = scanner.nextInt(); // Read the first integer value from standard input
        int b = scanner.nextInt(); // Read the second integer value from standard input
        int c = scanner.nextInt(); // Read the third integer value from standard input
        int d = scanner.nextInt(); // Read the fourth integer value from standard input

        // Calculate the product of the differences between the first two and the last two integers
        // This represents the area of a rectangle defined by the points (a, b) and (c, d)
        System.out.println((a - c) * (b - d));

        scanner.close(); // Close the Scanner object to release system resources
    }
}
