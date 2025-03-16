
import java.util.Scanner;

// Main class with a private constructor to prevent instantiation from outside
public final class Main {
    private Main() {
    }

    // Method to count the number of inversions in an array using merge sort algorithm
    public static int countInversions(int[] arr) {
        return mergeSortAndCount(arr, 0, arr.length - 1);
    }

    // Recursive helper method for merge sort and counting inversions
    private static int mergeSortAndCount(int[] arr, int left, int right) {
        if (left >= right) { // Base case: when the subarray has only one element or is empty
            return 0;
        }

        int mid = left + (right - left) / 2; // Calculate the middle index of the subarray

        // Recursively merge sort and count inversions in left and right halves
        int inversions = 0;
        inversions += mergeSortAndCount(arr, left, mid);
        inversions += mergeSortAndCount(arr, mid + 1, right);

        // Merge the sorted halves and count inversions
        inversions += mergeAndCount(arr, left, mid, right);

        return inversions;
    }

    // Merge and count inversions in two sorted halves
    private static int mergeAndCount(int[] arr, int left, int mid, int right) {
        int[] leftArr = new int[mid - left + 1]; // Create temporary arrays for merging
        int[] rightArr = new int[right - mid];

        // Copy elements from the original array to temporary arrays
        System.arraycopy(arr, left, leftArr, 0, mid - left + 1);
        System.arraycopy(arr, mid + 1, rightArr, 0, right - mid);

        int i = 0; // Index for left array
        int j = 0; // Index for right array
        int k = left; // Index for the merged array
        int inversions = 0; // Initialize inversions counter

        // Merge the sorted halves and count inversions
        while (i < leftArr.length && j < rightArr.length) {
            if (leftArr[i] <= rightArr[j]) { // If current elements are in non-decreasing order
                arr[k++] = leftArr[i++]; // Copy the smaller element to the merged array
            } else { // If current elements are in non-increasing order
                arr[k++] = rightArr[j++]; // Copy the larger element to the merged array
                inversions += mid + 1 - left - i; // Count the number of inversions caused by this swap
            }
        }

        // Copy remaining elements from left and right arrays to the merged array
        while (i < leftArr.length) {
            arr[k++] = leftArr[i++];
        }
        while (j < rightArr.length) {
            arr[k++] = rightArr[j++];
        }

        return inversions;
    }

    // Main method to read input and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

        int n = scanner.nextInt(); // Read the number of elements in the array
        int[] arr = new int[n]; // Create an integer array of size n

        for (int i = 0; i < n; i++) { // Read elements of the array and store them in the array
            arr[i] = scanner.nextInt();
        }

        int result = countInversions(arr); // Call the countInversions method to find the number of inversions
        System.out.println("Number of inversions: " + result); // Print the result

        scanner.close(); // Close the Scanner object
    }
}