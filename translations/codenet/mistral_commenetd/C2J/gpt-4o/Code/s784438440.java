import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the main class
    public static void main(String[] args) { // The entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int a = scanner.nextInt(); // Read the first integer and store it in 'a'
        int b = scanner.nextInt(); // Read the second integer and store it in 'b'

        // Print the result of the expression ((b-1)+(a-2))/(a-1)
        System.out.println((b - 1 + (a - 2)) / (a - 1));

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
