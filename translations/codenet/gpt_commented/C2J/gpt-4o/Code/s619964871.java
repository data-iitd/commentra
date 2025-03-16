/*
 * FileName:     TheNumberOfInversionsFix.java
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

import java.util.Scanner;

public class TheNumberOfInversionsFix {
    static final long UNKO = (long) 1e12;  // Define a large constant to act as a sentinel value

    // Function to merge two halves of an array and count inversions
    static long sort(long[] a, int left, int middle, int right) {
        // Create temporary arrays for left and right halves
        long[] lArr = new long[middle - left + 1];
        long[] rArr = new long[right - middle + 1];
        long cnt = 0;  // Initialize inversion count

        // Copy data to temporary arrays
        for (int i = 0; i < middle - left; i++) lArr[i] = a[i + left];
        for (int i = 0; i < right - middle; i++) rArr[i] = a[i + middle];

        // Add sentinel values to the end of the temporary arrays
        lArr[middle - left] = UNKO;
        rArr[right - middle] = UNKO;

        int l = 0, r = 0;  // Initialize pointers for left and right arrays

        // Merge the two halves back into the original array
        for (int i = 0; i < right - left; i++) {
            if (lArr[l] <= rArr[r]) {
                a[left + i] = lArr[l++];  // Take from left array
            } else {
                a[left + i] = rArr[r++];  // Take from right array
                cnt += middle - left - l;   // Count inversions
            }
        }
        return cnt;  // Return the count of inversions
    }

    // Function to recursively divide the array and count inversions
    static long merge(long[] a, int left, int right) {
        if (left + 1 < right) {
            int middle = (left + right) / 2;  // Find the middle point
            long x1 = merge(a, left, middle);  // Count inversions in the left half
            long x2 = merge(a, middle, right);  // Count inversions in the right half
            long x3 = sort(a, left, middle, right);  // Count inversions while merging
            return x1 + x2 + x3;  // Return total count of inversions
        } else {
            return 0;  // Base case: no inversions if the segment has one or no elements
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements
        long[] a = new long[n];  // Allocate memory for the array

        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }

        // Call the merge function and print the number of inversions
        System.out.println(merge(a, 0, n));

        scanner.close();  // Close the scanner
    }
}

/* <END-OF-CODE> */
