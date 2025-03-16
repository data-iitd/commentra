
import java.util.Scanner;

public class s400924672{
    public static void main(String[] args) {
        // Declare variables for radius (r), distance (D), and initial value (x)
        int r, D, x;

        // Create a Scanner object to read input values from the user
        Scanner scanner = new Scanner(System.in);

        // Read input values for r, D, and x from the user
        r = scanner.nextInt();
        D = scanner.nextInt();
        x = scanner.nextInt();

        // Loop to perform calculations and print results for 10 iterations
        for (int i = 1; i <= 10; i++) {
            // Calculate and print the result of the formula r*x - D
            System.out.println(r * x - D);

            // Update x for the next iteration using the formula r*x - D
            x = r * x - D;
        }

        // Close the Scanner object
        scanner.close();
    }
}
