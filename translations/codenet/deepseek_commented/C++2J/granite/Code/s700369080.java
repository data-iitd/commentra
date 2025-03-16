
import java.util.Scanner; // Import necessary classes for input and output operations

public class s700369080{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner object to read input from the standard input
        long x1 = scanner.nextLong(), y1 = scanner.nextLong(), x2 = scanner.nextLong(), y2 = scanner.nextLong(); // Read four long integers from the standard input

        // Calculate the differences between the coordinates
        long dx = x2 - x1, dy = y2 - y1;

        // Compute the new coordinates based on the differences
        long x3 = x2 - dy, y3 = y2 + dx;
        long x4 = x1 - dy, y4 = y1 + dx;

        // Output the new coordinates
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4); // Use the standard output to print the new coordinates
    }
}
