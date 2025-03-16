import java.util.Scanner; // Import the Scanner class for reading input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        int a, b, x, y; // Declare four integer variables: a, b, x, and y

        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        a = scanner.nextInt(); // Read the first integer and store it in variable a
        b = scanner.nextInt(); // Read the second integer and store it in variable b

        x = 2 * a + 2 * b; // Multiply variables a and b by 2, and then add the results together and store the result in variable x
        y = a * b; // Multiply variables a and b and store the result in variable y

        System.out.println(y + " " + x); // Print the values of variables y and x to the standard output, separated by a space

        scanner.close(); // Close the scanner to free up resources
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
