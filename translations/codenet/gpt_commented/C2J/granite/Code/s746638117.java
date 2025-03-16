
import java.util.Scanner;

public class s746638117{
    public static void main(String[] args) {
        // Declare variables to hold the dimensions and results
        int a, b, ar, le;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read the length and width from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the area of the rectangle (length * width)
        ar = a * b;

        // Calculate the perimeter of the rectangle (2 * (length + width))
        le = 2 * (a + b);

        // Output the calculated area and perimeter
        System.out.println(ar + " " + le);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
