import java.util.Scanner; // Import the Scanner class for user input

public class AverageCalculator { // Define a public class named AverageCalculator
    public static void main(String[] args) { // Main method
        int a, b, n; // Declare three integer variables

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        System.out.print("Enter two integers: "); // Prompt user to enter two integers
        a = scanner.nextInt(); // Read the first integer
        b = scanner.nextInt(); // Read the second integer

        n = (a + b) / 2; // Calculate the average of a and b

        System.out.printf("The average of %d and %d is: %d\n", a, b, n); // Display the average

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
