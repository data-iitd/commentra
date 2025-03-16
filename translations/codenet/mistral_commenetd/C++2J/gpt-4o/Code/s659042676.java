import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int a, b; // Declare two integer variables `a` and `b`

        // Read two integer values from the standard input using `scanner`
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the difference between `6` and the sum of `a` and `b`
        int result = 6 - a - b;

        // Print the result to the standard output
        System.out.println(result);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
