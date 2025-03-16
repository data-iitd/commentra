import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MinDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int k = scanner.nextInt(); // Read the subarray size
        List<Integer> vec = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int t = scanner.nextInt(); // Read each element and add it to the list
            vec.add(t);
        }
        
        Collections.sort(vec); // Sort the list in ascending order
        int ans = Integer.MAX_VALUE; // Initialize the answer with a large number
        
        for (int i = 0; i + k - 1 < n; i++) { // Iterate through the sorted list
            int diff = vec.get(i + k - 1) - vec.get(i); // Calculate the difference between the max and min in the subarray
            if (diff < ans) { // Update the answer if the current difference is smaller
                ans = diff;
            }
        }
        
        System.out.println(ans); // Output the minimum difference
        scanner.close();
    }
}
// <END-OF-CODE>
