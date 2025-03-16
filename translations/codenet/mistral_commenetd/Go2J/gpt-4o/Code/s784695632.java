import java.util.Scanner; // Import the Scanner class for reading input.

public class Main { // Define the class "Main".
    public static void main(String[] args) { // Define the main method as the entry point of our program.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input.
        
        int x, y; // Declare variables "x" and "y".
        
        // Read the values of variables "x" and "y" from the standard input.
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        // Print the result of the expression "x + y/2" to the standard output.
        System.out.println(x + y / 2);
        
        scanner.close(); // Close the scanner to free resources.
    } // End of main method.
} // End of class Main.
