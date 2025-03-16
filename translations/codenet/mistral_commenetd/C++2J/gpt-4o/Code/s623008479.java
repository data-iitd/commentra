import java.util.Arrays; // Import the Arrays class for sorting
import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input

        int n = scanner.nextInt(); // Read the number of elements
        int k = scanner.nextInt(); // Read the size of the subarray

        int[] l = new int[n]; // Declare an array l of size n

        for (int i = 0; i < n; i++) { // Iterate through the elements of the array l and read each element
            l[i] = scanner.nextInt();
        }

        Arrays.sort(l); // Sort the array l in ascending order

        int ans = 0; // Initialize an integer variable ans to 0 for storing the sum of the first k elements in descending order

        for (int i = 0; i < k; i++) { // Iterate through the last k elements in descending order and add their values to the variable ans
            ans += l[n - 1 - i];
        }

        System.out.println(ans); // Output the value of the variable ans to the console
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
