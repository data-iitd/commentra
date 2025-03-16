import java.util.Scanner; // Import the Scanner class for user input

public class CubeCalculator { // Declare the class

    public static void main(String[] args) { // Main method
        int x, kotae; // Declare two integer variables, x and kotae

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Ask the user to input an integer value for x
        System.out.print("Enter an integer value for x: ");
        x = scanner.nextInt(); // Read the integer input

        // Calculate the cube of the input integer x and store the result in the variable kotae
        kotae = x * x * x;

        // Print the result (the cube of the input integer) to the console
        System.out.printf("The cube of %d is %d.%n", x, kotae);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
