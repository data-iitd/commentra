
import java.util.*; // Import the Scanner class from the java.util package for input operations.

public class s050708710{ // Define the s050708710 class as the entry point of the program.
    public static void main(String[] args) { // Define the main method which is the entry point of the program.
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
        int r = sc.nextInt(); // Read an integer value from the standard input and store it in the variable 'r'.
        int g = sc.nextInt(); // Read another integer value from the standard input and store it in the variable 'g'.
        int b = sc.nextInt(); // Read another integer value from the standard input and store it in the variable 'b'.
        int n = sc.nextInt(); // Read another integer value from the standard input and store it in the variable 'n'.
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
    }
}
