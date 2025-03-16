import java.util.Scanner;
import java.util.Arrays;

/**
 * Introspective Sort Algorithm Implementation
 *
 * @see <a href="https://en.wikipedia.org/wiki/Introsort">IntroSort Algorithm</a>
 */
public class IntrospectiveSort {

    private static final int INSERTION_SORT_THRESHOLD = 16;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: size of the array
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];

        // Input: array elements
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array
        introspectiveSort(array, 0, array.length - 1, 2 * (int) (Math.log(array.length) / Math.log(2)));

        // Output: sorted array
        for (int num : array) {
            System.out.print(num + " ");
        }

        scanner.close();
    }

    /**
     * Performs introspective sort on the specified subarray.
     *
     * @param array The array to be sorted
     * @param low   The starting index of the subarray
     * @param high  The ending index of the subarray
     * @param depth The current depth of recursion
     */
    private static <T extends Comparable<T>> void introspectiveSort(T[] array, final int low, int high, final int depth) {
        while (high - low > INSERTION_SORT_THRESHOLD) {
            if (depth == 0) {
                heapSort(array, low, high);
                return;
            }
            final int pivotIndex = partition(array, low, high);
            introspectiveSort(array, pivotIndex + 1, high, depth - 1);
            high = pivotIndex - 1;
        }
        insertionSort(array, low, high);
    }

    /**
     * Partitions the array around a pivot.
     *
     * @param array The array to be partitioned
     * @param low   The starting index of the subarray
     * @param high  The ending index of the subarray
     * @param <T>   The type of elements in the array, which must be comparable
     * @return The index of the pivot
     */
    private static <T extends Comparable<T>> int partition(T[] array, final int low, final int high) {
        final T pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (array[j].compareTo(pivot) <= 0) {
                i++;
                swap(array, i, j);
            }
        }
        swap(array, i + 1, high);
        return i + 1;
    }

    /**
     * Sorts a subarray using insertion sort.
     *
     * @param array The array to be sorted
     * @param low   The starting index of the subarray
     * @param high  The ending index of the subarray
     * @param <T>   The type of elements in the array, which must be comparable
     */
    private static <T extends Comparable<T>> void insertionSort(T[] array, final int low, final int high) {
        for (int i = low + 1; i <= high; i++) {
            final T key = array[i];
            int j = i - 1;
            while (j >= low && array[j].compareTo(key) > 0) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }

    /**
     * Sorts a subarray using heapsort.
     *
     * @param array The array to be sorted
     * @param low   The starting index of the subarray
     * @param high  The ending index of the subarray
     * @param <T>   The type of elements in the array, which must be comparable
     */
    private static <T extends Comparable<T>> void heapSort(T[] array, final int low, final int high) {
        final int n = high - low + 1;
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(array, i, n, low);
        }
        for (int i = high; i > low; i--) {
            swap(array, low, i);
            heapify(array, 0, i - low, low);
        }
    }

    /**
     * Maintains the heap property for a subarray.
     *
     * @param array The array to be heapified
     * @param i     The index to be heapified
     * @param n     The size of the heap
     * @param low   The starting index of the subarray
     * @param <T>   The type of elements in the array, which must be comparable
     */
    private static <T extends Comparable<T>> void heapify(T[] array, final int i, final int n, final int low) {
        final int left = 2 * i + 1;
        final int right = 2 * i + 2;
        int largest = i;

        if (left < n && array[low + left].compareTo(array[low + largest]) > 0) {
            largest = left;
        }
        if (right < n && array[low + right].compareTo(array[low + largest]) > 0) {
            largest = right;
        }
        if (largest != i) {
            swap(array, low + i, low + largest);
            heapify(array, largest, n, low);
        }
    }

    /**
     * Swaps two elements in the array.
     */
    private static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
