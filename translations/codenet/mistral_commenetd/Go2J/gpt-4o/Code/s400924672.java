// Package declaration
import java.util.Scanner;

// Class declaration
public class Main {
    // Main method
    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Declaring variables r, D, and x of type int
        int r, D, x;

        // Reading input values for r, D, and x from the standard input
        r = scanner.nextInt();
        D = scanner.nextInt();
        x = scanner.nextInt();

        // Comment for the for loop
        // Loop runs 10 times
        for (int i = 1; i <= 10; i++) {
            // Print the result of the current iteration
            System.out.println(r * x - D);

            // Update the value of x for the next iteration
            x = r * x - D;
        }

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
