import java.util.Scanner; // Import the Scanner class to read input

public class CircleCalculator { // Define a public class named CircleCalculator
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        double r; // Declare a variable 'r' of type double
        double s, l; // Declare two variables 's' and 'l' of type double
        final double p = 3.141592653589; // Declare a constant variable 'p' with the value of pi

        r = scanner.nextDouble(); // Read a value of type double from the standard input and store it in variable 'r'

        s = r * r * p; // Calculate the area of a circle with radius 'r' and store it in variable 's'
        l = 2 * p * r; // Calculate the circumference of a circle with radius 'r' and store it in variable 'l'

        System.out.printf("%.6f %.6f\n", s, l); // Print the values of 's' and 'l' to the standard output

        scanner.close(); // Close the Scanner object
    }
}
