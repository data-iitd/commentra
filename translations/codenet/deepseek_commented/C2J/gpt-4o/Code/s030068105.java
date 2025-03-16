import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read an integer value for n from the standard input
        int[] data = new int[n]; // Declare an array of integers with size n

        // Read n integers from the standard input and store them in the array
        for (int i = 0; i < n; i++) {
            data[i] = scanner.nextInt();
        }

        int max = 0, index = 0; // Initialize max to 0 and index to 0

        // Iterate through the array to find the maximum value and its index
        for (int i = 0; i < n; i++) {
            if (data[i] > max) {
                max = data[i];
                index = i; // Update the index of the maximum value
            }
        }

        int a = 0; // Initialize a variable to store the sum of elements excluding the maximum value

        // Iterate through the array again, excluding the element at the index of the maximum value, and sum up the remaining elements
        for (int i = 0; i < n; i++) {
            if (i != index) {
                a += data[i];
            }
        }

        // Compare the sum of the remaining elements (a) with the maximum value (max)
        if (a > max) {
            System.out.println("Yes"); // Print "Yes" if the sum of remaining elements is greater than the maximum value
        } else {
            System.out.println("No"); // Print "No" otherwise
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
