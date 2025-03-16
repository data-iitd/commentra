import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Main method to count the number of inversions in an array
    public static int countInversions(int[] arr) {
        return mergeSortAndCount(arr, 0, arr.length - 1);
    }

    // Recursive method to sort the array and count inversions
    private static int mergeSortAndCount(int[] arr, int left, int right) {
        if (left >= right) {
            return 0; // Base case: no inversions in a single element array
        }
        int mid = left + (right - left) / 2;
        int inversions = 0;
        inversions += mergeSortAndCount(arr, left, mid); // Count inversions in the left half
        inversions += mergeSortAndCount(arr, mid + 1, right); // Count inversions in the right half
        inversions += mergeAndCount(arr, left, mid, right); // Count inversions during merge
        return inversions;
    }

    // Method to merge two halves and count inversions during merge
    private static int mergeAndCount(int[] arr, int left, int mid, int right) {
        int[] leftArr = new int[mid - left + 1];
        int[] rightArr = new int[right - mid];
        System.arraycopy(arr, left, leftArr, 0, mid - left + 1); // Copy left half to leftArr
        System.arraycopy(arr, mid + 1, rightArr, 0, right - mid); // Copy right half to rightArr
        int i = 0;
        int j = 0;
        int k = left;
        int inversions = 0;
        while (i < leftArr.length && j < rightArr.length) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++]; // No inversion, copy from leftArr
            } else {
                arr[k++] = rightArr[j++]; // Inversion found, copy from rightArr
                inversions += mid + 1 - left - i; // Count inversions
            }
        }
        while (i < leftArr.length) {
            arr[k++] = leftArr[i++]; // Copy remaining elements from leftArr
        }
        while (j < rightArr.length) {
            arr[k++] = rightArr[j++]; // Copy remaining elements from rightArr
        }
        return inversions;
    }

    // Main method to read input, compute inversions, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt(); // Read the array elements
        }
        int result = countInversions(arr); // Compute the number of inversions
        System.out.println("Number of inversions: " + result); // Print the result
        scanner.close(); // Close the scanner to free up resources
    }
}
