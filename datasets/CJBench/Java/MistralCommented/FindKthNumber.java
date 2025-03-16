
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    private static final Random RANDOM = new Random();

    // Method to find the kth largest element in an array
    public static int findKthMax(int[] array, int k) {
        if (k <= 0 || k > array.length) {
            throw new IllegalArgumentException("k must be between 1 and the size of the array");
            // Check if k is valid, k must be positive and less than the size of the array
        }
        return quickSelect(array, 0, array.length - 1, array.length - k);
        // Use quickSelect algorithm to find the kth largest element
    }

    private static int quickSelect(int[] array, int left, int right, int kSmallest) {
        if (left == right) {
            return array[left];
            // Base case: when the array has only one element
        }
        int pivotIndex = left + RANDOM.nextInt(right - left + 1);
        pivotIndex = partition(array, left, right, pivotIndex);
        if (kSmallest == pivotIndex) {
            return array[kSmallest];
            // If pivot is the kth largest element, return it
        } else if (kSmallest < pivotIndex) {
            return quickSelect(array, left, pivotIndex - 1, kSmallest);
            // Recursively search for the kth largest element in the left subarray
        } else {
            return quickSelect(array, pivotIndex + 1, right, kSmallest);
            // Recursively search for the kth largest element in the right subarray
        }
    }

    private static int partition(int[] array, int left, int right, int pivotIndex) {
        int pivotValue = array[pivotIndex];
        swap(array, pivotIndex, right);
        int storeIndex = left;
        for (int i = left; i < right; i++) {
            if (array[i] < pivotValue) {
                swap(array, storeIndex, i);
                storeIndex++;
                // Swap elements and increment storeIndex when array[i] is smaller than pivotValue
            }
        }
        swap(array, storeIndex, right);
        return storeIndex;
        // Return the index of the pivot after partitioning the array
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        // Swap elements at index i and j
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            // Initialize scanner to read input from the console
            int n = scanner.nextInt();
            if (n <= 0) {
                System.out.println("Array size must be positive.");
                // Check if the array size is valid, it must be positive
                return;
            }
            int[] array = new int[n];
            // Create an array of size n
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
                // Read integers from the console and store them in the array
            }
            int k = scanner.nextInt();
            if (k <= 0 || k > n) {
                System.out.println("Error: k must be between 1 and the size of the array.");
                // Check if k is valid, it must be between 1 and the size of the array
                return;
            }
            int result = findKthMax(array, k);
            System.out.println("The " + k + "-th largest element is: " + result);
            // Print the kth largest element
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
            // Handle exceptions and print an error message
        } finally {
            scanner.close();
            // Close the scanner
        }
    }
}