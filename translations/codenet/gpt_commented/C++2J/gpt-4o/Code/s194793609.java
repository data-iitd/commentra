import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize an array to store the input numbers
        long[] a = new long[n];
        // Read the input numbers into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }

        // Create a copy of the input array to store absolute values
        long[] abs_a = new long[n];
        for (int i = 0; i < n; i++) {
            abs_a[i] = Math.abs(a[i]); // Convert to absolute values
        }

        // Initialize variables to calculate the sum of absolute values and find the minimum absolute value
        long ans = 0;
        long min = abs_a[0];
        // Iterate through the absolute values to calculate the total sum and find the minimum
        for (long e : abs_a) {
            ans += e; // Accumulate the sum of absolute values
            if (min > e) {
                min = e; // Update the minimum absolute value found
            }
        }

        // Count the number of negative numbers in the original array
        int num_negative = 0;
        for (long e : a) {
            if (e < 0) {
                num_negative++; // Increment count for each negative number
            }
        }

        // If the count of negative numbers is odd, adjust the total sum
        if (num_negative % 2 != 0) {
            ans -= min * 2; // Subtract twice the minimum absolute value from the total sum
        }

        // Output the final result
        System.out.println(ans);
    }
}
// <END-OF-CODE>
