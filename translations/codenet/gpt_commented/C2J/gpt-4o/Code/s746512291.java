import java.util.Scanner; // Import the Scanner class for user input

public class CubeCalculator { // Define a public class named CubeCalculator
    public static void main(String[] args) { // Main method where program execution begins
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int x; // Declare an integer variable x

        // Prompt the user for input and read an integer value into x
        x = scanner.nextInt();

        // Calculate the cube of x and print the result
        System.out.println(x * x * x);

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of class

// <END-OF-CODE>
