/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i = 0; i < n; i++) a[i] = sc.nextLong();
        System.out.println(merge(a, 0, n));
    }

    // Function to merge two halves of an array and count inversions
    public static long merge(long[] a, int left, int right) {
        if(left + 1 < right) {
            int middle = (left + right) / 2;  // Find the middle point
            long x1 = merge(a, left, middle);  // Count inversions in the left half
            long x2 = merge(a, middle, right);  // Count inversions in the right half
            long x3 = sort(a, left, middle, right);  // Count inversions while merging
            return x1 + x2 + x3;  // Return total count of inversions
        } else {
            return 0;  // Base case: no inversions if the segment has one or no elements
        }
    }

    // Function to merge two halves of an array and count inversions
    public static long sort(long[] a, int left, int middle, int right) {
        // Create temporary arrays for left and right halves
        long[] l_arr = new long[middle-left+1];
        long[] r_arr = new long[right-middle+1];
        long cnt = 0;  // Initialize inversion count

        // Copy data to temporary arrays
        for(int i = 0; i < middle - left; i++) l_arr[i] = a[i + left];
        for(int i = 0; i < right - middle; i++) r_arr[i] = a[i + middle];

        // Add sentinel values to the end of the temporary arrays
        l_arr[middle-left] = Long.MAX_VALUE;
        r_arr[right-middle] = Long.MAX_VALUE;

        int l = 0, r = 0;  // Initialize pointers for left and right arrays

        // Merge the two halves back into the original array
        for(int i = 0; i < right - left; i++) {
            if(l_arr[l] <= r_arr[r]) {
                a[left + i] = l_arr[l++];  // Take from left array
            } else {
                a[left + i] = r_arr[r++];  // Take from right array
                cnt += middle - left - l;   // Count inversions
            }
        }
        return cnt;  // Return the count of inversions
    }
}

