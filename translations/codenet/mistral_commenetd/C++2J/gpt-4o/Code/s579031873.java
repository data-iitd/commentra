import java.util.Scanner; // Import the Scanner class for input.
import java.util.ArrayList; // Import the ArrayList class for dynamic arrays.

public class Main { // Define the main class.
    public static void main(String[] args) { // Start of the main method.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input.

        long N = scanner.nextLong(); // Read a long integer from input and assign it to N.
        long X = scanner.nextLong(); // Read a long integer from input and assign it to X.

        long ans = 0; // Initialize a long variable named ans to zero.
        long min = 1000000000; // Initialize a long variable named min to a large value.

        for (int i = 0; i < N; i++) { // Start of a for loop that iterates from 0 to N-1.
            long tmp = scanner.nextLong(); // Read a long integer from input and assign it to tmp.

            X -= tmp; // Subtract tmp from X.
            ans++; // Increment ans by 1.

            if (tmp < min) min = tmp; // If tmp is smaller than the current minimum value, update the minimum value.
        }

        ans += X / min; // Divide X by the minimum value and add the quotient to ans.

        System.out.println(ans); // Output the value of ans to the standard output.

        scanner.close(); // Close the scanner to free resources.
    } // End of the main method.
} // End of the main class.
