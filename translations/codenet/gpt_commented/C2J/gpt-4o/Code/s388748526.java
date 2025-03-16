import java.util.Scanner;  // Import the Scanner class for user input
import static java.lang.Math.PI;  // Import the constant PI from the Math class

public class CircleCalculator {
    public static void main(String[] args) {
        double r;  // Declare a variable to store the radius

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to input the radius
        System.out.print("Enter the radius: ");
        r = scanner.nextDouble();  // Read the radius from user input

        // Calculate and print the area and circumference of the circle
        // Area = π * r^2
        // Circumference = 2 * π * r
        System.out.printf("%f %f%n", r * r * PI, 2 * PI * r);

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
