
// Package declaration
package main;

import java.util.Scanner;

// Class declaration
public class s984400335{
    // Function declaration for finding the minimum number among given integers
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

    // s984400335 function declaration
    public static void main(String[] args) {
        // Creating a new instance of 'Scanner' class to read input values from the standard input
        Scanner scanner = new Scanner(System.in);

        // Declaring three integer variables for reading input values
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Printing the minimum value between 'n*a' and 'b' using 'System.out.println' method
        System.out.println(min(n * a, b));

        // Closing the 'Scanner' instance to release system resources
        scanner.close();
    }
}

// End of the code