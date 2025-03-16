import java.util.Scanner;  // Import the Scanner class for input
import java.lang.Math;     // Import the Math class for mathematical operations

public class CircleCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        double r;  // Declare a variable named 'r' of type double

        // Read a value for 'r' from the standard input
        r = scanner.nextDouble();

        // Calculate the area and circumference of a circle with radius 'r'
        double area = r * r * Math.PI;
        double circumference = 2 * Math.PI * r;

        // Print the results to the standard output
        System.out.printf("%f %f%n", area, circumference);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
