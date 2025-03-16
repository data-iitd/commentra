import java.util.Scanner; // Step 1: Import the Scanner class for user input.

public class Main { // Step 2: Define the main class.
    public static void main(String[] args) { // Step 3: Define the main method.
        Scanner scanner = new Scanner(System.in); // Step 4: Create a Scanner object for input.
        int a, b; // Step 5: Declare two integer variables a and b.
        a = scanner.nextInt(); // Step 6: Read the first integer from user input.
        b = scanner.nextInt(); // Step 7: Read the second integer from user input.
        
        if (500 * a >= b) // Step 8: Check if the product of 500 and a is greater than or equal to b.
            System.out.println("Yes"); // Step 9: Print "Yes" if the condition is true.
        else
            System.out.println("No"); // Step 10: Print "No" if the condition is false.
        
        scanner.close(); // Step 11: Close the scanner to prevent resource leaks.
    } // Step 12: End of the main method.
} // Step 13: End of the main class.
