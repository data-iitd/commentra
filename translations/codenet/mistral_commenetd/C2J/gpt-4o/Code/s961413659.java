import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b; // Declare two integer variables 'a' and 'b'
        
        a = scanner.nextInt(); // Read the first integer from input
        b = scanner.nextInt(); // Read the second integer from input

        // First if block: If 'a' is equal to 1, assign 14 to 'a'
        if (a == 1) {
            a = 14;
        }

        // Second if block: If 'b' is equal to 1, assign 14 to 'b'
        if (b == 1) {
            b = 14;
        }

        // Determine who wins based on the values of 'a' and 'b'
        if (a < b) {
            System.out.println("Bob"); // If 'a' is less than 'b', print "Bob"
        } else if (a > b) {
            System.out.println("Alice"); // If 'a' is greater than 'b', print "Alice"
        } else {
            System.out.println("Draw"); // If 'a' is equal to 'b', print "Draw"
        }

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
