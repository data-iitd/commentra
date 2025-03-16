import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to count the number of inversions in the array
    public static int countInversions(int[] arr) {
        return mergeSortAndCount(arr, 0, arr.length - 1);
    }

    // Recursive method to perform merge sort and count inversions
    private static int mergeSortAndCount(int[] arr, int left, int right) {
        // Base case: if the left index is greater than or equal to the right index
        if (left >= right) {
            return 0; // No inversions
        }

        // Calculate the middle index
        int mid = left + (right - left) / 2;
        int inversions = 0;

        // Recursively count inversions in the left half
        inversions += mergeSortAndCount(arr, left, mid);
        // Recursively count inversions in the right half
        inversions += mergeSortAndCount(arr, mid + 1, right);
        // Count inversions while merging the two halves
        inversions += mergeAndCount(arr, left, mid, right);

        return inversions; // Return total inversions
    }

    // Method to merge two halves and count inversions
    private static int mergeAndCount(int[] arr, int left, int mid, int right) {
        // Create temporary arrays for left and right halves
        int[] leftArr = new int[mid - left + 1];
        int[] rightArr = new int[right - mid];

        // Copy data to temporary arrays
        System.arraycopy(arr, left, leftArr, 0, mid - left + 1);
        System.arraycopy(arr, mid + 1, rightArr, 0, right - mid);

        // Initialize pointers for left, right, and merged array
        int i = 0; // Pointer for leftArr
        int j = 0; // Pointer for rightArr
        int k = left; // Pointer for the main array
        int inversions = 0; // Count of inversions

        // Merge the two halves while counting inversions
        while (i < leftArr.length && j < rightArr.length) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++]; // No inversion, copy element from leftArr
            } else {
                arr[k++] = rightArr[j++]; // Inversion found, copy element from rightArr
                // Count inversions: all remaining elements in leftArr are greater
                inversions += mid + 1 - left - i;
            }
        }

        // Copy remaining elements of leftArr, if any
        while (i < leftArr.length) {
            arr[k++] = leftArr[i++];
        }

        // Copy remaining elements of rightArr, if any
        while (j < rightArr.length) {
            arr[k++] = rightArr[j++];
        }

        return inversions; // Return the count of inversions
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements in the array
        int n = scanner.nextInt();
        int[] arr = new int[n];

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Count inversions in the array and store the result
        int result = countInversions(arr);
        // Output the number of inversions
        System.out.println("Number of inversions: " + result);
        // Close the scanner to free resources
        scanner.close();
    }
}
