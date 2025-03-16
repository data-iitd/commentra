import java.util.Scanner; // Import the Scanner class for input operations
import java.util.Arrays;  // Import the Arrays class for sorting the array

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        int[] s = new int[10]; // Declare an integer array 's' of size 10
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input

        // Read 10 integers from the user and store them in the array 's'
        for (int i = 0; i < 10; i++) {
            s[i] = scanner.nextInt(); // Read an integer from the standard input and store it in the array 's' at the current index
        }

        // Sort the array 's' in ascending order using the Arrays.sort method
        Arrays.sort(s);

        // Print the 4th, 5th and 6th smallest elements from the sorted array 's'
        for (int i = 9; i > 6; i--) { // Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
            System.out.println(s[i]); // Print the current element of the array 's' to the standard output
        }

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
