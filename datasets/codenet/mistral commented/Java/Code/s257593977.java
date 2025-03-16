
import java.util.Scanner; // Import the Scanner class for user input

public class Main {

    private static final int BASE = 3; // Define a constant variable BASE with a value of 3

    public static void main(String[] args) {
        // Initialize a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the user
        int baseNumber = scanner.nextInt();

        // Calculate the power of the base number raised to the power of BASE (3)
        int result = (int)Math.pow(baseNumber, BASE);

        // Print the result to the console
        System.out.println("Result: " + result);

        // Close the Scanner object to prevent resource leaks
        scanner.close();
    }
}