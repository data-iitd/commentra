import java.util.Arrays; // Import the Arrays class for sorting the array
import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Declare and initialize variables
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n; // Number of elements in the array
        n = scanner.nextInt(); // Read the number of elements from the user
        int a; // Size of the subarray to be summed
        a = scanner.nextInt(); // Read the size of the subarray from the user
        int sum = 0; // Initialize the sum variable to zero
        int[] s = new int[n]; // Declare an array of size n to store the input elements

        // Read the elements of the array from the user
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt(); // Read the i-th element of the array
        }

        // Sort the array in ascending order
        Arrays.sort(s); // Sort the array using the sort method from the Arrays class

        // Calculate the sum of the last 'a' elements of the sorted array
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i]; // Add the current element to the sum
        }

        // Print the result
        System.out.println(sum); // Print the sum of the last 'a' elements
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
