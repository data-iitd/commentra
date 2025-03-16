import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Random instance for selecting pivot in quick select algorithm
    private static final Random RANDOM = new Random();

    // Method to find the k-th largest element in the array
    public static int findKthMax(int[] array, int k) {
        // Validate the value of k
        if (k <= 0 || k > array.length) {
            throw new IllegalArgumentException("k must be between 1 and the size of the array");
        }
        // Call quickSelect to find the k-th largest element
        return quickSelect(array, 0, array.length - 1, array.length - k);
    }

    // QuickSelect algorithm to find the k-th smallest element
    private static int quickSelect(int[] array, int left, int right, int kSmallest) {
        // Base case: if the list contains only one element
        if (left == right) {
            return array[left];
        }
        // Randomly select a pivot index
        int pivotIndex = left + RANDOM.nextInt(right - left + 1);
        // Partition the array around the pivot
        pivotIndex = partition(array, left, right, pivotIndex);
        
        // Check if the pivot is the k-th smallest element
        if (kSmallest == pivotIndex) {
            return array[kSmallest];
        } 
        // If kSmallest is less than pivotIndex, search in the left subarray
        else if (kSmallest < pivotIndex) {
            return quickSelect(array, left, pivotIndex - 1, kSmallest);
        } 
        // If kSmallest is greater than pivotIndex, search in the right subarray
        else {
            return quickSelect(array, pivotIndex + 1, right, kSmallest);
        }
    }

    // Partition the array around a pivot
    private static int partition(int[] array, int left, int right, int pivotIndex) {
        // Store the pivot value
        int pivotValue = array[pivotIndex];
        // Move the pivot to the end of the array
        swap(array, pivotIndex, right);
        int storeIndex = left;
        
        // Rearrange the array elements based on the pivot value
        for (int i = left; i < right; i++) {
            if (array[i] < pivotValue) {
                swap(array, storeIndex, i);
                storeIndex++;
            }
        }
        // Move the pivot to its final place
        swap(array, storeIndex, right);
        return storeIndex; // Return the final index of the pivot
    }

    // Helper method to swap two elements in the array
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            // Read the size of the array
            int n = scanner.nextInt();
            // Validate the size of the array
            if (n <= 0) {
                System.out.println("Array size must be positive.");
                return;
            }
            // Initialize the array and read its elements
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
            }
            // Read the value of k
            int k = scanner.nextInt();
            // Validate the value of k
            if (k <= 0 || k > n) {
                System.out.println("Error: k must be between 1 and the size of the array.");
                return;
            }
            // Find the k-th largest element and print the result
            int result = findKthMax(array, k);
            System.out.println("The " + k + "-th largest element is: " + result);
        } catch (Exception e) {
            // Handle any exceptions that occur during input or processing
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            // Close the scanner resource
            scanner.close();
        }
    }
}
