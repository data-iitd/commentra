import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method where execution starts
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int x; // Declare an integer variable x

        // Read an integer value from user input and store it in x
        x = scanner.nextInt();

        // Check if the value of x is equal to 1
        if (x == 1) 
            System.out.println("0"); // If x is 1, print "0"
        else 
            System.out.println("1"); // If x is not 1, print "1"

        scanner.close(); // Close the scanner
    } 
} 
// <END-OF-CODE>
