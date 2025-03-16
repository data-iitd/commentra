import java.util.Scanner;

/**
 * FibonacciSearch is a search algorithm that finds the position of a target value in
 * a sorted array using Fibonacci numbers.
 *
 * <p>
 * The time complexity for this search algorithm is O(log n).
 * The space complexity for this search algorithm is O(1).
 * </p>
 *
 * <p>
 * Note: This algorithm requires that the input array be sorted.
 * </p>
 */
public class FibonacciSearch {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Read the key to be searched
        int key = scanner.nextInt();

        // Perform Fibonacci Search
        FibonacciSearch searcher = new FibonacciSearch();
        int index = searcher.find(array, key);

        // Print the result
        System.out.println(index);

        scanner.close();
    }

    /**
     * Finds the index of the specified key in a sorted array using Fibonacci search.
     *
     * @param array The sorted array to search.
     * @param key The element to search for.
     * @param <T> The type of the elements in the array, which must be comparable.
     * @throws IllegalArgumentException if the input array is not sorted or empty, or if the key is null.
     * @return The index of the key if found, otherwise -1.
     */
    public <T extends Comparable<T>> int find(T[] array, T key) {
        if (array.length == 0) {
            throw new IllegalArgumentException("Input array must not be empty.");
        }
        if (!isSorted(array)) {
            throw new IllegalArgumentException("Input array must be sorted.");
        }
        if (key == null) {
            throw new IllegalArgumentException("Key must not be null.");
        }

        int fibMinus1 = 1;
        int fibMinus2 = 0;
        int fibNumber = fibMinus1 + fibMinus2;
        int n = array.length;

        while (fibNumber < n) {
            fibMinus2 = fibMinus1;
            fibMinus1 = fibNumber;
            fibNumber = fibMinus2 + fibMinus1;
        }

        int offset = -1;

        while (fibNumber > 1) {
            int i = Math.min(offset + fibMinus2, n - 1);

            if (array[i].compareTo(key) < 0) {
                fibNumber = fibMinus1;
                fibMinus1 = fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
                offset = i;
            } else if (array[i].compareTo(key) > 0) {
                fibNumber = fibMinus2;
                fibMinus1 = fibMinus1 - fibMinus2;
                fibMinus2 = fibNumber - fibMinus1;
            } else {
                return i;
            }
        }

        if (fibMinus1 == 1 && offset + 1 < n && array[offset + 1].equals(key)) {
            return offset + 1;
        }

        return -1;
    }

    private boolean isSorted(Comparable[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i - 1].compareTo(array[i]) > 0) {
                return false;
            }
        }
        return true;
    }
}
