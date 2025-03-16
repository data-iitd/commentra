import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Begin the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input

        int a; // Declare an integer variable named 'a'

        a = scanner.nextInt(); // Read an integer value from the user and store it in variable 'a'

        // Calculate the value of the expression (a + (a * a) + (a * a * a)) and print it
        System.out.println(a + (a * a) + (a * a * a));

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
