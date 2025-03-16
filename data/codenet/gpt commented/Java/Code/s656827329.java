import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        
        // Initialize an array to hold the input values
        int[] a = new int[n];
        
        // Populate the array with user input
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize variables to count the number of direction changes
        int count = 1; // Start with one segment
        int now = 0;   // Current direction (1 for increasing, -1 for decreasing)
        int bef = 0;   // Previous direction
        
        // Loop through the array starting from the second element
        for (int i = 1; i < n; i++) {
            // Determine the current direction based on the comparison of adjacent elements
            if (a[i - 1] < a[i]) {
                now = 1; // Increasing
            } else if (a[i - 1] > a[i]) {
                now = -1; // Decreasing
            } else {
                continue; // Skip if the elements are equal
            }
            
            // If this is the first direction change, set bef to now
            if (bef == 0) {
                bef = now;
            }
            
            // Check if the current direction is different from the previous direction
            if (bef != now) {
                count++; // Increment the count of direction changes
                bef = 0; // Reset bef to indicate a new segment
            }
        }
        
        // Output the total number of direction changes
        System.out.println(count);
    }
}
