import java.util.Scanner;
import java.util.Arrays;

public class Main {
    // Threshold for switching to insertion sort
    private static final int INSERTION_SORT_THRESHOLD = 16;

    public static void main(String[] args) {
        // Create a scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements to be sorted
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Perform introspective sort on the array
        introspectiveSort(array, 0, array.length - 1, 2 * (int) (Math.log(array.length) / Math.log(2)));
        
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Introspective sort that switches between quicksort and heapsort based on depth and size
    private static <T extends Comparable<T>> void introspectiveSort(T[] array, final int low, int high, final int depth) {
        // Continue sorting until the size of the subarray is less than the threshold
        while (high - low > INSERTION_SORT_THRESHOLD) {
            // If the depth limit is reached, switch to heapsort
            if (depth == 0) {
                heapSort(array, low, high);
                return;
            }
            // Partition the array and get the pivot index
            final int pivotIndex = partition(array, low, high);
            // Recursively sort the right subarray
            introspectiveSort(array, pivotIndex + 1, high, depth - 1);
            // Update high to sort the left subarray
            high = pivotIndex - 1;
        }
        // Use insertion sort for small subarrays
        insertionSort(array, low, high);
    }

    // Partition the array around a pivot element
    private static <T extends Comparable<T>> int partition(T[] array, final int low, final int high) {
        final T pivot = array[high]; // Choose the last element as the pivot
        int i = low - 1; // Pointer for the smaller element
        // Rearrange the array based on the pivot
        for (int j = low; j < high; j++) {
            if (array[j].compareTo(pivot) <= 0) {
                i++;
                swap(array, i, j); // Swap elements to partition the array
            }
        }
        // Place the pivot in its correct position
        swap(array, i + 1, high);
        return i + 1; // Return the pivot index
    }

    // Insertion sort algorithm for sorting a small subarray
    private static <T extends Comparable<T>> void insertionSort(T[] array, final int low, final int high) {
        // Iterate through the subarray and insert elements in sorted order
        for (int i = low + 1; i <= high; i++) {
            final T key = array[i];
            int j = i - 1;
            // Move elements that are greater than key to one position ahead
            while (j >= low && array[j].compareTo(key) > 0) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key; // Insert the key at its correct position
        }
    }

    // Heapsort algorithm for sorting a subarray
    private static <T extends Comparable<T>> void heapSort(T[] array, final int low, final int high) {
        final int n = high - low + 1; // Calculate the size of the heap
        // Build a max heap
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(array, i, n, low);
        }
        // Extract elements from the heap one by one
        for (int i = high; i > low; i--) {
            swap(array, low, i); // Move the current root to the end
            heapify(array, 0, i - low, low); // Heapify the reduced heap
        }
    }

    // Helper method to maintain the heap property
    private static <T extends Comparable<T>> void heapify(T[] array, final int i, final int n, final int low) {
        final int left = 2 * i + 1; // Left child index
        final int right = 2 * i + 2; // Right child index
        int largest = i; // Initialize largest as root
        // Check if left child is larger than root
        if (left < n && array[low + left].compareTo(array[low + largest]) > 0) {
            largest = left;
        }
        // Check if right child is larger than largest so far
        if (right < n && array[low + right].compareTo(array[low + largest]) > 0) {
            largest = right;
        }
        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(array, low + i, low + largest);
            heapify(array, largest, n, low); // Recursively heapify the affected sub-tree
        }
    }

    // Helper method to swap two elements in the array
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
