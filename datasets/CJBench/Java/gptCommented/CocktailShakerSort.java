import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements to be sorted
        int n = scanner.nextInt();
        
        // Initialize an array to hold the input integers
        Integer[] array = new Integer[n];
        
        // Read n integers from the console and store them in the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Create an instance of Main to access the sort method
        Main sorter = new Main();
        
        // Sort the array using the custom sort method
        sorter.sort(array);
        
        // Print the sorted array to the console
        for (int num : array) {
            System.out.print(num + " ");
        }
        
        // Close the scanner to free up resources
        scanner.close();
    }

    // Generic method to sort an array of comparable elements
    public <T extends Comparable<T>> void sort(final T[] array) {
        // If the array is empty, there's nothing to sort
        if (array.length == 0) {
            return;
        }
        
        // Initialize left and right pointers for the sorting process
        int left = 0;
        int right = array.length - 1;
        
        // Continue sorting until the left pointer meets the right pointer
        while (left < right) {
            // Perform a forward pass to bubble up the largest element
            right = performForwardPass(array, left, right);
            // Perform a backward pass to bubble down the smallest element
            left = performBackwardPass(array, left, right);
        }
    }

    // Method to perform a forward pass in the sorting process
    private <T extends Comparable<T>> int performForwardPass(final T[] array, final int left, final int right) {
        // Track the last index where a swap occurred
        int lastSwappedIndex = left;
        
        // Iterate from the left to the right, comparing adjacent elements
        for (int i = left; i < right; i++) {
            // If the current element is greater than the next, swap them
            if (array[i].compareTo(array[i + 1]) > 0) {
                swap(array, i, i + 1);
                lastSwappedIndex = i; // Update the last swapped index
            }
        }
        
        // Return the last index where a swap occurred
        return lastSwappedIndex;
    }

    // Method to perform a backward pass in the sorting process
    private <T extends Comparable<T>> int performBackwardPass(final T[] array, final int left, final int right) {
        // Track the last index where a swap occurred
        int lastSwappedIndex = right;
        
        // Iterate from the right to the left, comparing adjacent elements
        for (int i = right; i > left; i--) {
            // If the current element is less than the previous, swap them
            if (array[i].compareTo(array[i - 1]) < 0) {
                swap(array, i - 1, i);
                lastSwappedIndex = i; // Update the last swapped index
            }
        }
        
        // Return the last index where a swap occurred
        return lastSwappedIndex;
    }

    // Method to swap two elements in the array
    private <T> void swap(final T[] array, final int i, final int j) {
        // Store the element at index i in a temporary variable
        T temp = array[i];
        // Swap the elements at index i and j
        array[i] = array[j];
        array[j] = temp;
    }
}
