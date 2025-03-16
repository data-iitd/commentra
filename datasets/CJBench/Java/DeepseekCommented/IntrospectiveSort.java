import java.util.Scanner;
import java.util.Arrays;
public class Main {
    private static final int INSERTION_SORT_THRESHOLD = 16; // Threshold for switching to insertion sort
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read the array elements
        }
        introspectiveSort(array, 0, array.length - 1, 2 * (int) (Math.log(array.length) / Math.log(2))); // Call introspective sort
        for (int num : array) {
            System.out.print(num + " "); // Print the sorted array
        }
        scanner.close(); // Close the scanner
    }
    private static <T extends Comparable<T>> void introspectiveSort(T[] array, final int low, int high, final int depth) {
        while (high - low > INSERTION_SORT_THRESHOLD) { // Continue sorting if the subarray is large
            if (depth == 0) { // If depth limit is reached, switch to heap sort
                heapSort(array, low, high);
                return;
            }
            final int pivotIndex = partition(array, low, high); // Partition the array
            introspectiveSort(array, pivotIndex + 1, high, depth - 1); // Recursively sort the right subarray
            high = pivotIndex - 1; // Continue sorting the left subarray
        }
        insertionSort(array, low, high); // Perform insertion sort for small subarrays
    }
    private static <T extends Comparable<T>> int partition(T[] array, final int low, final int high) {
        final T pivot = array[high]; // Choose the last element as the pivot
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (array[j].compareTo(pivot) <= 0) { // If the current element is less than or equal to the pivot
                i++;
                swap(array, i, j); // Swap the elements
            }
        }
        swap(array, i + 1, high); // Place the pivot in its correct position
        return i + 1; // Return the pivot index
    }
    private static <T extends Comparable<T>> void insertionSort(T[] array, final int low, final int high) {
        for (int i = low + 1; i <= high; i++) {
            final T key = array[i];
            int j = i - 1;
            while (j >= low && array[j].compareTo(key) > 0) { // Shift elements to the right
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key; // Insert the key in the correct position
        }
    }
    private static <T extends Comparable<T>> void heapSort(T[] array, final int low, final int high) {
        final int n = high - low + 1;
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(array, i, n, low); // Build the max heap
        }
        for (int i = high; i > low; i--) {
            swap(array, low, i); // Extract the maximum element
            heapify(array, 0, i - low, low); // Rebuild the heap
        }
    }
    private static <T extends Comparable<T>> void heapify(T[] array, final int i, final int n, final int low) {
        final int left = 2 * i + 1;
        final int right = 2 * i + 2;
        int largest = i;
        if (left < n && array[low + left].compareTo(array[low + largest]) > 0) { // If left child is larger
            largest = left;
        }
        if (right < n && array[low + right].compareTo(array[low + largest]) > 0) { // If right child is larger
            largest = right;
        }
        if (largest != i) {
            swap(array, low + i, low + largest); // Swap the elements
            heapify(array, largest, n, low); // Recursively heapify the affected sub-tree
        }
    }
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp; // Swap the elements
    }
}
