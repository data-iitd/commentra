// Include the Scanner library for input operations.
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare four integer variables to store input values.
        int r, g, b, n;

        // Create a Scanner object to read input from the standard input (keyboard).
        Scanner sc = new Scanner(System.in);

        // Read four integers from the standard input.
        r = sc.nextInt();
        g = sc.nextInt();
        b = sc.nextInt();
        n = sc.nextInt();

        // Initialize a variable 'ans' to 0 to store the count of valid combinations.
        int ans = 0;

        // Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
        for (int i = 0; i <= n / r; i++) {
            for (int j = 0; j <= n / g; j++) {
                int num = n - r * i - g * j; // Calculate the remaining value after using 'r * i' and 'g * j'.
                if (num >= 0 && num % b == 0) // Check if 'num' is non-negative and divisible by 'b'.
                {
                    ans++; // Increment 'ans' if the conditions are met.
                }
            }
        }

        // Print the value of 'ans' which represents the count of valid combinations.
        System.out.println(ans);
    }
}

