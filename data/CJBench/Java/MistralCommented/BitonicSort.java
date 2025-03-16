import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;

/**
 * Main class for sorting an array using Bitonic Sort algorithm.
 */
public class Main {

    /**
     * Enum representing the two possible directions for sorting: descending and ascending.
     */
    private enum Direction {
        DESCENDING,
        ASCENDING,
    }

    /**
     * Sorts an array of comparable elements using the Bitonic Sort algorithm.
     *
     * @param <T> The type of elements in the array.
     * @param array The array to be sorted.
     * @return The sorted array.
     */
    public <T extends Comparable<T>> T[] sort(T[] array) {
        if (array.length == 0) {
            // If the array is empty, return it as is.
            return array;
        }

        final int paddedSize = nextPowerOfTwo(array.length);
        T[] paddedArray = Arrays.copyOf(array, paddedSize);
        final T maxValue = max(array);
        Arrays.fill(paddedArray, array.length, paddedSize, maxValue);
        // Pad the array with maxValue to make it a power of 2 size.

        bitonicSort(paddedArray, 0, paddedSize, Direction.ASCENDING);
        return Arrays.copyOf(paddedArray, array.length);
        // Perform the sorting and return the sorted array.
    }

    /**
     * Recursively sorts a portion of the array using the Bitonic Sort algorithm.
     *
     * @param <T> The type of elements in the array.
     * @param array The array to be sorted.
     * @param low The index of the first element in the portion to be sorted.
     * @param cnt The number of elements in the portion to be sorted.
     * @param direction The direction of the sorting: ascending or descending.
     */
    private <T extends Comparable<T>> void bitonicSort(final T[] array, final int low, final int cnt, final Direction direction) {
        if (cnt > 1) {
            final int k = cnt / 2;
            // If the portion has more than one element, recursively sort the left and right halves.

            bitonicSort(array, low, k, Direction.ASCENDING);
            bitonicSort(array, low + k, cnt - k, Direction.DESCENDING);
            // Merge the sorted halves.

            bitonicMerge(array, low, cnt, direction);
        }
    }

    /**
     * Merges two sorted portions of the array using the Bitonic Merge algorithm.
     *
     * @param <T> The type of elements in the array.
     * @param array The array to be merged.
     * @param low The index of the first element in the portion to be merged.
     * @param cnt The number of elements in the portion to be merged.
     * @param direction The direction of the sorting: ascending or descending.
     */
    private <T extends Comparable<T>> void bitonicMerge(T[] array, int low, int cnt, Direction direction) {
        if (cnt > 1) {
            final int k = cnt / 2;
            // If the portion has more than one element, merge the left and right halves.

            final BiPredicate<T, T> areSorted = (direction == Direction.ASCENDING) ?
                    (a, b) -> a.compareTo(b) < 0 :
                    (a, b) -> a.compareTo(b) > 0;
            // Define a comparator based on the sorting direction.

            for (int i = low; i < low + k; i++) {
                if (!areSorted.test(array[i], array[i + k])) {
                    // If two adjacent elements are not in the correct order, swap them.
                    swap(array, i, i + k);
                }
            }
            bitonicMerge(array, low, k, direction);
            // Merge the left half recursively.

            bitonicMerge(array, low + k, cnt - k, direction);
            // Merge the right half recursively.
        }
    }

    /**
     * Calculates the next power of 2 greater than or equal to a given number.
     *
     * @param n The number to find the next power of 2 for.
     * @return The next power of 2 greater than or equal to n.
     */
    private static int nextPowerOfTwo(int n) {
        int count = 0;
        if ((n & (n - 1)) == 0) {
            // If n is already a power of 2, return it.
            return n;
        }
        while (n != 0) {
            n >>= 1;
            count += 1;
        }
        // Calculate the number of bits needed to represent the next power of 2.

        return 1 << count;
        // Return the next power of 2 as a power of 2 raised to the calculated number of bits.
    }

    /**
     * Finds the maximum value in an array of comparable elements.
     *
     * @param <T> The type of elements in the array.
     * @param array The array containing the elements to find the maximum of.
     * @return The maximum value in the array.
     */
    private static <T extends Comparable<T>> T max(final T[] array) {
        return Arrays.stream(array).max(Comparable::compareTo).orElseThrow();
        // Use Java Stream API to find the maximum value in the array.
    }

    /**
     * Swaps two elements in an array.
     *
     * @param <T> The type of elements in the array.
     * @param array The array containing the elements to swap.
     * @param i The index of the first element to swap.
     * @param j The index of the second element to swap.
     */
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        // Swap the elements by temporarily storing one of them and assigning the other to its place.
    }

    /**
     * Main method for testing the sorting functionality.
     *
     * @param args Command line arguments (not used in this implementation).
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Read the number of elements in the array from the standard input.

        Integer[] array = new Integer[n];
        // Allocate an array of integers of the given size.

        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
            // Read each element of the array from the standard input.
        }
        Main sorter = new Main();
        // Instantiate the Main class to use its sorting functionality.

        Integer[] sortedArray = sorter.sort(array);
        // Call the sorting method to sort the array.

        for (int num : sortedArray) {
            System.out.print(num + " ");
            // Print each sorted element to the standard output.
        }
        scanner.close();
        // Close the standard input scanner.
    }
}
