import java.util.Scanner;

public class Main {
    // Generic method to sort an array of comparable elements
    public static <T extends Comparable<T>> void sort(T[] array) {
        // Check if the array has more than one element to sort
        if (array.length > 1) {
            // Call the dual pivot quicksort method to sort the array
            dualPivotQuicksort(array, 0, array.length - 1);
        }
    }

    // Recursive method to perform dual pivot quicksort
    private static <T extends Comparable<T>> void dualPivotQuicksort(final T[] array, final int left, final int right) {
        // Base case: if the left index is less than the right index
        if (left < right) {
            // Partition the array and get the pivot indices
            final int[] pivots = partition(array, left, right);
            // Recursively sort the subarrays around the pivots
            dualPivotQuicksort(array, left, pivots[0] - 1);
            dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1);
            dualPivotQuicksort(array, pivots[1] + 1, right);
        }
    }

    // Method to partition the array around two pivots
    private static <T extends Comparable<T>> int[] partition(final T[] array, int left, int right) {
        // Ensure the left pivot is less than the right pivot
        if (array[left].compareTo(array[right]) > 0) {
            swap(array, left, right);
        }
        // Set the two pivots
        final T pivot1 = array[left];
        final T pivot2 = array[right];
        int pivot1End = left + 1; // End index for the first pivot
        int low = left + 1; // Current index for scanning
        int high = right - 1; // High index for scanning

        // Partitioning process
        while (low <= high) {
            // If the current element is less than the first pivot
            if (array[low].compareTo(pivot1) < 0) {
                swap(array, low, pivot1End); // Swap to the left of pivot1
                pivot1End++;
            } 
            // If the current element is greater than or equal to the second pivot
            else if (array[low].compareTo(pivot2) >= 0) {
                // Move high pointer to find an element less than pivot2
                while (low < high && array[high].compareTo(pivot2) > 0) {
                    high--;
                }
                swap(array, low, high); // Swap the current element with the high pointer
                high--; // Move high pointer left
                // Check if the swapped element is less than pivot1
                if (array[low].compareTo(pivot1) < 0) {
                    swap(array, low, pivot1End); // Swap to the left of pivot1
                    pivot1End++;
                }
            }
            low++; // Move to the next element
        }

        // Final adjustments to place the pivots in their correct positions
        pivot1End--;
        high++;
        swap(array, left, pivot1End); // Place pivot1 in its final position
        swap(array, right, high); // Place pivot2 in its final position

        // Return the indices of the two pivots
        return new int[]{pivot1End, high};
    }

    // Method to swap two elements in the array
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i]; // Store the element at index i
        array[i] = array[j]; // Move the element at index j to index i
        array[j] = temp; // Place the stored element at index j
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of elements
        Integer[] array = new Integer[n]; // Initialize the array
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        // Sort the array using the sort method
        sort(array);
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close(); // Close the scanner
    }
}
