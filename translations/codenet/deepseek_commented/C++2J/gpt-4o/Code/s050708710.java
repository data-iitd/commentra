import java.util.Scanner; // Import the Scanner class for input operations.

public class Main { // Define the Main class.
    public static void main(String[] args) { // Define the main method which is the entry point of the program.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input.
        
        int r = scanner.nextInt(); // Read the first integer input for 'r'.
        int g = scanner.nextInt(); // Read the second integer input for 'g'.
        int b = scanner.nextInt(); // Read the third integer input for 'b'.
        int n = scanner.nextInt(); // Read the fourth integer input for 'n'.
        
        int ans = 0; // Initialize a variable 'ans' to 0 to store the count of valid combinations.

        // Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
        for (int i = 0; i <= n / r; ++i) {
            for (int j = 0; j <= n / g; ++j) {
                int num = n - r * i - g * j; // Calculate the remaining value after using 'r * i' and 'g * j'.
                if (num >= 0 && num % b == 0) { // Check if 'num' is non-negative and divisible by 'b'.
                    ++ans; // Increment 'ans' if the conditions are met.
                }
            }
        }

        System.out.println(ans); // Print the value of 'ans' which represents the count of valid combinations.
        scanner.close(); // Close the scanner to prevent resource leaks.
    } // End of main method.
} // End of Main class.
