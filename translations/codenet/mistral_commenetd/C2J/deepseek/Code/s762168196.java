import java.util.Scanner;

public class ArrayOperations {
    public static void main(String[] args) {
        // Declare variables
        int[] a = new int[10000];
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, n, i;
        long sum = 0;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        System.out.print("Enter the number of elements in the array: ");
        n = scanner.nextInt();

        // Initialize a for loop to read elements into the array and calculate sum
        for (i = 0; i < n; i++) {
            // Read each element into the array
            System.out.print("Enter element " + (i + 1) + ": ");
            a[i] = scanner.nextInt();

            // Add the current element to the sum
            sum += a[i];
        }

        // Initialize a for loop to find minimum and maximum elements in the array
        for (i = 0; i < n; i++) {
            // Find the minimum and maximum elements
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
        }

        // Print the minimum, maximum, and sum
        System.out.println("Minimum element is " + min);
        System.out.println("Maximum element is " + max);
        System.out.println("Sum of all elements is " + sum);

        // Close the scanner
        scanner.close();
    }
}
