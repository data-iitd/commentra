import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        int n; // Declare an integer variable 'n' to store the size of the array
        int[] a = new int[101]; // Declare an integer array 'a' of size 101

        n = scanner.nextInt(); // Read the size of the array from the user input

        // Allocate memory for the array 'a' of size 'n'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read each element of the array 'a' from the user input
        }

        // Print the last element of the array
        System.out.print(a[n - 1]);

        // Print the remaining elements of the array in reverse order
        for (int i = 1; i < n; i++) {
            System.out.print(" " + a[n - i - 1]); // Print the current element with a space before it
        }

        System.out.println(); // Print a newline character at the end
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
