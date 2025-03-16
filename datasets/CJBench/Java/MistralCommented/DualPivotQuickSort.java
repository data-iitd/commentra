
import java.util.Scanner; // Importing Scanner class for user input

public class Main {
    // Method to sort an array of comparable elements using dual pivot quicksort algorithm
    public static <T extends Comparable<T>> void sort(T[] array) {
        if (array.length > 1) { // Check if the array has more than one element to sort
            dualPivotQuicksort(array, 0, array.length - 1); // Call dualPivotQuicksort method to sort the array
        }
    }

    // Recursive method to implement dual pivot quicksort algorithm
    private static <T extends Comparable<T>> void dualPivotQuicksort(final T[] array, final int left, final int right) {
        if (left < right) { // Check if the left index is less than the right index
            final int[] pivots = partition(array, left, right); // Call partition method to find the pivots
            dualPivotQuicksort(array, left, pivots[0] - 1); // Recursively sort elements before the first pivot
            dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1); // Recursively sort elements between the pivots
            dualPivotQuicksort(array, pivots[1] + 1, right); // Recursively sort elements after the second pivot
        }
    }

    // Method to partition the array and find the pivots
    private static <T extends Comparable<T>> int[] partition(final T[] array, int left, final int right) {
        if (array[left].compareTo(array[right]) > 0) { // Swap the first and last elements if the first is greater than the last
            swap(array, left, right);
        }
        final T pivot1 = array[left]; // Set the first element as the first pivot
        final T pivot2 = array[right]; // Set the last element as the second pivot
        int pivot1End = left + 1; // Initialize the index for the first pivot's end
        int low = left + 1; // Initialize the index for the first iteration
        int high = right - 1; // Initialize the index for the last iteration

        // Iterate through the array to find the correct positions for the pivots
        while (low <= high) {
            if (array[low].compareTo(pivot1) < 0) { // If the current element is less than the first pivot, swap it with the element at pivot1End and increment pivot1End
                swap(array, low, pivot1End);
                pivot1End++;
            } else if (array[low].compareTo(pivot2) >= 0) { // If the current element is greater than or equal to the second pivot, swap it with the element at high and decrement high
                while (low < high && array[high].compareTo(pivot2) > 0) { // If the current high element is greater than the second pivot, swap it with the element at low and decrement high
                    swap(array, low, high);
                    high--;
                }
                swap(array, low, high); // Swap the current low and high elements
                high--;
                if (array[low].compareTo(pivot1) < 0) { // If the current low element is less than the first pivot, swap it with the element at pivot1End and increment pivot1End
                    swap(array, low, pivot1End);
                    pivot1End++;
                }
            }
            low++; // Increment the low index for the next iteration
        }

        // Swap the pivots with the elements at pivot1End and high indices
        pivot1End--;
        high++;
        swap(array, left, pivot1End);
        swap(array, right, high);

        // Return the indices of the pivots
        return new int[]{pivot1End, high};
    }

    // Method to swap two elements in the array
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i]; // Store the element at index i
        array[i] = array[j]; // Assign the element at index j to index i
        array[j] = temp; // Assign the element at index i to index j
    }

    // Main method to read user input and call sort method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object for user input
        int n = scanner.nextInt(); // Read the number of elements in the array from user input
        Integer[] array = new Integer[n]; // Create an array of Integers with the given size
        for (int i = 0; i < n; i++) { // Iterate through the array to read user input and assign it to the corresponding index
            array[i] = scanner.nextInt();
        }
        sort(array); // Call the sort method to sort the array
        for (int num : array) { // Iterate through the sorted array and print each element
            System.out.print(num + " ");
        }
        scanner.close(); // Close the Scanner object
    }
}

