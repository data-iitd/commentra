import java.util.Scanner;
import java.util.Vector;

public class Solution {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize a vector to store the input numbers
        Vector<Long> a = new Vector<Long>(n);
        // Read the input numbers into the vector
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong());
        }

        // Create a copy of the input vector to store absolute values
        Vector<Long> abs_a = new Vector<Long>(a);

        // Convert all elements in abs_a to their absolute values
        for (int i = 0; i < n; i++) {
            if (abs_a.get(i) < 0) {
                abs_a.set(i, -abs_a.get(i));
            }
        }

        // Initialize variables to calculate the sum of absolute values and find the minimum absolute value
        long ans = 0;
        long min = abs_a.get(0);
        // Iterate through the absolute values to calculate the total sum and find the minimum
        for (int i = 0; i < n; i++) {
            ans += abs_a.get(i); // Accumulate the sum of absolute values
            if (min > abs_a.get(i)) {
                min = abs_a.get(i); // Update the minimum absolute value found
            }
        }

        // Count the number of negative numbers in the original array
        int num_negative = 0;
        for (int i = 0; i < n; i++) {
            if (a.get(i) < 0) {
                num_negative++; // Increment count for each negative number
            }
        }

        // If the count of negative numbers is odd, adjust the total sum
        if (num_negative % 2) {
            ans -= min * 2; // Subtract twice the minimum absolute value from the total sum
        }

        // Output the final result
        System.out.println(ans);
    }
}

