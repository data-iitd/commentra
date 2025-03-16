import java.util.Arrays; // Importing utility class for array operations
import java.util.Scanner; // Importing utility class for input handling

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize Scanner object to read input
        int n = in.nextInt(); // Read the number of elements
        Long[] ans = new Long[n]; // Initialize array to store long integers
        
        // Populate the array with input values
        for (int i = 0; i < n; i++) {
            ans[i] = in.nextLong();
        }
        
        // Sort the array in ascending order
        Arrays.sort(ans);
        
        // Initialize count with the largest element in the array
        Long count = ans[n - 1];
        
        // Iterate through the array from the second-to-last element to the first
        for (int i = n - 2; i >= 0; i--) {
            if (ans[i] < ans[i + 1]) {
                count += ans[i]; // Add the current element to count if it's less than the next element
            } else {
                while (ans[i] >= ans[i + 1]) {
                    ans[i]--; // Decrease the current element until it's less than the next element
                }
                if (ans[i] > 0) {
                    count += ans[i]; // Add the adjusted current element to count
                }
            }
        }
        
        // Print the final count
        System.out.println(count);
    }
}
