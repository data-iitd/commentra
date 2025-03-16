import java.util.Scanner;
// This line imports the Scanner class for input

public class Main {
    // Main class definition

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object for reading input

        while (scanner.hasNextInt()) {
            // Continue reading input while there are integers available
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            // Read two integers a and b

            int x = a + b;
            // Assign the sum of a and b to x

            int w = 0;
            // Initialize w to zero

            while (x > 0) {
                w++;
                // Increment w each time through the loop
                x /= 10;
                // Divide x by 10 to get the next digit
            }
            System.out.println(w);
            // Print the value of w, which represents the number of digits in the sum of a and b
        }
        // This while loop continues to read input until there are no more integers

        scanner.close();
        // Close the scanner to free resources
    }
}
// The main function does not need to return a value in Java

// <END-OF-CODE>
