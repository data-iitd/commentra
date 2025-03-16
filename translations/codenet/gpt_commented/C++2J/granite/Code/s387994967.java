
import java.util.Scanner;

public class s387994967{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables A and B
        int A, B;

        // Read input values for A and B from the user
        A = scanner.nextInt();
        B = scanner.nextInt();

        // Check if A is between 6 (inclusive) and 13 (exclusive)
        if (A < 13 && A >= 6) {
            // If true, output half of B
            System.out.println(B / 2);
        }

        // Check if A is less than 6
        if (A < 6) {
            // If true, output 0
            System.out.println(0);
        }

        // Check if A is greater than or equal to 13
        if (A >= 13) {
            // If true, output the value of B
            System.out.println(B);
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
