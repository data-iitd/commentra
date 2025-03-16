public class NumberOfInversions {
    private static final long unko = 1_000_000_000_000L;  // Define a large constant to act as a sentinel value

    // Function to merge two halves of an array and count inversions
    private static long merge(long[] a, int left, int middle, int right) {
        // Create temporary arrays for left and right halves
        long[] l_arr = new long[middle - left + 1];
        long[] r_arr = new long[right - middle + 1];
        long cnt = 0;  // Initialize inversion count

        // Copy data to temporary arrays
        for (int i = 0; i < middle - left; i++) l_arr[i] = a[i + left];
        for (int i = 0; i < right - middle; i++) r_arr[i] = a[i + middle];

        // Add sentinel values to the end of the temporary arrays
        l_arr[middle - left] = unko;
        r_arr[right - middle] = unko;

        int l = 0, r = 0;  // Initialize pointers for left and right arrays

        // Merge the two halves back into the original array
        for (int i = 0; i < right - left; i++) {
            if (l_arr[l] <= r_arr[r]) {
                a[left + i] = l_arr[l++];  // Take from left array
            } else {
                a[left + i] = r_arr[r++];  // Take from right array
                cnt += middle - left - l;   // Count inversions
            }
        }
        return cnt;  // Return the count of inversions
    }

    // Function to recursively divide the array and count inversions
    private static long mergeSort(long[] a, int left, int right) {
        if (left + 1 < right) {
            int middle = (left + right) / 2;  // Find the middle point
            long x1 = mergeSort(a, left, middle);  // Count inversions in the left half
            long x2 = mergeSort(a, middle, right);  // Count inversions in the right half
            long x3 = merge(a, left, middle, right);  // Count inversions while merging
            return x1 + x2 + x3;  // Return total count of inversions
        } else {
            return 0;  // Base case: no inversions if the segment has one or no elements
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements
        long[] a = new long[n];  // Allocate memory for the array

        // Read the elements into the array
        for (int i = 0; i < n; i++) a[i] = scanner.nextLong();

        // Call the mergeSort function and print the number of inversions
        System.out.println(mergeSort(a, 0, n));

        scanner.close();  // Close the scanner
    }
}
