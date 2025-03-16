
import java.util.Scanner;

public class s000061454{
    public static void main(String[] args) {
        // Declare variables for input values and calculations
        int a, b, n;
        int sum;
        int i, j;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Infinite loop to continuously accept input until an error occurs
        while(scanner.hasNextInt()) {
            // Read three integers a, b, and n from standard input
            a = scanner.nextInt();
            b = scanner.nextInt();
            n = scanner.nextInt();

            // Adjust 'a' to be the remainder when divided by 'b'
            a -= a / b * b;
            // Initialize sum to accumulate the result
            sum = 0;

            // Loop 'n' times to process each digit
            for(i = 1; i <= n; i++) {
                // Scale 'a' by 10 to shift left for the next digit
                a *= 10;

                // Find the largest digit 'j' (0-9) such that b*j <= a
                for(j = 9; j >= 0; j--) {
                    if(b * j <= a) break; // If condition is met, exit the loop
                }

                // Subtract the value of b*j from 'a'
                a -= b * j;
                // Add the digit 'j' to the sum
                sum += j;
            }

            // Output the final sum for the current input set
            System.out.println(sum);
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
