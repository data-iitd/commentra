
import java.util.Scanner; // Step 1: Import necessary classes for input/output operations

public class s680076196{ // Step 2: Define a class named "s680076196" to contain the main method
  public static void main(String[] args) { // Step 3: Define the main method
    Scanner scanner = new Scanner(System.in); // Step 4: Create a Scanner object to read input values
    int a = scanner.nextInt(); // Read the first integer value from the user
    int b = scanner.nextInt(); // Read the second integer value from the user
    int c = scanner.nextInt(); // Read the third integer value from the user
    int d = scanner.nextInt(); // Read the fourth integer value from the user

    // Step 5: Perform calculations
    int area = (a - c) * (b - d); // Calculate the area of the rectangle using the given coordinates

    // Step 6: Output the result
    System.out.println(area); // Print the calculated area to the console
  }
}
