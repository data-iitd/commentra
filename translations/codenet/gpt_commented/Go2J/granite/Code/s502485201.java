
import java.util.Scanner;

public class s502485201{
    public static void main(String[] args) {
        // Declare variables for radius (r), distance (d), and initial value (x)
        int r, d, x;

        // Create a Scanner object to read input values from standard input
        Scanner scanner = new Scanner(System.in);

        // Read input values for r, d, and x from standard input
        r = scanner.nextInt();
        d = scanner.nextInt();
        x = scanner.nextInt();

        // Loop 10 times to perform calculations based on the input values
        for (int i = 0; i < 10; i++) {
            // Update x using the formula: x = r * x - d
            x = r * x - d;

            // Print the updated value of x to the standard output
            System.out.println(x);
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
