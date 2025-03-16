import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        System.out.print("Enter two integers: "); // Print a message asking for two integers

        int x = scanner.nextInt(); // Read the first integer from the user
        int y = scanner.nextInt(); // Read the second integer from the user

        // Perform some arithmetic operations
        int result1 = x * y; // Multiply x and y and store the result in result1
        int result2 = 2 * x + 2 * y; // Multiply x by 2 and y by 2, then add the results

        // Print the results
        System.out.printf("The product of %d and %d is: %d\n", x, y, result1); // Print the product of x and y
        System.out.printf("The sum of 2 times %d and 2 times %d is: %d\n", x, y, result2); // Print the sum of 2 times x and 2 times y

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
