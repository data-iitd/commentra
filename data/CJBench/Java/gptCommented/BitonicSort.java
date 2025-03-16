import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;

public class Main {
    // Enum to define sorting direction
    private enum Direction {
        DESCENDING,
        ASCENDING,
    }

    // Method to sort an array using Bitonic Sort
    public <T extends Comparable<T>> T[] sort(T[] array) {
        // Return the original array if it's empty
        if (array.length == 0) {
            return array;
        }
        // Calculate the next power of two for padding the array
        final int paddedSize = nextPowerOfTwo(array.length);
        // Create a padded array to accommodate the Bitonic Sort
        T[] paddedArray = Arrays.copyOf(array, paddedSize);
        // Find the maximum value in the original array
        final T maxValue = max(array);
        // Fill the padded part of the array with the maximum value
        Arrays.fill(paddedArray, array.length, paddedSize, maxValue);
        // Perform Bitonic Sort on the padded array in ascending order
        bitonicSort(paddedArray, 0, paddedSize, Direction.ASCENDING);
        // Return the sorted array, excluding the padded elements
        return Arrays.copyOf(paddedArray, array.length);
    }

    // Recursive method to perform Bitonic Sort
    private <T extends Comparable<T>> void bitonicSort(final T[] array, final int low, final int cnt, final Direction direction) {
        // Base case: if the count is greater than 1, continue sorting
        if (cnt > 1) {
            final int k = cnt / 2;
            // Sort the first half in ascending order
            bitonicSort(array, low, k, Direction.ASCENDING);
            // Sort the second half in descending order
            bitonicSort(array, low + k, cnt - k, Direction.DESCENDING);
            // Merge the two halves
            bitonicMerge(array, low, cnt, direction);
        }
    }

    // Method to merge two sorted halves of the array
    private <T extends Comparable<T>> void bitonicMerge(T[] array, int low, int cnt, Direction direction) {
        // Base case: if the count is greater than 1, continue merging
        if (cnt > 1) {
            final int k = cnt / 2;
            // Define a predicate to check if elements are sorted based on the direction
            final BiPredicate<T, T> areSorted = (direction == Direction.ASCENDING) ? 
                (a, b) -> a.compareTo(b) < 0 : 
                (a, b) -> a.compareTo(b) > 0;
            // Compare and swap elements to ensure they are in the correct order
            for (int i = low; i < low + k; i++) {
                if (!areSorted.test(array[i], array[i + k])) {
                    swap(array, i, i + k);
                }
            }
            // Recursively merge the first and second halves
            bitonicMerge(array, low, k, direction);
            bitonicMerge(array, low + k, cnt - k, direction);
        }
    }

    // Method to find the next power of two greater than or equal to n
    private static int nextPowerOfTwo(int n) {
        int count = 0;
        // If n is already a power of two, return it
        if ((n & (n - 1)) == 0) {
            return n;
        }
        // Calculate the next power of two
        while (n != 0) {
            n >>= 1;
            count += 1;
        }
        return 1 << count;
    }

    // Method to find the maximum element in an array
    private static <T extends Comparable<T>> T max(final T[] array) {
        return Arrays.stream(array).max(Comparable::compareTo).orElseThrow();
    }

    // Method to swap two elements in an array
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Main method to execute the sorting program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements in the array
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        // Read the elements of the array from user input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        // Create an instance of Main to access the sort method
        Main sorter = new Main();
        // Sort the array using Bitonic Sort
        Integer[] sortedArray = sorter.sort(array);
        // Print the sorted array
        for (int num : sortedArray) {
            System.out.print(num + " ");
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
