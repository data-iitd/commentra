import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        int a, b, mawari, menseki; // Declare variables a, b, mawari, and menseki as integers

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        // Read input values for variables a and b from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Assign the variable mawari the sum of the squares of a and b
        mawari = a + a + b + b;
        // Assign the variable menseki the product of a and b
        menseki = a * b;
        
        // Print the values of menseki and mawari to the console
        System.out.println(menseki + " " + mawari);
        
        // Close the scanner
        scanner.close();
    } // End of main method
} // End of Main class
// <END-OF-CODE>
