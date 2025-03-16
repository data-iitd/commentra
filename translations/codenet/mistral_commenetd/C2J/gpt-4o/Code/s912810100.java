import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        int a, b, x, y; // Declare variables a, b, x, and y as integers

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        a = scanner.nextInt(); // Read the first integer and store it in variable a
        b = scanner.nextInt(); // Read the second integer and store it in variable b

        x = a * b; // Multiply the values of variables a and b and store the result in variable x
        y = (a + b) * 2; // Add the values of variables a and b, then multiply the result by 2 and store it in variable y

        System.out.println(x + " " + y); // Print the values of variables x and y to the standard output

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
