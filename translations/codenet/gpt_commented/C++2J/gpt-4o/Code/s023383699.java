import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method where the program execution begins
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int x; // Declare an integer variable 'x' to store user input
        x = scanner.nextInt(); // Read an integer value from the user and store it in 'x'
        
        // Calculate the cube of 'x' and print the result
        System.out.println(x * x * x); // Output the cube of 'x' followed by a newline

        scanner.close(); // Close the scanner to free up resources
    } // End of main method
} // End of Main class
// <END-OF-CODE>
