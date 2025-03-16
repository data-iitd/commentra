import java.util.Scanner;
// Import the Scanner class for user input

public class SwapIntegers {
    // Class to contain the main method and swap functionality

    public static void swap(int[] a, int[] b) {
        // Method to swap two integers passed by reference using an array
        int tmp;
        // Declare a temporary variable to store the value of 'a'

        tmp = a[0];
        // Assign the value of 'b' to 'a'

        a[0] = b[0];
        // Assign the value of 'a' to 'b'

        b[0] = tmp;
        // Assign the value of the temporary variable 'tmp' back to 'b'
    }

    public static void main(String[] args) {
        // Main method to execute the program
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object for user input

        while (true) {
            // Infinite loop to read two integers from the user
            int a, b;
            // Declare two integer variables 'a' and 'b'

            a = scanner.nextInt();
            b = scanner.nextInt();
            // Read two integers from the user and store them in 'a' and 'b' respectively

            if (a == 0 && b == 0) break;
            // If both 'a' and 'b' are zero, break out of the loop

            if (b < a) {
                int[] aRef = {a};
                int[] bRef = {b};
                swap(aRef, bRef);
                a = aRef[0];
                b = bRef[0];
            }
            // If 'b' is less than 'a', swap their values

            System.out.println(a + " " + b);
            // Print the swapped values of 'a' and 'b'
        }

        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// End of the SwapIntegers class
