import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Declare the Main class
    public static void main(String[] args) { // Declare the main method
        int a, b, h; // Declare three integer variables: a, b, and h

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        System.out.print("Enter the values of a, b, and h: "); // Print a message asking for user input
        a = scanner.nextInt(); // Read the first integer from the user
        b = scanner.nextInt(); // Read the second integer from the user
        h = scanner.nextInt(); // Read the third integer from the user

        // Calculate the area of the rectangle using the formula: area = (a + b) * h / 2
        System.out.println((a + b) * h / 2); // Print the result, which is the area of the rectangle

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
