import java.util.Scanner;
// Import the Scanner class for user input

public class Main {
    // Main class to contain the program
    public static void main(String[] args) {
        // Main method to start the execution of the program
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the user

        int n, tmp; // Declare variables n and tmp
        long min = 1000000, max = -1000000, sum = 0; // Initialize variables min, max, and sum

        System.out.print("Enter the number of integers: ");
        n = scanner.nextInt();
        // Read the number of integers to be entered from the user

        for (int i = 0; i < n; i++) {
            // Use a for loop to read and process each integer
            tmp = scanner.nextInt();
            // Read the next integer from the user and store it in variable tmp

            if (min > tmp) min = tmp;
            // If the current integer is smaller than the current minimum, update the minimum
            if (max < tmp) max = tmp;
            // If the current integer is larger than the current maximum, update the maximum
            sum += tmp;
            // Add the current integer to the sum
        }

        System.out.printf("%d %d %d\n", min, max, sum);
        // Print the minimum, maximum, and sum of the entered integers

        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// Main class ends with a closing brace
// <END-OF-CODE>
