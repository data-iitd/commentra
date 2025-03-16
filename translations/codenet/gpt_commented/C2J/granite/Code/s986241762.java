
import java.util.Scanner;

public class s986241762{
    public static void main(String[] args) {
        // Declare variables
        int n; // Number of elements in the array
        long sum = 0; // Variable to store the total sum of differences

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements from user input
        n = scanner.nextInt();
        
        // Declare an array of size n
        int[] a = new int[n];

        // Read n elements into the array from user input
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Iterate through the array to calculate the sum of differences
        for (int i = 1; i < n; i++) {
            // Check if the previous element is greater than the current element
            if (a[i - 1] > a[i]) {
                // Calculate the difference and add it to the sum
                sum += a[i - 1] - a[i];
                // Update the current element to be equal to the previous element
                a[i] = a[i - 1];
            }
        }

        // Print the total sum of differences
        System.out.println(sum);

        // Close the Scanner object
        scanner.close();
    }
}
