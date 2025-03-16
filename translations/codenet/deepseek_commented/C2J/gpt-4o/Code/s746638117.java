import java.util.Scanner; // Step 1: Import the Scanner class for input.

public class Rectangle { // Step 2: Define the Rectangle class.
    public static void main(String[] args) { // Step 3: Define the main method.
        int a, b, ar, le; // Step 4: Declare integer variables a, b, ar, and le.
        Scanner scanner = new Scanner(System.in); // Step 5: Create a Scanner object for input.
        a = scanner.nextInt(); // Step 6: Read the first integer from the user.
        b = scanner.nextInt(); // Step 7: Read the second integer from the user.
        ar = a * b; // Step 8: Calculate the area of a rectangle (ar) by multiplying a and b.
        le = 2 * (a + b); // Step 9: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
        System.out.println(ar + " " + le); // Step 10: Print the area and perimeter.
        scanner.close(); // Step 11: Close the scanner to prevent resource leaks.
    } // End of main method.
} // End of Rectangle class.
