import java.util.Scanner;

public class Main {
    // Method to swap the values of two integers
    public static void swap(int[] a, int[] b) {
        int tmp; // Temporary variable to hold one of the values during swap
        tmp = a[0]; // Store the value in tmp
        a[0] = b[0]; // Assign the value of b to a
        b[0] = tmp; // Assign the value stored in tmp to b
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        int a, b; // Declare two integer variables to hold user input

        // Infinite loop to continuously read input until termination condition is met
        while (true) {
            // Read two integers from user input
            a = scanner.nextInt();
            b = scanner.nextInt();
            
            // Check for the termination condition (both inputs are zero)
            if (a == 0 && b == 0) break;

            // If the second number is less than the first, swap them
            if (b < a) {
                int[] aArray = {a};
                int[] bArray = {b};
                swap(aArray, bArray);
                a = aArray[0];
                b = bArray[0];
            }
            
            // Print the sorted values of a and b
            System.out.println(a + " " + b);
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
