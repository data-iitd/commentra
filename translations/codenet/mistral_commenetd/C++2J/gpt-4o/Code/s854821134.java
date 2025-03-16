import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Begin the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a = scanner.nextInt(); // Read the first integer from input
        int b = scanner.nextInt(); // Read the second integer from input

        // Check if both a and b are less than or equal to 8
        if (a <= 8 && b <= 8) {
            System.out.println("Yay!"); // If the condition is true, print "Yay!"
        } else {
            System.out.println(":("); // If the condition is false, print ":("
        }

        // Close the scanner
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
