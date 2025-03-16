import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Function to print output to the console
    static void out(Object... x) {
        System.out.println(Arrays.toString(x));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Scanner for reading input

        // Read the number of elements (N), maximum count (C), and time limit (K)
        int N = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        int[] t = new int[N]; // Create an array to hold the time values

        // Read N time values from input
        for (int i = 0; i < N; i++) {
            t[i] = sc.nextInt(); // Store each time value in the array
        }

        Arrays.sort(t); // Sort the time values in ascending order

        // Initialize variables for counting groups and tracking the end time
        int ans = 1; // Start with one group
        int cnt = 1; // Count of elements in the current group
        int end = t[0] + K; // Calculate the end time for the first group

        // Iterate through the sorted time values
        for (int i = 1; i < N; i++) {
            // Check if we can add the current time to the current group
            if (cnt < C && t[i] <= end) {
                cnt++; // Increment the count of the current group
            } else {
                // Start a new group since the current time exceeds the end time
                cnt = 1; // Reset the count for the new group
                end = t[i] + K; // Update the end time for the new group
                ans++; // Increment the group count
            }
        }
        out(ans); // Output the total number of groups formed
    }
}
// <END-OF-CODE>
