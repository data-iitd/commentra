import java.util.Scanner;

public class InversionCount {
    static final int MAXN = 200010; // Define the maximum size for the array
    static int[] a = new int[MAXN]; // Declare the array
    static int[] L = new int[MAXN / 2]; // Temporary array for left half
    static int[] R = new int[MAXN / 2]; // Temporary array for right half
    static long cnt; // Initialize inversion count

    // Function to merge two halves of the array and count inversions
    static long merge(int left, int mid, int right) {
        int n1 = mid - left; // Size of the left subarray
        int n2 = right - mid; // Size of the right subarray

        // Copy data to temporary arrays L and R
        for (int i = 0; i < n1; ++i) L[i] = a[left + i];
        for (int i = 0; i < n2; ++i) R[i] = a[mid + i];

        // Sentinel values to avoid out-of-bounds access
        L[n1] = Integer.MAX_VALUE; 
        R[n2] = Integer.MAX_VALUE; 

        int i = 0, j = 0; // Initialize pointers for L and R
        // Merge the two subarrays back into the original array
        for (int k = left; k < right; ++k) {
            if (L[i] <= R[j]) 
                a[k] = L[i++]; // If L[i] is smaller, take it
            else {
                a[k] = R[j++]; // If R[j] is smaller, take it
                cnt += n1 - i; // Count inversions: all remaining elements in L are greater than R[j]
            }
        }
        return cnt; // Return the count of inversions
    }

    // Function to perform mergesort and count inversions
    static long mergesort(int left, int right) {
        long v1 = 0, v2 = 0, v3 = 0;
        // Base case: if the subarray has more than one element
        if (left + 1 < right) {
            int mid = (left + right) / 2; // Find the mid point
            v1 = mergesort(left, mid); // Sort the left half and count inversions
            v2 = mergesort(mid, right); // Sort the right half and count inversions
            v3 = merge(left, mid, right); // Merge both halves and count cross inversions
            return v1 + v2 + v3; // Return total inversion count
        }
        return 0; // Return 0 for a single element (no inversions)
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        for (int i = 0; i < n; ++i) 
            a[i] = scanner.nextInt(); // Read the elements into the array

        long ans = mergesort(0, n); // Perform mergesort and get the inversion count
        System.out.println(ans); // Output the result
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
