import java.util.Scanner;

public class CircleCalculator {
    public static void main(String[] args) {
        // Declare variables for radius, area, and circumference
        double r; // radius
        double s, l; // area and circumference
        double p = 3.141592653589; // value of pi

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the radius from user input
        r = scanner.nextDouble();
        
        // Calculate the area of the circle using the formula: area = π * r^2
        s = r * r * p;

        // Calculate the circumference of the circle using the formula: circumference = 2 * π * r
        l = 2 * p * r;
        
        // Print the calculated area and circumference
        System.out.printf("%f %f%n", s, l);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
