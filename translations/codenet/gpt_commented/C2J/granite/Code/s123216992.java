
import java.util.Scanner;

// Function to swap the values of two integers
void swap(int[] a, int[] b) {
    int tmp; // Temporary variable to hold one of the values during swap
    tmp = a[0]; // Store the value pointed by a in tmp
    a[0] = b[0];  // Assign the value pointed by b to the location pointed by a
    b[0] = tmp; // Assign the value stored in tmp to the location pointed by b
}

public class s123216992{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner object to read user input
        int[] a = new int[1]; // Declare an integer array to hold the first input
        int[] b = new int[1]; // Declare an integer array to hold the second input

        // Infinite loop to continuously read input until termination condition is met
        while (true) {
            // Read two integers from user input
            a[0] = scanner.nextInt();
            b[0] = scanner.nextInt();
            
            // Check for the termination condition (both inputs are zero)
            if (a[0] == 0 && b[0] == 0) break;

            // If the second number is less than the first, swap them
            if (b[0] < a[0]) swap(a, b);
            
            // Print the sorted values of a and b
            System.out.println(a[0] + " " + b[0]);
        }

        scanner.close(); // Close the scanner object to release system resources
    }
}

