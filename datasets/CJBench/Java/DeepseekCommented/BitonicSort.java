import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;
public class Main {
    // Enum to define sorting directions
    private enum Direction {
        DESCENDING,
        ASCENDING,
    }
    // Method to sort an array using bitonic sort algorithm
    public <T extends Comparable<T>> T[] sort(T[] array) {
        // If the array is empty, return it as is
        if (array.length == 0) {
            return array;
        }
        // Calculate the next power of two for padding the array size
        final int paddedSize = nextPowerOfTwo(array.length);
        // Copy the original array and pad it with the maximum value
        T[] paddedArray = Arrays.copyOf(array, paddedSize);
        final T maxValue = max(array);
        Arrays.fill(paddedArray, array.length, paddedSize, maxValue);
        // Perform bitonic sort on the padded array
        bitonicSort(paddedArray, 0, paddedSize, Direction.ASCENDING);
        // Return the sorted portion of the array
        return Arrays.copyOf(paddedArray, array.length);
    }
    // Recursive method to perform bitonic sort
    private <T extends Comparable<T>> void bitonicSort(final T[] array, final int low, final int cnt, final Direction direction) {
        // Base case: if the count is greater than one, continue sorting
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
    // Method to merge two halves of the array in a bitonic sequence
    private <T extends Comparable<T>> void bitonicMerge(T[] array, int low, int cnt, Direction direction) {
        // Base case: if the count is greater than one, continue merging
        if (cnt > 1) {
            final int k = cnt / 2;
            // Define the predicate for comparing elements based on direction
            final BiPredicate<T, T> areSorted = (direction == Direction.ASCENDING) ? 
                (a, b) -> a.compareTo(b) < 0 : 
                (a, b) -> a.compareTo(b) > 0;
            // Compare and swap elements to ensure the correct order
            for (int i = low; i < low + k; i++) {
                if (!areSorted.test(array[i], array[i + k])) {
                    swap(array, i, i + k);
                }
            }
            // Recursively merge the two halves
            bitonicMerge(array, low, k, direction);
            bitonicMerge(array, low + k, cnt - k, direction);
        }
    }
    // Method to calculate the smallest power of two greater than or equal to n
    private static int nextPowerOfTwo(int n) {
        int count = 0;
        if ((n & (n - 1)) == 0) {
            return n;
        }
        while (n != 0) {
            n >>= 1;
            count += 1;
        }
        return 1 << count;
    }
    // Method to find the maximum element in the array
    private static <T extends Comparable<T>> T max(final T[] array) {
        return Arrays.stream(array).max(Comparable::compareTo).orElseThrow();
    }
    // Method to swap two elements in an array
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    // Main method to read input, sort the array, and print the sorted array
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        Main sorter = new Main();
        Integer[] sortedArray = sorter.sort(array);
        for (int num : sortedArray) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
