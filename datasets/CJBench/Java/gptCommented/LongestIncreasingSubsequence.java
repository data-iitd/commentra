import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to find the upper bound index for a key in a sorted array
    private static int upperBound(int[] ar, int l, int r, int key) {
        // Perform binary search to find the upper bound
        while (l < r - 1) {
            int m = (l + r) >>> 1; // Calculate mid-point
            if (ar[m] >= key) {
                r = m; // Move right if mid is greater than or equal to key
            } else {
                l = m; // Move left otherwise
            }
        }
        return r; // Return the upper bound index
    }

    // Method to compute the length of the longest increasing subsequence (LIS)
    public static int lis(int[] array) {
        int len = array.length; // Get the length of the input array
        if (len == 0) {
            return 0; // Return 0 if the array is empty
        }
        
        int[] tail = new int[len]; // Array to store the smallest tail of all increasing subsequences
        int length = 1; // Initialize length of LIS
        tail[0] = array[0]; // Start with the first element

        // Iterate through the array to build the LIS
        for (int i = 1; i < len; i++) {
            if (array[i] < tail[0]) {
                tail[0] = array[i]; // Update the smallest element
            } 
            else if (array[i] > tail[length - 1]) {
                tail[length++] = array[i]; // Extend the LIS
            } 
            else {
                // Find the position to replace in the tail array
                tail[upperBound(tail, -1, length - 1, array[i])] = array[i];
            }
        }
        return length; // Return the length of the LIS
    }

    // Method to find the length of the longest increasing subsequence using a different approach
    public static int findLISLen(int[] a) {
        final int size = a.length; // Get the size of the input array
        if (size == 0) {
            return 0; // Return 0 if the array is empty
        }
        
        int[] arr = new int[size]; // Array to store the smallest tail of increasing subsequences
        arr[0] = a[0]; // Initialize the first element
        int lis = 1; // Initialize length of LIS

        // Iterate through the array to compute LIS length
        for (int i = 1; i < size; i++) {
            // Find the position to insert the current element
            int index = binarySearchBetween(arr, lis - 1, a[i]);
            arr[index] = a[i]; // Update the tail array
            if (index == lis) {
                lis++; // Increase the length of LIS if a new longer subsequence is found
            }
        }
        return lis; // Return the length of the LIS
    }

    // Method to perform binary search to find the correct position for the key
    private static int binarySearchBetween(int[] t, int end, int key) {
        int left = 0; // Initialize left pointer
        int right = end; // Initialize right pointer
        
        // Check if the key is less than the smallest element
        if (key < t[0]) {
            return 0; // Return 0 if key is the smallest
        }
        // Check if the key is greater than the largest element
        if (key > t[end]) {
            return end + 1; // Return end + 1 if key is the largest
        }
        
        // Perform binary search to find the correct position
        while (left < right - 1) {
            final int middle = (left + right) >>> 1; // Calculate mid-point
            if (t[middle] < key) {
                left = middle; // Move left pointer if middle is less than key
            } else {
                right = middle; // Move right pointer otherwise
            }
        }
        return right; // Return the position to insert the key
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of elements
        int[] array = new int[n]; // Initialize the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read each element into the array
        }
        int method = scanner.nextInt(); // Read the method choice (1 or 2)
        int result; // Variable to store the result
        
        // Determine which method to use based on user input
        if (method == 1) {
            result = lis(array); // Call the first method
        } else {
            result = findLISLen(array); // Call the second method
        }
        
        // Output the result
        System.out.println("The length of the longest increasing subsequence is: " + result);
    }
}
