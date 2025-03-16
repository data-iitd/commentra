import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        
        // Read the number of elements in the array
        int N = scan.nextInt();
        
        // Initialize an array to hold the input integers
        int[] arr = new int[N];
        
        // Populate the array with input integers
        for (int i = 0; i < N; i++)
            arr[i] = scan.nextInt();
        
        // Create an instance of the Task class to perform the calculation
        Task tsk = new Task();
        
        // Solve the task and print the result
        System.out.println(tsk.solve(arr));
    }

    static class Task {
        public int solve(int[] arr) {
            // Get the length of the input array
            int n = arr.length;
            
            // Create a sorted copy of the input array
            int[] sorted = Arrays.copyOf(arr, n);
            Arrays.sort(sorted);
            
            // Calculate the total number of pairs possible in the array
            long total = (long) n * (n + 1) / 2;
            
            // Initialize pointers for binary search
            int l = 0, r = n - 1;
            
            // Perform binary search to find the median-like value
            while (l < r) {
                // Calculate the midpoint of the current search range
                int mid = l + (r - l) / 2;
                
                // Get the target value from the sorted array
                int target = sorted[mid];
                
                // Initialize counters for the current state
                int cur = 0;
                long cnt = 0;
                
                // Create a Binary Indexed Tree (BIT) for counting
                long[] bit = new long[2 * n + 2];
                
                // Initialize the BIT with base values
                for (int x = n + 1; x < bit.length; x += x & -x)
                    bit[x]++;
                
                // Count the number of elements less than or equal to the target
                for (int i = 0; i < n; i++) {
                    cur += arr[i] <= target ? 1 : -1;
                    
                    // Update the BIT with the current count
                    for (int x = cur + n + 1; x < bit.length; x += x & -x)
                        bit[x]++;
                    
                    // Count the number of valid pairs using the BIT
                    for (int x = cur + n; x > 0; x -= x & -x)
                        cnt += bit[x];
                }
                
                // Adjust the search range based on the count of pairs
                if (cnt >= total / 2 + 1)
                    r = mid; // Move left if count is sufficient
                else
                    l = mid + 1; // Move right if count is insufficient
            }
            
            // Return the median-like value found
            return sorted[l];
        }
    }
}
