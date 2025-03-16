
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the user input
        int n = scanner.nextInt();

        // Allocate memory for an array of Integer type with the given size
        Integer[] array = new Integer[n];

        // Read each element of the array from the user input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Create an instance of the Main class and call the sort method to sort the array
        Main sorter = new Main();
        sorter.sort(array);

        // Print each element of the sorted array to the console
        for (int num : array) {
            System.out.print(num + " ");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }

    // A method to sort an array of Comparable type using the bubble sort algorithm
    public <T extends Comparable<T>> void sort(final T[] array) {
        // Base case: if the array is empty, return without doing anything
        if (array.length == 0) {
            return;
        }

        // Initialize two pointers, one at the beginning and another at the end of the array
        int left = 0;
        int right = array.length - 1;

        // Repeat the following steps until the array is sorted
        while (left < right) {
            // Perform a forward pass to swap elements if they are in the wrong order
            right = performForwardPass(array, left, right);

            // Perform a backward pass to swap elements if they are in the wrong order
            left = performBackwardPass(array, left, right);
        }
    }

    // A helper method to perform a forward pass in the bubble sort algorithm
    private <T extends Comparable<T>> int performForwardPass(final T[] array, final int left, final int right) {
        // Initialize a variable to keep track of the last index where a swap occurred
        int lastSwappedIndex = left;

        // Iterate through the array from the left pointer to the right pointer - 1
        for (int i = left; i < right; i++) {
            // If the current element is greater than the next element, swap them
            if (array[i].compareTo(array[i + 1]) > 0) {
                swap(array, i, i + 1);
                lastSwappedIndex = i;
            }
        }

        // Return the last index where a swap occurred
        return lastSwappedIndex;
    }

    // A helper method to perform a backward pass in the bubble sort algorithm
    private <T extends Comparable<T>> int performBackwardPass(final T[] array, final int left, final int right) {
        // Initialize a variable to keep track of the last index where a swap occurred
        int lastSwappedIndex = right;

        // Iterate through the array from the right pointer to the left pointer + 1
        for (int i = right; i > left; i--) {
            // If the current element is smaller than the previous element, swap them
            if (array[i].compareTo(array[i - 1]) < 0) {
                swap(array, i - 1, i);
                lastSwappedIndex = i;
            }
        }

        // Return the last index where a swap occurred
        return lastSwappedIndex;
    }

    // A helper method to swap two elements in the array
    private <T> void swap(final T[] array, final int i, final int j) {
        // Swap the elements at the given indices
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}