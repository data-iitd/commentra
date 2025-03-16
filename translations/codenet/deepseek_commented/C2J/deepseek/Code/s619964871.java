public class NumberOfInversions {
    // Function to merge two subarrays and count inversions
    private static long sort(long[] a, int left, int middle, int right) {
        long[] l_arr = new long[middle - left + 1];
        long[] r_arr = new long[right - middle + 1];
        long cnt = 0;
        // Copy elements into temporary arrays
        for (int i = 0; i < middle - left; i++) l_arr[i] = a[i + left];
        for (int i = 0; i < right - middle; i++) r_arr[i] = a[i + middle];
        // Sentinel values to simplify merging
        l_arr[middle - left] = Long.MAX_VALUE;
        r_arr[right - middle] = Long.MAX_VALUE;
        int l = 0, r = 0;
        // Merge the two subarrays while counting inversions
        for (int i = 0; i < right - left; i++) {
            if (l_arr[l] <= r_arr[r]) {
                a[left + i] = l_arr[l++];
            } else {
                a[left + i] = r_arr[r++];
                cnt += middle - left - l;
            }
        }
        return cnt;
    }

    // Recursive function to count inversions in the array
    private static long merge(long[] a, int left, int right) {
        if (left + 1 < right) {
            int middle = (left + right) / 2;
            // Recursively count inversions in the left and right halves
            long x1 = merge(a, left, middle);
            long x2 = merge(a, middle, right);
            // Merge the two halves and count inversions in the merge step
            long x3 = sort(a, left, middle, right);
            return x1 + x2 + x3;
        } else {
            return 0;
        }
    }

    // Main function to read input, count inversions, and print the result
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = scanner.nextLong(); // Read the elements of the array
        System.out.println(merge(a, 0, n)); // Count and print the number of inversions
        scanner.close(); // Close the scanner
    }
}
