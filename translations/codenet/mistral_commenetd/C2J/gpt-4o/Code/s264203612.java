import java.util.Scanner; // Import the Scanner class for input

public class CircleCalculator { // Define a public class named CircleCalculator
    public static void main(String[] args) { // Start of the main method
        double r; // Declare a variable 'r' of type double
        double s, l; // Declare two variables 's' and 'l' of type double
        double p = 3.141592653589; // Initialize a constant variable 'p' with the value of pi

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        r = scanner.nextDouble(); // Read a value of type double from the standard input and store it in variable 'r'

        s = r * r * p; // Calculate the area of a circle with radius 'r' and store it in variable 's'
        l = 2 * p * r; // Calculate the circumference of a circle with radius 'r' and store it in variable 'l'

        System.out.printf("%f %f\n", s, l); // Print the values of 's' and 'l' to the standard output

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of the main method
} // End of the CircleCalculator class
// <END-OF-CODE>
