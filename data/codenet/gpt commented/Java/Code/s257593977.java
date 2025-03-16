import java.util.Scanner; // Import the Scanner class for user input

public class Main {

    private static final int BASE = 3; // Define a constant BASE with a value of 3

    public static void main(String[] args) {
        // Create a new Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Prompt the user for input and read an integer value
        System.out.print("Enter a number: ");
        int userInput = scanner.nextInt();
        
        // Calculate the power of the user input raised to the BASE (3) and cast it to an integer
        int result = (int) Math.pow(userInput, BASE);
        
        // Print the result of the calculation
        System.out.println("Result: " + result);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
