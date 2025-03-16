// Importing necessary packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaring variables
        int x, a, b;

        // Creating a Scanner object to read input values
        Scanner scanner = new Scanner(System.in);

        // Reading input values from standard input
        x = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Logic block to check if b is less than or equal to a
        if (b - a <= 0) {
            // Base case: If b is less than or equal to a
            System.out.println("delicious");
        } else if (b - a <= x) {
            // Next case: If b is greater than a but less than or equal to x
            System.out.println("safe");
        } else {
            // Default case: If none of the above conditions are met
            System.out.println("dangerous");
        }

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
