public class NumberOfInversions {
    // Function to sort a subarray using merge-sort algorithm
    public static long sort(long[] a, int left, int middle, int right) {
        long[] l_arr = new long[middle - left + 1]; // Allocate memory for left subarray
        long[] r_arr = new long[right - middle + 1]; // Allocate memory for right subarray
        long cnt = 0; // Initialize inversion count to zero

        // Copy elements from the left subarray to a temporary array
        for (int i = 0; i < middle - left; i++) {
            l_arr[i] = a[i + left]; // Copy elements from the original array to the temporary array
        }

        // Copy elements from the right subarray to a temporary array
        for (int i = 0; i < right - middle; i++) {
            r_arr[i] = a[i + middle]; // Copy elements from the original array to the temporary array
        }

        // Set the last element of left subarray and right subarray to a large value
        l_arr[middle - left] = Long.MAX_VALUE;
        r_arr[right - middle] = Long.MAX_VALUE;

        int l = 0, r = 0; // Initialize pointers for left and right subarrays

        // Merge the sorted subarrays back to the original array and count inversions
        for (int i = 0; i < right - left; i++) {
            if (l_arr[l] <= r_arr[r]) { // If current element from left subarray is smaller than or equal to current element from right subarray
                a[left + i] = l_arr[l++]; // Copy the smaller element to the original array
            } else { // If current element from left subarray is greater than the current element from right subarray
                a[left + i] = r_arr[r++]; // Copy the smaller element to the original array
                cnt += middle - left - l; // Increment inversion count
            }
        }

        return cnt; // Return the number of inversions
    }

    // Recursive function to merge-sort the given array
    public static long merge(long[] a, int left, int right) {
        if (left + 1 < right) { // If the subarray has more than one element
            int middle = (left + right) / 2; // Calculate the middle index of the subarray
            long x1 = merge(a, left, middle); // Merge-sort the left subarray
            long x2 = merge(a, middle, right); // Merge-sort the right subarray
            long x3 = sort(a, left, middle, right); // Merge the sorted subarrays and count inversions
            return x1 + x2 + x3; // Return the total number of inversions
        } else { // If the subarray has only one element
            return 0; // No inversions are present
        }
    }

    // Main function to read input and call merge-sort function
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements in the array
        long[] a = new long[n]; // Allocate memory for the array

        for (int i = 0; i < n; i++) { // Read the elements of the array from the standard input
            a[i] = scanner.nextLong();
        }

        System.out.println(merge(a, 0, n)); // Call the merge-sort function and print the result

        scanner.close(); // Close the scanner
    }
}
