import java.util.Scanner;  // Import the Scanner class for input operations

public class PolygonAngles {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for user input
        int n;  // Declare an integer variable 'n' to store the number of sides of the polygon
        n = scanner.nextInt();  // Read the number of sides from user input

        // Calculate the sum of the interior angles of a polygon with 'n' sides
        // The formula for the sum of interior angles is (n - 2) * 180
        System.out.println((n - 2) * 180);  // Output the calculated sum of interior angles

        scanner.close();  // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
