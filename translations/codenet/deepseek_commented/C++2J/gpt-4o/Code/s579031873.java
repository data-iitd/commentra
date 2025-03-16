import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the main class
    public static void main(String[] args) { // Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        long N = scanner.nextLong(); // Read the number of elements
        long X = scanner.nextLong(); // Read the target value

        long ans = 0; // Initialize the answer variable
        long min = Long.MAX_VALUE; // Initialize the minimum value variable

        for (int i = 0; i < N; i++) { // Loop through N elements
            long tmp = scanner.nextLong(); // Read the value into a temporary variable
            X -= tmp; // Subtract the value from X
            ans++; // Increment the answer count
            if (tmp < min) min = tmp; // Update the minimum value if the current value is smaller
        }

        ans += X / min; // Calculate the final answer by adding the quotient of X divided by the minimum value

        System.out.println(ans); // Print the final answer to the standard output

        scanner.close(); // Close the scanner
    } // End of main method
} // End of main class
// <END-OF-CODE>
