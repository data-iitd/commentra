import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int x; // Declare an integer variable x to store user input
        x = scanner.nextInt(); // Read an integer value from the user and store it in x

        // Check if the input value x is greater than or equal to 1200
        if (x >= 1200) 
            System.out.println("ARC"); // If true, output "ARC"
        else 
            System.out.println("ABC"); // If false, output "ABC"
        
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
