import java.util.Scanner;
// Import the Scanner class for reading input

public class Main {
    // Declare the main class

    public static void main(String[] args) {
        // Declare the main method

        int a, b, c, d, i, j;
        // Declare variables a, b, c, d, i, and j

        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input

        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        // Read four integers from the standard input and store them in variables a, b, c, and d

        i = a * b;
        // Multiply variables a and b and store the result in variable i

        j = c * d;
        // Multiply variables c and d and store the result in variable j

        if (i > j) {
            // Check if the value of i is greater than j

            System.out.println(i);
            // If true, print the value of i

        } else {
            // If the condition in the if statement is false

            System.out.println(j);
            // Print the value of j
        }

        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// End of the main class
