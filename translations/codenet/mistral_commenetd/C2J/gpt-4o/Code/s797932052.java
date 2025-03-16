import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        int a, b; // Declare two integer variables 'a' and 'b'
        
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        
        a = scanner.nextInt(); // Read an integer value from the standard input and store it in variable 'a'
        b = scanner.nextInt(); // Read an integer value from the standard input and store it in variable 'b'
        
        if ((a * b) % 2 == 0) { // Check if the product of 'a' and 'b' is even
            System.out.println("Even"); // If it is even, print "Even" to the standard output
        } else {
            System.out.println("Odd"); // If it is odd, print "Odd" to the standard output
        }
        
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
