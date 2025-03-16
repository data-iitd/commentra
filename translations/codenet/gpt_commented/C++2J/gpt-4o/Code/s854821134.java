import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b; // Declare two integer variables a and b
        a = scanner.nextInt(); // Read the first integer input
        b = scanner.nextInt(); // Read the second integer input

        // Check if both a and b are less than or equal to 8
        if (a <= 8 && b <= 8) 
            System.out.println("Yay!"); // If true, print "Yay!"
        else 
            System.out.println(":("); // If false, print ":("

        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
