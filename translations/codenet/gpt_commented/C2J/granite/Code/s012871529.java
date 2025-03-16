
import java.util.Scanner;

public class s012871529{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables to hold the input values
        int a, b;

        // Read two integers from the user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
        System.out.printf("%d %d\n", a * b, 2 * (a + b));

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
