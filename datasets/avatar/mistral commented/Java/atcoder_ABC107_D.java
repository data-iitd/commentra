
import java.io.BufferedInputStream; // Buffered input stream for reading from System.in
import java.util.Arrays; // For array manipulation functions like sorting and copying
import java.util.HashMap; // For storing frequency counts
import java.util.Scanner; // For reading input
import java.util.TreeMap; // For maintaining a sorted map

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for reading input
        Scanner scan = new Scanner(new BufferedInputStream(System.in));

        // Read the number of elements in the array
        int N = scan.nextInt();

        // Allocate memory for the array
        int[] arr = new int[N];

        // Read the elements of the array
        for (int i = 0; i < N; i++) {
            arr[i] = scan.nextInt(); // Read an element
        }

        // Create an instance of the Task class and call its solve method
        Task tsk = new Task();
        System.out.println(tsk.solve(arr)); // Print the result
    }

    static class Task {
        // Method to solve the problem
        public int solve(int[] arr) {
            int n = arr.length; // Number of elements in the array

            // Create a copy of the array for sorting
            int[] sorted = Arrays.copyOf(arr, n);
            Arrays.sort(sorted); // Sort the copy in ascending order

            long total = (long) n * (n + 1) / 2; // Calculate the total sum of elements from 1 to n^2

            int l = 0, r = n - 1; // Initialize left and right pointers for binary search

            while (l < r) {
                int mid = l + (r - l) / 2; // Calculate the middle index
                int target = sorted[mid]; // The middle element is the target for this iteration

                int cur = 0; // Initialize current sum
                long cnt = 0; // Initialize count of elements less than or equal to target

                long[] bit = new long[2 * n + 2]; // Bitmap array for fast counting

                // Initialize the bitmap array
                for (int x = n + 1; x < bit.length; x += x & -x) {
                    bit[x]++; // Increment the count for the current position
                }

                // Process each element in the original array
                for (int i = 0; i < n; i++) {
                    cur += arr[i] <= target ? 1 : -1; // Increment the current sum if the element is less than or equal to target
                    for (int x = cur + n + 1; x < bit.length; x += x & -x) {
                        bit[x]++; // Increment the count for the current position
                    }
                    for (int x = cur + n; x > 0; x -= x & -x) {
                        cnt += bit[x]; // Add the count of elements with sum less than or equal to current sum
                    }
                }

                if (cnt >= total / 2 + 1) { // If the count is greater than half the total sum
                    r = mid; // Narrow the search range to the left
                } else {
                    l = mid + 1; // Narrow the search range to the right
                }
            }

            // Return the middle element as the answer
            return sorted[l];
        }
    }
}

