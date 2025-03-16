import java.util.Scanner; // Importing Scanner for input

public final class Main { // Defining the final Main class
    private Main() {
    } // Private constructor to prevent instantiation

    // Helper method to find the smallest index with a value greater than or equal to key
    private static int upperBound(int[] ar, int l, int r, int key) {
        while (l < r - 1) {
            int m = (l + r) >>> 1;
            if (ar[m] >= key) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }

    // Method to calculate the length of the longest increasing subsequence
    public static int lis(int[] array) {
        int len = array.length;
        if (len == 0) {
            return 0;
        }
        int[] tail = new int[len]; // Array to store the last element of each increasing subsequence
        int length = 1; // Length of the LIS
        tail[0] = array[0]; // Initialize the first element
        for (int i = 1; i < len; i++) {
            if (array[i] < tail[0]) {
                tail[0] = array[i]; // Replace the smallest element
            } 
            else if (array[i] > tail[length - 1]) {
                tail[length++] = array[i]; // Append to the LIS
            } 
            else {
                tail[upperBound(tail, -1, length - 1, array[i])] = array[i]; // Replace the appropriate element
            }
        }
        return length;
    }

    // Alternative method to calculate the length of the longest increasing subsequence
    public static int findLISLen(int[] a) {
        final int size = a.length;
        if (size == 0) {
            return 0;
        }
        int[] arr = new int[size]; // Array to store the LIS
        arr[0] = a[0];
        int lis = 1; // Length of the LIS
        for (int i = 1; i < size; i++) {
            int index = binarySearchBetween(arr, lis - 1, a[i]);
            arr[index] = a[i];
            if (index == lis) {
                lis++;
            }
        }
        return lis;
    }

    // Helper method to find the position to replace in the array for the binary search method
    private static int binarySearchBetween(int[] t, int end, int key) {
        int left = 0;
        int right = end;
        if (key < t[0]) {
            return 0;
        }
        if (key > t[end]) {
            return end + 1;
        }
        while (left < right - 1) {
            final int middle = (left + right) >>> 1;
            if (t[middle] < key) {
                left = middle;
            } else {
                right = middle;
            }
        }
        return right;
    }

    // Main method to read input, determine the method, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int[] array = new int[n]; // Create an array to store the elements
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read the elements
        }
        int method = scanner.nextInt(); // Read the method choice
        int result;
        if (method == 1) {
            result = lis(array); // Calculate LIS using the first method
        } else {
            result = findLISLen(array); // Calculate LIS using the second method
        }
        System.out.println("The length of the longest increasing subsequence is: " + result); // Print the result
    }
}
