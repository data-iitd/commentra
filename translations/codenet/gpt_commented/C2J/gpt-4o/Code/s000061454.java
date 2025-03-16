import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input values and calculations
        int a, b, n;
        int sum;
        
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Infinite loop to continuously accept input until an error occurs
        while (true) {
            // Read three integers a, b, and n from standard input
            // Break the loop if input fails
            if (!scanner.hasNextInt()) break;
            a = scanner.nextInt();
            if (!scanner.hasNextInt()) break;
            b = scanner.nextInt();
            if (!scanner.hasNextInt()) break;
            n = scanner.nextInt();

            // Adjust 'a' to be the remainder when divided by 'b'
            a -= a / b * b;
            // Initialize sum to accumulate the result
            sum = 0;

            // Loop 'n' times to process each digit
            for (int i = 1; i <= n; i++) {
                // Scale 'a' by 10 to shift left for the next digit
                a *= 10;

                // Find the largest digit 'j' (0-9) such that b*j <= a
                int j;
                for (j = 9; j >= 0; j--) {
                    if (b * j <= a) break; // If condition is met, exit the loop
                }

                // Subtract the value of b*j from 'a'
                a -= b * j;
                // Add the digit 'j' to the sum
                sum += j;
            }

            // Output the final sum for the current input set
            System.out.println(sum);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
