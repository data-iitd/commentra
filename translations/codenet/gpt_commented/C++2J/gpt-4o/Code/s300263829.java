import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method where the execution of the program begins
        int a, b; // Declare two integer variables a and b to store user input
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Prompt the user to enter two integers
        System.out.print("Enter two integers: "); 
        a = scanner.nextInt(); // Read the first integer from user input
        b = scanner.nextInt(); // Read the second integer from user input
        
        // Calculate the product of a and b and display the result
        System.out.println("The product is: " + (a * b)); 
        
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
