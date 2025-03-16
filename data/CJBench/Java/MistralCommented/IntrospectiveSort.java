
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    private static final int INSERTION_SORT_THRESHOLD = 16;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the console

        int n = scanner.nextInt(); // Read the number of elements in the array from the console

        Integer[] array = new Integer[n]; // Create an Integer array of size n

        for (int i = 0; i < n; i++) { // Iterate through the array to read the elements from the console
            array[i] = scanner.nextInt();
        }

        introspectiveSort(array, 0, array.length - 1, 2 * (int) (Math.log(array.length) / Math.log(2))); // Call the introspectiveSort method to sort the array

        for (int num : array) { // Iterate through the sorted array and print each element
            System.out.print(num + " ");
        }

        scanner.close(); // Close the Scanner object to free up resources
    }

    private static <T extends Comparable<T>> void introspectiveSort(T[] array, final int low, int high, final int depth) {
        // Base case: if the depth is 0, use heap sort instead of introspective sort
        if (depth == 0) {
            heapSort(array, low, high);
            return;
        }

        // Find the pivot index using partition method and recursively sort the right side of the pivot
        final int pivotIndex = partition(array, low, high);
        introspectiveSort(array, pivotIndex + 1, high, depth - 1);
        high = pivotIndex - 1; // Update the high index to the last index of the left side of the pivot
    }

    private static <T extends Comparable<T>> int partition(T[] array, final int low, final int high) {
        // Choose the last element as the pivot
        final T pivot = array[high];

        int i = low - 1; // Initialize i to the index of the last element in the left side of the pivot

        for (int j = low; j < high; j++) { // Iterate through the array to find the position of the pivot element
            if (array[j].compareTo(pivot) <= 0) { // If the current element is smaller than or equal to the pivot
                i++; // Increment i to move to the next position in the left side of the pivot
                swap(array, i, j); // Swap the current element with the element at position i
            }
        }

        swap(array, i + 1, high); // Swap the pivot element with the element at position i+1 (the correct position for the pivot)

        return i + 1; // Return the index of the pivot
    }

    private static <T extends Comparable<T>> void insertionSort(T[] array, final int low, final int high) {
        // Iterate through the array to sort it using insertion sort algorithm
        for (int i = low + 1; i <= high; i++) {
            final T key = array[i];
            int j = i - 1;
            while (j >= low && array[j].compareTo(key) > 0) { // Find the position for the key element
                array[j + 1] = array[j]; // Swap the current element with the next element
                j--;
            }
            array[j + 1] = key; // Insert the key element at its correct position
        }
    }

    private static <T extends Comparable<T>> void heapSort(T[] array, final int low, final int high) {
        // Base case: if the size of the sub-array is 1 or less, the array is already sorted
        if (high - low + 1 <= 0) {
            return;
        }

        // Heapify the root node of the sub-array
        heapify(array, 0, high - low + 1, low);

        // Swap the root node with the last node, and recursively heapify the sub-array of size n-1
        swap(array, low, high);
        heapify(array, 0, high - low, low);
    }

    private static <T extends Comparable<T>> void heapify(T[] array, final int i, final int n, final int low) {
        // Find the index of the left and right child nodes of the current node
        final int left = 2 * i + 1;
        final int right = 2 * i + 2;

        // Find the index of the largest node among the current node, its left child, and its right child
        int largest = i;
        if (left < n && array[low + left].compareTo(array[low + largest]) > 0) {
            largest = left;
        }
        if (right < n && array[low + right].compareTo(array[low + largest]) > 0) {
            largest = right;
        }

        // If the current node is not at its correct position, swap it with its correct position and recursively heapify the sub-tree rooted at the new position
        if (largest != i) {
            swap(array, low + i, low + largest);
            heapify(array, largest, n, low);
        }
    }

    private static <T> void swap(T[] array, int i, int j) {
        // Swap the elements at positions i and j in the array
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

