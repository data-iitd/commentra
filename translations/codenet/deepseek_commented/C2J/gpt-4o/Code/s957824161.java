import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int x = scanner.nextInt(); // Read the first integer
        int y = scanner.nextInt(); // Read the second integer
        System.out.println(x * y + " " + (2 * x + 2 * y)); // Print the product of x and y and the perimeter of the rectangle
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
