import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input values and loop counters
        int n, r, p, c;
        int i, j, k;
        int[] a = new int[51]; // Array to hold values
        int[] b = new int[51]; // Temporary array to hold values

        Scanner scanner = new Scanner(System.in);

        // Infinite loop to continuously accept input until a termination condition is met
        while (true) {
            // Read the values of n (number of elements) and r (number of operations)
            n = scanner.nextInt();
            r = scanner.nextInt();

            // Check for termination condition: if both n and r are zero, exit the loop
            if (n == 0 && r == 0) {
                break;
            }

            // Initialize array a with values from 1 to n
            for (i = 0; i < n; i++) {
                a[i] = i + 1;
            }

            // Process each operation
            for (i = 0; i < r; i++) {
                // Read the values of p (number of elements to move) and c (number of elements to copy)
                p = scanner.nextInt();
                c = scanner.nextInt();

                // Copy elements from a to b
                for (j = 0; j < c; j++) {
                    b[j] = a[n - p - c + j]; // Adjusted index for Java (0-based)
                }

                // Shift elements in array a to make space for the new elements
                for (j = 0; j < p - 1; j++) {
                    a[n - p - c + j] = a[n - p + j]; // Move elements to the left
                }

                // Insert the copied elements from b back into array a
                for (j = n - p - c, k = 0; k < c; j++, k++) {
                    a[j] = b[k]; // Place elements from b into the correct position in a
                }

                /*
                Uncomment the following lines to debug and print the current state of array a
                for (j = 0; j < n; j++) {
                    System.out.println(a[j]);
                }
                System.out.println("---");
                */
            }

            // Print the last element of array a after all operations are completed
            System.out.println(a[n - 1]);
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
