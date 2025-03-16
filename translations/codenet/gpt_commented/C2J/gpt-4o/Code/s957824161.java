import java.util.Scanner;

public class Main {
    // Declare global variables for storing two integers
    static int x, y;

    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from user input
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
        // Print the results: product and perimeter
        System.out.println(x * y + " " + (2 * x + 2 * y));
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
