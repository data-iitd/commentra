import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, i, j, m, s, t;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        n = scanner.nextInt();

        // Declare an array of size n
        int[] a = new int[n];

        // Read n elements into the array
        for (i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize total sum variable
        t = 0;

        // Outer loop to iterate through each element of the array
        for (i = 0; i < n; i++) {
            // Initialize sum for the current element
            s = 0;

            // Inner loop to calculate the product of the current element with all subsequent elements
            for (j = 1; j < n; j++) {
                // Skip elements that are not after the current element
                if (j <= i) {
                    continue;
                }

                // Calculate the product of the current element a[i] and a[j]
                m = a[i] * a[j];

                // Add the product to the sum for the current element
                s = s + m;
            }

            // Add the sum of products for the current element to the total
            t = t + s;
        }

        // Print the total sum of products
        System.out.println(t);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
