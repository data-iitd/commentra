// Package declaration
import java.util.Scanner;

// Class declaration
public class Main {

    // Method to find the minimum number among given integers
    public static int min(int... nums) {
        // Initializing the minimum value with the first integer
        int min = nums[0];

        // Iterating through the array 'nums' to find the minimum value
        for (int v : nums) {
            // If the current value is less than the minimum value, update the minimum value
            if (v < min) {
                min = v;
            }
        }

        // Returning the minimum value
        return min;
    }

    // Main method declaration
    public static void main(String[] args) {
        // Creating a Scanner object for reading input values
        Scanner scanner = new Scanner(System.in);

        // Declaring three integer variables for reading input values
        int n, a, b;

        // Reading input values from the standard input
        n = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Printing the minimum value between 'n*a' and 'b'
        System.out.println(min(n * a, b));

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
