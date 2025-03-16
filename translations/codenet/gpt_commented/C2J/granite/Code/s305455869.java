
import java.util.Scanner;

public class s305455869{
    public static void main(String[] args) {
        // Declare variables to hold input values and the result
        int a, b;
        int ans;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Initialize the answer variable to zero
        ans = 0;

        // Determine the value of ans based on the value of a
        if (a >= 13) {
            // If a is 13 or greater, set ans to b
            ans = b;
        } else if (a >= 6) {
            // If a is between 6 and 12, set ans to half of b
            ans = b / 2;
        }

        // Output the result
        System.out.println(ans);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
