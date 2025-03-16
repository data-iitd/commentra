import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int A, B; // Declare two integer variables A and B
        A = scanner.nextInt(); // Read the first integer from the user
        B = scanner.nextInt(); // Read the second integer from the user
        if (A < 10 && B < 10) { // Check if both A and B are less than 10
            System.out.println(A * B); // If true, print the multiplication result
        } else {
            System.out.println("-1"); // If the condition is false, print -1
        }
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
