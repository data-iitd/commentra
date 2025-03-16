import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MinDifferenceSubset {
    public static void main(String[] args) {
        // Declare variables
        int n, k; // n: number of elements, k: size of the subset
        int ans = 1000000001; // Initialize ans to a large value to find the minimum difference

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements (n) and the size of the subset (k)
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Create a list to store the input elements
        List<Integer> vec = new ArrayList<>();

        // Read n integers from input and store them in the list
        for (int i = 0; i < n; i++) {
            vec.add(scanner.nextInt()); // Add the integer to the list
        }

        // Sort the list in non-decreasing order
        Collections.sort(vec);

        // Iterate through the sorted list to find the minimum difference
        for (int i = 0; i + k - 1 < n; i++) {
            // Calculate the difference between the maximum and minimum of the current subset of size k
            int diff = vec.get(i + k - 1) - vec.get(i);
            
            // Update the minimum difference found so far
            if (diff < ans) {
                ans = diff; // Update ans if a smaller difference is found
            }
        }

        // Output the minimum difference found
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
