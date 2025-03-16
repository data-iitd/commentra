import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare arrays and variables
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[200000];
        int[] tmpa = new int[200000];
        int[] light = new int[200010];

        // Input the initial values into the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Calculate the influence range for each element in 'a'
        for (int i = 0; i < n; i++) {
            int r = i - a[i]; // Calculate the left boundary
            int l = i + a[i]; // Calculate the right boundary
            light[Math.max(0, r)]++; // Increment the start of the influence range
            if (l + 1 <= n) {
                light[l + 1]--; // Decrement the end of the influence range
            }
        }

        // Perform k iterations to update the array 'a'
        for (int i = 0; i < k; i++) {
            int sum = 0;

            // Update 'a' based on the current influence ranges
            for (int j = 0; j < n; j++) {
                tmpa[j] = a[j]; // Store the current state of 'a' in 'tmpa'
                sum += light[j]; // Accumulate the influence
                a[j] = sum; // Update 'a' with the accumulated influence
            }

            // Update the influence ranges based on the new values in 'a'
            for (int j = 0; j < n; j++) {
                int r = j - tmpa[j]; // Calculate the left boundary for the previous state
                int l = j + tmpa[j]; // Calculate the right boundary for the previous state
                light[Math.max(0, r)]--; // Decrement the start of the previous influence range
                if (l + 1 <= n) {
                    light[l + 1]++; // Increment the end of the previous influence range
                }

                r = j - a[j]; // Calculate the new left boundary
                l = j + a[j]; // Calculate the new right boundary
                light[Math.max(0, r)]++; // Increment the start of the new influence range
                if (l + 1 <= n) {
                    light[l + 1]--; // Decrement the end of the new influence range
                }
            }

            // Check if all elements in 'a' are the same and equal to n
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
                    isSame = false; // Set flag to false if any elements differ
                    break;
                }
            }
            // If all elements are the same and equal to n, exit the loop
            if (isSame && a[0] == n) {
                break;
            }
        }

        // Output the final state of the array 'a'
        for (int j = 0; j < n; j++) {
            System.out.print(a[j]); // Print each element of 'a'
            if (j < n - 1) {
                System.out.print(" "); // Print a space after each element except the last
            }
        }
        System.out.println(); // Print a newline after the last element
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
