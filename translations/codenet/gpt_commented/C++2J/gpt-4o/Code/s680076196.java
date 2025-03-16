import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Declare four integer variables to hold input values
        int a, b, c, d;

        // Read four integer values from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Calculate the product of the differences between the first two and the last two integers
        // This represents the area of a rectangle defined by the points (a, b) and (c, d)
        System.out.println((a - c) * (b - d));

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
