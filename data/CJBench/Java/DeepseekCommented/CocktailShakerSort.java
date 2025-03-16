import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements in the array
        int n = scanner.nextInt();
        // Create an array of size n to store the elements
        Integer[] array = new Integer[n];
        // Read n elements into the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        // Create an instance of the Main class to use its sorting method
        Main sorter = new Main();
        // Call the sort method on the array
        sorter.sort(array);
        // Print the sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }
        // Close the scanner to free up resources
        scanner.close();
    }
    // Generic sort method that takes an array of type T which extends Comparable
    public <T extends Comparable<T>> void sort(final T[] array) {
        // If the array is empty, return immediately
        if (array.length == 0) {
            return;
        }
        // Initialize pointers for the forward and backward passes
        int left = 0;
        int right = array.length - 1;
        // Continue sorting until the left pointer meets the right pointer
        while (left < right) {
            // Perform the forward pass and update the right pointer
            right = performForwardPass(array, left, right);
            // Perform the backward pass and update the left pointer
            left = performBackwardPass(array, left, right);
        }
    }
    // Forward pass to bubble the largest element to the right
    private <T extends Comparable<T>> int performForwardPass(final T[] array, final int left, final int right) {
        // Track the last swapped index in the forward pass
        int lastSwappedIndex = left;
        // Iterate through the array from left to right-1
        for (int i = left; i < right; i++) {
            // Swap if the current element is greater than the next element
            if (array[i].compareTo(array[i + 1]) > 0) {
                swap(array, i, i + 1);
                lastSwappedIndex = i;
            }
        }
        // Return the last swapped index for the next pass
        return lastSwappedIndex;
    }
    // Backward pass to bubble the smallest element to the left
    private <T extends Comparable<T>> int performBackwardPass(final T[] array, final int left, final int right) {
        // Track the last swapped index in the backward pass
        int lastSwappedIndex = right;
        // Iterate through the array from right to left+1
        for (int i = right; i > left; i--) {
            // Swap if the current element is less than the previous element
            if (array[i].compareTo(array[i - 1]) < 0) {
                swap(array, i - 1, i);
                lastSwappedIndex = i;
            }
        }
        // Return the last swapped index for the next pass
        return lastSwappedIndex;
    }
    // Generic swap method to swap two elements in the array
    private <T> void swap(final T[] array, final int i, final int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
