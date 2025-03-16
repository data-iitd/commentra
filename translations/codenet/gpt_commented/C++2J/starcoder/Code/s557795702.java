import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; ++i) a[i] = in.nextInt();
        System.out.println(mergesort(a, 0, n));
    }

    // Function to merge two halves of the array and count inversions
    static int merge(int[] a, int left, int mid, int right) {
        int i, j, k;
        int cnt = 0; // Initialize inversion count
        int n1 = mid - left; // Size of the left subarray
        int n2 = right - mid; // Size of the right subarray

        // Copy data to temporary arrays L and R
        int[] L = new int[n1 + 1];
        int[] R = new int[n2 + 1];
        for(i = 0; i < n1; ++i) L[i] = a[left + i];
        for(i = 0; i < n2; ++i) R[i] = a[mid + i];

        // Sentinel values to avoid out-of-bounds access
        L[n1] = R[n2] = Integer.MAX_VALUE; 

        i = j = 0; // Initialize pointers for L and R
        // Merge the two subarrays back into the original array
        for(k = left; k < right; ++k) {
            if(L[i] <= R[j]) 
                a[k] = L[i++]; // If L[i] is smaller, take it
            else {
                a[k] = R[j++]; // If R[j] is smaller, take it
                cnt += n1 - i; // Count inversions: all remaining elements in L are greater than R[j]
            }
        }
        return cnt; // Return the count of inversions
    }

    // Function to perform mergesort and count inversions
    static int mergesort(int[] a, int left, int right) {
        int mid;
        int v1, v2, v3;
        // Base case: if the subarray has more than one element
        if(left + 1 < right) {
            mid = (left + right) / 2; // Find the mid point
            v1 = mergesort(a, left, mid); // Sort the left half and count inversions
            v2 = mergesort(a, mid, right); // Sort the right half and count inversions
            v3 = merge(a, left, mid, right); // Merge both halves and count cross inversions
            return v1 + v2 + v3; // Return total inversion count
        }
        return 0; // Return 0 for a single element (no inversions)
    }
}

