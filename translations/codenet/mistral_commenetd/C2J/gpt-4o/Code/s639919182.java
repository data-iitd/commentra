import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer array 'v' of size 10 and an integer variable 'sum' to store the sum of array elements.
        int[] v = new int[10]; // Declare an integer array 'v' of size 10.
        int sum = 0;           // Declare an integer variable 'sum' and initialize it to zero.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input.

        // Read 10 integers from the user and store them in the array 'v'.
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter the value for index " + i + ": ");
            v[i] = scanner.nextInt(); // Read an integer value from the user and store it in the current index of the array 'v'.
        }

        // Calculate the sum of all elements in the array 'v'.
        for (int i = 0; i < 10; i++) {
            sum += v[i]; // Add the value of the current element in the array 'v' to the variable 'sum'.
        }

        // Print the sum of all elements in the array 'v'.
        System.out.println(sum); // Display the sum of all elements in the array 'v'.

        scanner.close(); // Close the scanner to prevent resource leaks.
    }
}
// <END-OF-CODE>
