import java.util.Scanner;

public class RectangleCalculator {
    public static void main(String[] args) {
        // Declare integer variables to hold the input values and results
        int a, b, c, d;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integer values from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the area of a rectangle (length * width)
        c = a * b;

        // Calculate the perimeter of a rectangle (2 * (length + width))
        d = 2 * a + 2 * b;

        // Output the calculated area and perimeter
        System.out.println(c + " " + d);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
