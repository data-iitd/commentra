import java.util.Scanner;

public class CircleCalculator {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the input value for the radius of the circle
        double r = scanner.nextDouble();

        // Calculate the area of the circle (πr^2) and the circumference (2πr)
        double area = r * r * Math.PI;
        double circumference = 2 * Math.PI * r;

        // Print the results to the standard output
        System.out.printf("%lf %lf%n", area, circumference);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
