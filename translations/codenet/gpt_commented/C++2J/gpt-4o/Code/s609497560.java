import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method where the execution of the program begins
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

        System.out.print("Enter a number: "); // Prompt the user to enter a value
        int a = scanner.nextInt(); // Read the input value from the user and store it in 'a'

        // Calculate the expression a + a^2 + a^3 and output the result
        System.out.println(a + (a * a) + (a * a * a)); 

        scanner.close(); // Close the scanner to prevent resource leaks
    } 
} // End of the Main class
// <END-OF-CODE>
