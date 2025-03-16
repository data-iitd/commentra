import java.util.Scanner;

public class Main {
    // Global variable to control debug output
    static boolean debug = false;

    public static void main(String[] args) {
        // Declare variables for input
        int n, k, x, y;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read input values: n (total items), k (threshold), x (cost for first k items), y (cost for items beyond k)
        n = scanner.nextInt();
        k = scanner.nextInt();
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Initialize sum to accumulate total cost
        int sum = 0;

        // Loop through each item from 1 to n
        for (int i = 1; i <= n; i++) {
            // If the current item index exceeds k, add cost y; otherwise, add cost x
            if (i > k) 
                sum += y; // Cost for items beyond the threshold
            else 
                sum += x; // Cost for items within the threshold
        }

        // Output the total calculated cost
        System.out.println(sum);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
