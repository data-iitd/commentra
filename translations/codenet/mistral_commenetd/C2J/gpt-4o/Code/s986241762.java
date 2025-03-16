import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n; // Declare an integer variable 'n'
        long sum = 0; // Declare and initialize a long integer variable 'sum' with zero value

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the user
        System.out.print("Enter the number of elements in the array: ");
        n = scanner.nextInt();

        // Declare an integer array 'a' of size 'n'
        int[] a = new int[n];

        // Read the elements of the array from the user
        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element number " + (i + 1) + ": ");
            a[i] = scanner.nextInt(); // Read an integer value and store it in the array 'a'
        }

        // Calculate the sum of the differences between adjacent elements in the array
        for (int i = 1; i < n; i++) {
            // Check if the previous element is greater than the current element
            if (a[i - 1] > a[i]) {
                // If true, add the difference to the sum
                sum += a[i - 1] - a[i];
                // Swap the elements to maintain the array in non-decreasing order
                a[i] = a[i - 1];
            }
        }

        // Print the sum of the differences
        System.out.println("The sum of the differences is: " + sum);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
