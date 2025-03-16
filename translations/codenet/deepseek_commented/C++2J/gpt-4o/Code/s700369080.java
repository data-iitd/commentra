import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        long x1 = scanner.nextLong(); // Read the first coordinate
        long y1 = scanner.nextLong(); // Read the second coordinate
        long x2 = scanner.nextLong(); // Read the third coordinate
        long y2 = scanner.nextLong(); // Read the fourth coordinate

        // Calculate the differences between the coordinates
        long dx = x2 - x1;
        long dy = y2 - y1;

        // Compute the new coordinates based on the differences
        long x3 = x2 - dy;
        long y3 = y2 + dx;
        long x4 = x1 - dy;
        long y4 = y1 + dx;

        // Output the new coordinates
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
