import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input number and loop counter
        int n, i, a;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read an integer input from the user
        n = scanner.nextInt();

        // Loop from 1 to n (inclusive)
        for (i = 1; i <= n; i++) {
            // Assign the current loop index to a
            a = i;

            // Check if the current number is divisible by 3
            if (a % 3 == 0) {
                // If divisible by 3, print the number
                System.out.print(" " + i);
            } else {
                // If not divisible by 3, check if it contains the digit '3'
                while (a > 0) {
                    // Check if the last digit of a is 3
                    if (a % 10 == 3) {
                        // If it contains the digit '3', print the number
                        System.out.print(" " + i);
                        // Set a to 0 to exit the loop
                        a = 0;
                    }
                    // Remove the last digit from a
                    a = a / 10;
                }
            }
        }

        // Print a newline character after all numbers have been processed
        System.out.println();

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
