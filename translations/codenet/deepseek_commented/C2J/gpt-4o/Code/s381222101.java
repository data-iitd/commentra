import java.util.Scanner; // Step 1: Import the Scanner class for user input.

public class TrapezoidArea { // Step 2: Define the class.
    public static void main(String[] args) { // Step 3: Define the main method.
        int a, b, h; // Step 4: Declare three integer variables a, b, and h.
        
        Scanner scanner = new Scanner(System.in); // Step 5: Create a Scanner object for input.
        
        // Step 6: Read three integer values from the user and store them in a, b, and h.
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();
        
        // Step 7: Calculate the area of a trapezoid using the formula (a+b)*h/2.
        System.out.println((a + b) * h / 2); // Step 8: Print the result.
        
        scanner.close(); // Step 9: Close the scanner.
    } // Step 10: End the main method.
} // Step 11: End the class.

