import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of items (N) and the total amount (X)
        long N = scanner.nextLong();
        long X = scanner.nextLong();

        // Initialize the answer and minimum value variables
        long ans = 0; // Counter for the number of items processed
        long min = Long.MAX_VALUE; // Initialize min to a large value

        // Process each item
        for (int i = 0; i < N; i++) {
            long tmp; // Temporary variable to hold the current item's value
            tmp = scanner.nextLong(); // Read the current item's value
            X -= tmp; // Subtract the item's value from total amount X
            ans++; // Increment the count of items processed
            if (tmp < min) min = tmp; // Update min if the current item is smaller
        }

        // Calculate how many more items can be added using the remaining amount
        ans += X / min; // Add the number of additional items that can be bought

        // Output the final answer
        System.out.println(ans);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
