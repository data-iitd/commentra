// Import the Scanner class for reading input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables, A and B, and read their values from the standard input
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Declare an integer variable, ans, to store the result of our calculation
        int ans = 0;

        // Use an if statement to check the value of A
        if (A >= 6 && A <= 12) {
            // If A is between 6 and 12 (inclusive), calculate the answer as the integer division of B by 2
            ans = B / 2;
        } else if (A > 12) {
            // If A is greater than 12, assign the value of B directly to the ans variable
            ans = B;
        }

        // Print the value of ans
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
