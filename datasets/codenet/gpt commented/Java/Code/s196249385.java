import java.io.*;
import java.util.*;

public class Main {

    // Declare scanner for input and printer for output
    private static Scanner sc;
    private static Printer pr;

    // Method to solve the problem
    private static void solve() {
        // Read the number of elements and the value of k
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Initialize an array to hold the input values
        int[] a = new int[n];
        // Read the input values into the array
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Create a cumulative sum array to store the sum of elements up to each index
        long[] cumsum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            cumsum[i + 1] = cumsum[i] + a[i]; // Calculate cumulative sum
        }

        // List to hold all possible subarray sums
        List<Long> b = new ArrayList<>(n * (n + 1) / 2);
        long max = 0; // Variable to track the maximum subarray sum
        // Generate all subarray sums and find the maximum
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long subarraySum = cumsum[j + 1] - cumsum[i]; // Calculate subarray sum
                b.add(subarraySum); // Add to the list of subarray sums
                max = Math.max(max, subarraySum); // Update maximum if necessary
            }
        }
        // Collections.sort(b, Collections.reverseOrder()); // Sorting is commented out

        // Find the highest one bit in the maximum subarray sum
        long mask = Long.highestOneBit(max);
        // Filter the subarray sums based on the current mask
        while (mask > 0) {
            List<Long> tmp = new ArrayList<>();
            for (long e : b) {
                // Check if the current subarray sum has the current bit set
                if ((e & mask) != 0) {
                    tmp.add(e); // Add to temporary list if the bit is set
                }
            }
            
            // If we have enough elements, keep the filtered list
            if (tmp.size() >= k) {
                b = tmp;
            }
            
            // Shift the mask to check the next bit
            mask >>= 1;
        }
        
        // Check if we have less than k valid subarray sums
        if (b.size() < k) {
            pr.println(0); // Print 0 if not enough sums
        } else {
            long ans = -1L; // Initialize answer with -1 for bitwise AND operation
            // Perform bitwise AND on the remaining subarray sums
            for (long e : b) {
                ans &= e; // Update answer with the AND of the current sum
            }
            
            pr.println(ans); // Print the final answer
        }
    }

    // ---------------------------------------------------
    public static void main(String[] args) {
        // Initialize scanner and printer
        sc = new Scanner(System.in);
        pr = new Printer(System.out);
        
        // Call the solve method to execute the logic
        solve();
        
        // Close the printer and scanner
        pr.close();
        sc.close();
    }

    // Custom printer class extending PrintWriter for output
    static class Printer extends PrintWriter {
        Printer(OutputStream out) {
            super(out);
        }
    }
}
