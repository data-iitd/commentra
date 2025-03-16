
import java.util.Scanner;

public class s914373115{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Call function B to execute its logic
        B(scanner);

        // Close the Scanner object
        scanner.close();
    }

    public static void B(Scanner scanner) {
        long long x, sum; // Declare variables for input and sum
        x = scanner.nextLong(); // Read input value x from the user
        int i = 0; // Declare a counter variable
        sum = 100; // Initialize sum to 100

        // Loop until sum is less than x
        while (sum < x) {
            // Increase sum by 1% of its current value
            sum += sum / 100;
            i++; // Increment the counter variable
        }

        // Output the number of iterations needed to exceed or meet x
        System.out.println(i);
    }
}
